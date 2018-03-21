<?php

function hampsters_list_page() {
  $output = '';

  $keys = [];
  $rows = [];
  $page_count = 10;

  $total = db_query('SELECT COUNT(*) as count FROM {hamsters}')->fetchField();
  $page_num = pager_default_initialize($total, $page_count);

  $result = db_query_range('SELECT h.id, h.name, h.weight, h.gender, hb.name as hab_name
                      FROM {hamsters} h
                      LEFT JOIN {habitats} hb ON hb.id = h.habitat_id
                      ORDER BY h.id, h.name', ($page_num * $page_count), $page_count);
  foreach ($result as $record) {
    $row = get_object_vars($record);
    $keys = (empty($keys) ? array_keys($row) : $keys);

    $row['weight'] = t('@weight g', ['@weight' => $row['weight']]);
    $row['hab_name'] = (empty($row['hab_name']) ? '<i>Not Found</i>' : $row['hab_name']);
    $row['name'] = l($row['name'], '/hampsters/' . $record->id);

    $link_query = ['destination' => 'hampster'];
    if (!empty($_GET['page'])) {
      $link_query['destination'] .= '?page=' . $_GET['page'];
    }

    $row[] = implode(' - ', [
      l('View', 'hampsters/' . $record->id),
      l('Edit', 'hampsters/' . $record->id . '/edit', ['query' => $link_query]),
      l('Delete', 'hampsters/' . $record->id . '/delete', ['query' => $link_query]),
    ]);

    $rows[] = $row;
  }

  // Readable names for the db column names.
  $key_names = array_map(function($key) { return ucwords(str_ireplace('_', ' ', $key)); }, $keys);
  $key_names[] = 'Actions';

  // Table theming
  $output .= theme('table', [
    'header' => array_map(function($key){ return t($key); }, $key_names),
    'rows' => $rows,
  ]);

  $output .= theme('pager');

  return $output;
}

function hampsters_hampster_title($hampster) {
  return ucwords($hampster->name) . ' the Hampster';
}

function hampsters_hampster_page($hampster) {
  return theme('hampster_info', ['hampster' => $hampster]);
}

function hampsters_oo_list_page($gender = NULL) {
  $output = '';

  $keys = [];
  $rows = [];
  $page_count = 10;

  $query = db_select('hamsters', 'h');
  $query->join('habitats', 'hb', 'hb.id = h.habitat_id');
  $query->fields('h', ['id', 'name', 'weight', 'gender']);
  $query->addField('hb', 'name', 'hab_name');
  if (!empty($gender)) {
    $query->condition('h.gender', $gender);
  }
  $query->orderBy('h.id');
  $query = $query->extend('PagerDefault')->limit($page_count);
  $result = $query->execute();

  foreach ($result as $record) {
    $row = get_object_vars($record);
    $keys = (empty($keys) ? array_keys($row) : $keys);

    $row['weight'] = t('@weight g', ['@weight' => $row['weight']]);
    $row['hab_name'] = (empty($row['hab_name']) ? '<i>Not Found</i>' : $row['hab_name']);
    $row['name'] = l($row['name'], '/hampsters/' . $record->id);

    $rows[] = $row;
  }

  // Readable names for the db column names.
  $key_names = array_map(function($key) { return ucwords(str_ireplace('_', ' ', $key)); }, $keys);

  // Table theming
  $output .= theme('table', [
    'header' => array_map(function($key){ return t($key); }, $key_names),
    'rows' => $rows,
  ]);

  $output .= theme('pager');

  return $output;
}

function hampster_edit_form($form, &$form_state, $hampster = NULL) {
  $form['id'] = [
    '#type' => 'value',
    '#value' => (isset($hampster->id) ? $hampster->id : NULL),
  ];

  $form['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => isset($hampster->name) ? $hampster->name : NULL,
    '#required' => TRUE,
  ];

  $form['gender'] = [
    '#type' => 'radios',
    '#title' => t('Gender'),
    '#options' => ['male' => t('Male'), 'female' => t('Female')],
    '#default_value' => isset($hampster->gender) ? $hampster->gender : NULL,
    '#required' => TRUE,
  ];

  $form['weight'] = [
    '#type' => 'textfield',
    '#title' => t('Weight'),
    '#field_suffix' => 'grams',
    '#default_value' => isset($hampster->weight) ? $hampster->weight : NULL,
    '#size' => 5,
    '#required' => TRUE,
  ];

  $habitats = db_query('SELECT id, name FROM {habitats}')->fetchAllKeyed(0);
  $habitats = ['' => '-- Select a Habitat --'] + $habitats;

  $form['habitat_id'] = [
    '#type' => 'select',
    '#title' => t('Habitat'),
    '#options' => $habitats,
    '#default_value' => isset($hampster->habitat_id) ? $hampster->habitat_id : NULL,
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save Hampster'),
  ];

  return $form;
}

function hampster_edit_form_submit($form, &$form_state) {
  $hampster = $form_state['values'];

  if (!empty($hampster['id'])) {
    // Editing exisitng hampster
    drupal_write_record('hamsters', $hampster, ['id']);
    drupal_set_message(t('Hampster %name updated', ['%name' => $hampster['name']]));
  }
  else {
    // Adding new hampster
    drupal_write_record('hamsters', $hampster);
    drupal_set_message(t('Hampster %name created', ['%name' => $hampster['name']]));
  }

  cache_clear_all('perfdemo:ham:list', 'cache');

  $form_state['redirect'] = 'hampsters/' . $hampster['id'];
}

function hampster_delete_form($form, &$form_state, $hampster) {
  $form['id'] = [
    '#type' => 'value',
    '#value' => $hampster->id,
  ];

  $form['name'] = [
    '#type' => 'value',
    '#value' => $hampster->name,
  ];
  return confirm_form($form, t('Are you sure you want to delete hampster %name?', ['%name' => $hampster->name]), 'hampsters/' . $hampster->id);
}

function hampster_delete_form_submit($form, &$form_state) {
  db_query('DELETE FROM {hamsters} WHERE id = :id', [':id' => $form_state['values']['id']]);
  drupal_set_message(t('Hampster %name deleted', ['%name' => $form_state['values']['name']]));
  $form_state['redirect'] = 'hampsters';
}
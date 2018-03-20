<?php

function hampster_views_default_views() {
  $views = [];

  $view = new view();
  $view->name = 'hampsters';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'hamsters';
  $view->human_name = 'Hampsters';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Hampsters';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Hampster: Habitat ID */
  $handler->display->display_options['relationships']['habitat_id']['id'] = 'habitat_id';
  $handler->display->display_options['relationships']['habitat_id']['table'] = 'hamsters';
  $handler->display->display_options['relationships']['habitat_id']['field'] = 'habitat_id';
  /* Field: Hampster: ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'hamsters';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Hampster: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'hamsters';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'hampsters/[id]';
  /* Field: Hampster: Gender */
  $handler->display->display_options['fields']['gender']['id'] = 'gender';
  $handler->display->display_options['fields']['gender']['table'] = 'hamsters';
  $handler->display->display_options['fields']['gender']['field'] = 'gender';
  /* Field: Hampster: Weight */
  $handler->display->display_options['fields']['weight']['id'] = 'weight';
  $handler->display->display_options['fields']['weight']['table'] = 'hamsters';
  $handler->display->display_options['fields']['weight']['field'] = 'weight';
  $handler->display->display_options['fields']['weight']['suffix'] = ' g';
  /* Field: Hampster: Habitat ID */
  $handler->display->display_options['fields']['habitat_id']['id'] = 'habitat_id';
  $handler->display->display_options['fields']['habitat_id']['table'] = 'hamsters';
  $handler->display->display_options['fields']['habitat_id']['field'] = 'habitat_id';
  /* Field: Hampster Habitat: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'habitats';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'habitat_id';
  $handler->display->display_options['fields']['name_1']['label'] = 'Habitat Name';
  /* Sort criterion: Hampster: Gender */
  $handler->display->display_options['sorts']['gender']['id'] = 'gender';
  $handler->display->display_options['sorts']['gender']['table'] = 'hamsters';
  $handler->display->display_options['sorts']['gender']['field'] = 'gender';
  $handler->display->display_options['sorts']['gender']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['gender']['expose']['label'] = 'Gender';
  /* Sort criterion: Hampster: ID */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'hamsters';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['id']['expose']['label'] = 'ID';
  /* Sort criterion: Hampster: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'hamsters';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Name';
  /* Sort criterion: Hampster: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'hamsters';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['weight']['expose']['label'] = 'Weight';
  /* Filter criterion: Hampster: ID */
  $handler->display->display_options['filters']['id']['id'] = 'id';
  $handler->display->display_options['filters']['id']['table'] = 'hamsters';
  $handler->display->display_options['filters']['id']['field'] = 'id';
  $handler->display->display_options['filters']['id']['group'] = 1;
  $handler->display->display_options['filters']['id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['id']['expose']['operator_id'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['id']['expose']['operator'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['identifier'] = 'id';
  $handler->display->display_options['filters']['id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Hampster: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'hamsters';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Hampster: Gender */
  $handler->display->display_options['filters']['gender']['id'] = 'gender';
  $handler->display->display_options['filters']['gender']['table'] = 'hamsters';
  $handler->display->display_options['filters']['gender']['field'] = 'gender';
  $handler->display->display_options['filters']['gender']['group'] = 1;
  $handler->display->display_options['filters']['gender']['exposed'] = TRUE;
  $handler->display->display_options['filters']['gender']['expose']['operator_id'] = 'gender_op';
  $handler->display->display_options['filters']['gender']['expose']['label'] = 'Gender';
  $handler->display->display_options['filters']['gender']['expose']['operator'] = 'gender_op';
  $handler->display->display_options['filters']['gender']['expose']['identifier'] = 'gender';
  $handler->display->display_options['filters']['gender']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Hampster: Weight */
  $handler->display->display_options['filters']['weight']['id'] = 'weight';
  $handler->display->display_options['filters']['weight']['table'] = 'hamsters';
  $handler->display->display_options['filters']['weight']['field'] = 'weight';
  $handler->display->display_options['filters']['weight']['group'] = 1;
  $handler->display->display_options['filters']['weight']['exposed'] = TRUE;
  $handler->display->display_options['filters']['weight']['expose']['operator_id'] = 'weight_op';
  $handler->display->display_options['filters']['weight']['expose']['label'] = 'Weight';
  $handler->display->display_options['filters']['weight']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['weight']['expose']['operator'] = 'weight_op';
  $handler->display->display_options['filters']['weight']['expose']['identifier'] = 'weight';
  $handler->display->display_options['filters']['weight']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Hampster Habitat: Name */
  $handler->display->display_options['filters']['name_1']['id'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['table'] = 'habitats';
  $handler->display->display_options['filters']['name_1']['field'] = 'name';
  $handler->display->display_options['filters']['name_1']['relationship'] = 'habitat_id';
  $handler->display->display_options['filters']['name_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['name_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_1']['expose']['operator_id'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['label'] = 'Habitat Name';
  $handler->display->display_options['filters']['name_1']['expose']['operator'] = 'name_1_op';
  $handler->display->display_options['filters']['name_1']['expose']['identifier'] = 'name_1';
  $handler->display->display_options['filters']['name_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'hampsters-view';

  $views[$view->name] = $view;

  return $views;
}
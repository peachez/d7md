<?php

function hampster_views_data() {
  $data = [];

  $data['habitats'] = [
    'table' => [
      'group' => t('Hampster Habitat'),
      'title' => t('Hamster Habitat Information'),
      'help' => t('List information about hampster cages.'),
      // 'base' => [
      //   'field' => 'id',
      //   'title' => t('Hampsters'),
      //   'help' => t('Information about hampsters.'),
      // ],
    ],
    'id' => [
      'title' => t('ID'),
      'help' => t('The ID of the hampster habitat.'),
      'field' => [
        'handler' => 'views_handler_field_numeric',
      ],
      'filter' => [
        'handler' => 'views_handler_filter_numeric',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
    'name' => [
      'title' => t('Name'),
      'help' => t('The name of the hampster habitat.'),
      'field' => [
        'handler' => 'views_handler_field',
      ],
      'filter' => [
        'handler' => 'views_handler_filter_string',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
  ];

  $data['hamsters'] = [
    'table' => [
      'group' => t('Hampster'),
      'title' => t('Hamster Information'),
      'help' => t('List information about hampsters.'),
      'base' => [
        'field' => 'id',
        'title' => t('Hampsters'),
        'help' => t('Information about hampsters.'),
      ],
    ],
    'id' => [
      'title' => t('ID'),
      'help' => t('The ID of the hampster.'),
      'field' => [
        'handler' => 'views_handler_field_numeric',
      ],
      'filter' => [
        'handler' => 'views_handler_filter_numeric',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
    'name' => [
      'title' => t('Name'),
      'help' => t('The name of the hampster.'),
      'field' => [
        'handler' => 'views_handler_field',
      ],
      'filter' => [
        'handler' => 'views_handler_filter_string',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
    'weight' => [
      'title' => t('Weight'),
      'help' => t('The weight of the hampster.'),
      'field' => [
        'handler' => 'views_handler_field_numeric',
      ],
      'filter' => [
        'handler' => 'views_handler_filter_numeric',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
    'gender' => [
      'title' => t('Gender'),
      'help' => t('The gender of the hampster.'),
      'field' => [
        'handler' => 'views_handler_field',
      ],
      'filter' => [
        'handler' => 'views_handler_filter_in_operator',
        'options callback' => 'hampster_views_gender_options',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
    'habitat_id' => [
      'title' => t('Habitat ID'),
      'help' => t('The Habitat ID of the hampster.'),
      'field' => [
        'handler' => 'views_handler_field',
      ],
      'relationship' => [
        'label' => t('Habitat'),
        'base' => 'habitats',
        'base field' => 'id',
      ],
    ],
  ];

  return $data;
}

function hampster_views_gender_options() {
  return [
    'male' => t('Male'),
    'female' => t('Female'),
  ];
}
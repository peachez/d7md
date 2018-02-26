<?php

function node_metadata_page($node) {
  // $node = node_load($nid);

  $format_date = function($unix) { return date('m/d/Y g:ia', $unix); };

  $theme_info = function($prop_name, $node, $format_value = NULL) {
    $labels = [
      'name' => 'Author',
      'changed' => 'Updated',
      'comment_count' => 'Comment Count',
    ];

    $label = (isset($labels[$prop_name]) ? $labels[$prop_name] : $prop_name);

    $value = (is_callable($format_value)) ? $format_value($node->{$prop_name}) : $node->{$prop_name};

    return '<label>' . ucwords($label) . ': </label>' . $value . '</div>';
  };

  $output = '';

  $output .= '<div>';
  $output .= $theme_info('name', $node); //'<label>Author: </label>' . $node->name . '</div>';
  $output .= $theme_info('created', $node, $format_date);
  $output .= $theme_info('changed', $node, $format_date);
  $output .= $theme_info('comment_count', $node);
  $output .= '</div>';


  return $output; //t('Node ID is @nid', ['@nid' => $nid]);
}
<?php
/**
 * @file
 * Internationalization (i18n) hooks
 */


/**
 * Implements hook i18n_object_info()
 */
function i18n_node_i18n_object_info() {
  $info['node_type'] = array(
    'title' => t('Node type'),
    'key' => 'type',
    'placeholders' => array(
    	'%node_type' => 'type',
    ),
    'edit path' => 'admin/structure/types/manage/%node_type',
    'translate path' => 'admin/structure/types/manage/%node_type/translate',
    'string translation' => array(
      'textgroup' => 'node',
      'type' => 'type',
      'properties' => array(
        'name' => t('Name'),
        'title_label' => t('Title label'),
        'description' => t('Description'),
        'help' => t('Help text'),
      ),
      'translate path' => 'admin/structure/types/manage/%node_type/translate/%language',
    )
  );
  return $info;
}

/**
 * Implements hook_i18n_string_info()
 */
function i18n_node_i18n_string_info() {
  $groups['node'] = array(
    'title' => t('Node types'),
    'description' => t('Content type names, descriptions, help texts.'),
    //'format' => TRUE, // This group has strings with format (block body)
    'list' => TRUE, // This group can list all strings
  );
  return $groups;
}
/**
 * Implements hook_i18n_string_list()
 */
function i18n_node_i18n_string_list($group) {
  if ($group == 'node' || $group = 'all') {
    $strings = array();
    foreach (node_type_get_types() as $type) {
      $strings['node']['type'][$type->type] = array(
        'name' => $type->name,
        'title_label' => $type->title_label,
        'description' => $type->description,
        'help' => $type->help,
      );
    }
    return $strings;
  }
}
<?php
/**
 * @file
 * vies_employee.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vies_employee_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function vies_employee_node_info() {
  $items = array(
    'vies_employee' => array(
      'name' => t('Employee'),
      'base' => 'node_content',
      'description' => t('<em>Employee</em> is used to describe the employees on the school.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

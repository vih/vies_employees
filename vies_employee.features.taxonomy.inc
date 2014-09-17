<?php
/**
 * @file
 * vies_employee.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function vies_employee_taxonomy_default_vocabularies() {
  return array(
    'vies_employee_group' => array(
      'name' => 'Employee group',
      'machine_name' => 'vies_employee_group',
      'description' => 'Used to categorize the employees.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}

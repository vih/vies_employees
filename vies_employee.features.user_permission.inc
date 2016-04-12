<?php
/**
 * @file
 * vies_employee.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function vies_employee_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access draggableviews'.
  $permissions['access draggableviews'] = array(
    'name' => 'access draggableviews',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'draggableviews',
  );

  return $permissions;
}

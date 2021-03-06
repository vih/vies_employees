<?php

/**
 * @file
 *  Migrations for vies_employee.
 */

class VIESEmployeeNode extends Migration {

  public function __construct(array $arguments = array()) {
    parent::__construct($arguments);
    $this->description = t('Import employee nodes.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'vies_employee') . '/import/employees.csv', $this->csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('vies_employee');

    $this->addFieldMapping('uid', 'uid')->defaultValue(1);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')
      ->defaultValue('panopoly_wysiwyg_text');
    $this->addFieldMapping('field_vies_favorite_quote', 'quote');
    $this->addFieldMapping('field_vies_favorite_athlete', 'athlete');
    $this->addFieldMapping('field_vies_funny_addons', 'addons');
    $this->addFieldMapping('field_vies_email', 'email');
    $this->addFieldMapping('field_vies_employee_category', 'category');

    // Featured image
    $this->addFieldMapping('field_featured_image', 'featured_image');
    $this->addFieldMapping('field_featured_image:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_featured_image:source_dir')
      ->defaultValue(drupal_get_path('module', 'vies_employee') . '/import/images');
  }

  function csvcolumns() {
    $columns[0] = array('id', 'Id');
    $columns[1] = array('title', 'Title');
    $columns[2] = array('body', 'Body');
    $columns[3] = array('quote', 'Quote');
    $columns[4] = array('athlete', 'Athlete');
    $columns[5] = array('addons', 'Addons');
    $columns[6] = array('email', 'Email');
    $columns[7] = array('category', 'Category');
    $columns[8] = array('featured_image', 'Featured Image');
    return $columns;
  }
}

<?php


/**
 * Deploy fonction used in hook_install
 */
function _skeleton_deploy($type) {
  $filepath = drupal_get_path('profile', 'skeleton') . '/deployment';
  switch($type){
    case "blocks":
      $query = db_insert('block')->fields(array(
        'module', 
        'delta', 
        'theme', 
        'status', 
        'weight', 
        'region', 
        'visibility', 
        'pages', 
        'title', 
        'cache',
      ));
      $files = drupal_system_listing('/\.inc$/', $filepath . "/blocks", 'name', 0);
      foreach($files as $file) {
        include_once $filepath . "/blocks/" . $file->filename;
        if(!empty($block)) {
          $query->values($block);
        }
        $query->execute();
      }
    break;

    case "menus" :
    // Delegate import menus to menutastic
    if(module_exists('menutastic')) {
      $files = drupal_system_listing('/\.inc$/', $filepath . "/menus", 'name', 0);
      foreach($files as $file) {
        include_once $filepath . "/menus/" . $file->filename;
        menutastic_menu_import($menu);
      }
    }
    break;

    case "nodes" :
      $files = drupal_system_listing('/\.inc$/', $filepath . "/nodes", 'name', 0);
      foreach($files as $file) {
        include_once $filepath . "/nodes/" . $file->filename;
        if(!empty($node)) {
          node_save($node);
        }
      }
    break;
  }
}
<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function skeleton_ctools_plugin_api($module, $api) {
  if ($module == 'page_manager' && $api == 'pages_default') {
    return array('version' => 1);
  }
}

/**
 * Implementation of hook_default_page_manager_pages().
 */
function skeleton_default_page_manager_pages() {
  $pages = array();
  $path = drupal_get_path('profile', 'skeleton') . '/deployment/pages';
  $files = drupal_system_listing('/\.inc$/', $path, 'name', 0);

  foreach($files as $file) {
    include_once $path . "/" . $file->filename;
    if(!empty($page)) {
      $pages[$page->name] = $page;
      unset($page);
    }
  }
  return $pages;
}

/**
 * Implementation of hook_views_api().
 */
function skeleton_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implementation of hook_views_default_views().
 */
function skeleton_views_default_views() {
  $views = array();
  $path = drupal_get_path('profile', 'skeleton') . '/deployment/views';
  $files = drupal_system_listing('/\.inc$/', $path, 'name', 0);

  foreach ($files as $file) {
    include_once $path . "/" . $file->filename;
    if(!empty($view)) {
      $views[$view->name] = $view;
      unset($view);
    }
  }
  return $views;
}
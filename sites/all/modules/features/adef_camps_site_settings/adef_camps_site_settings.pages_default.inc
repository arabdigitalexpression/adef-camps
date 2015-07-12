<?php
/**
 * @file
 * adef_camps_site_settings.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function adef_camps_site_settings_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Participant Main',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'participant-profile-home',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'participant' => 'participant',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'camps_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2a0a5097-52ea-4490-8215-4a9a3332b2e1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fd21180c-62b2-4bed-95f2-5378f8584ca7';
  $pane->panel = 'left';
  $pane->type = 'views';
  $pane->subtype = 'content_blocks';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_participant_infocard',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fd21180c-62b2-4bed-95f2-5378f8584ca7';
  $display->content['new-fd21180c-62b2-4bed-95f2-5378f8584ca7'] = $pane;
  $display->panels['left'][0] = 'new-fd21180c-62b2-4bed-95f2-5378f8584ca7';
  $pane = new stdClass();
  $pane->pid = 'new-d4416790-fb68-4746-adc7-0e23a2fc2691';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'content_blocks';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_participant_attendance',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd4416790-fb68-4746-adc7-0e23a2fc2691';
  $display->content['new-d4416790-fb68-4746-adc7-0e23a2fc2691'] = $pane;
  $display->panels['right'][0] = 'new-d4416790-fb68-4746-adc7-0e23a2fc2691';
  $pane = new stdClass();
  $pane->pid = 'new-d24fcdc9-df09-4e28-8914-5acc878b969f';
  $pane->panel = 'top';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_profile_picture';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'profile_header',
      'image_link' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'profile-header-image',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd24fcdc9-df09-4e28-8914-5acc878b969f';
  $display->content['new-d24fcdc9-df09-4e28-8914-5acc878b969f'] = $pane;
  $display->panels['top'][0] = 'new-d24fcdc9-df09-4e28-8914-5acc878b969f';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function adef_camps_site_settings_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_homepage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Main',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'camps_twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fea5ad3b-3e84-470e-a064-9f7995c81567';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cee17761-6119-480f-9e9c-2bee59e3149f';
  $pane->panel = 'first';
  $pane->type = 'views';
  $pane->subtype = 'content_blocks';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_trainer_schedule',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'cee17761-6119-480f-9e9c-2bee59e3149f';
  $display->content['new-cee17761-6119-480f-9e9c-2bee59e3149f'] = $pane;
  $display->panels['first'][0] = 'new-cee17761-6119-480f-9e9c-2bee59e3149f';
  $pane = new stdClass();
  $pane->pid = 'new-dedbc6ad-7728-47ee-95e6-7b4d96b1e9aa';
  $pane->panel = 'last';
  $pane->type = 'views';
  $pane->subtype = 'content_blocks';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_trainer_participants',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'dedbc6ad-7728-47ee-95e6-7b4d96b1e9aa';
  $display->content['new-dedbc6ad-7728-47ee-95e6-7b4d96b1e9aa'] = $pane;
  $display->panels['last'][0] = 'new-dedbc6ad-7728-47ee-95e6-7b4d96b1e9aa';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-cee17761-6119-480f-9e9c-2bee59e3149f';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['homepage'] = $page;

  return $pages;

}

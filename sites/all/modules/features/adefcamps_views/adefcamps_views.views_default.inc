<?php
/**
 * @file
 * adefcamps_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function adefcamps_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'content_blocks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content Blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Zamakan */
  $handler = $view->new_display('block', 'Zamakan', 'block_sessions');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'clearfix';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'session id-[nid_1] w-[nid] tc-[field_date_time_1][field_date_time] zkid-[nid_2] color-[field_color]';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_target_id']['id'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['table'] = 'field_data_field_session';
  $handler->display->display_options['relationships']['field_session_target_id']['field'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['label'] = 'Session';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_workshop_target_id']['id'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['table'] = 'field_data_field_workshop';
  $handler->display->display_options['relationships']['field_workshop_target_id']['field'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['label'] = 'Workshop';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_participants_target_id']['id'] = 'field_participants_target_id';
  $handler->display->display_options['relationships']['field_participants_target_id']['table'] = 'field_data_field_participants';
  $handler->display->display_options['relationships']['field_participants_target_id']['field'] = 'field_participants_target_id';
  $handler->display->display_options['relationships']['field_participants_target_id']['label'] = 'Participant';
  /* Relationship: Content: مكان (field_location) */
  $handler->display->display_options['relationships']['field_location_tid']['id'] = 'field_location_tid';
  $handler->display->display_options['relationships']['field_location_tid']['table'] = 'field_data_field_location';
  $handler->display->display_options['relationships']['field_location_tid']['field'] = 'field_location_tid';
  $handler->display->display_options['relationships']['field_location_tid']['label'] = 'Location';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'track';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'fields' => 'fields',
    'locations' => 0,
    'location_description' => 0,
    'educational_goals' => 0,
    'participant_groups' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: زمان */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['label'] = '';
  $handler->display->display_options['fields']['field_date_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'time_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: زمان */
  $handler->display->display_options['fields']['field_date_time_1']['id'] = 'field_date_time_1';
  $handler->display->display_options['fields']['field_date_time_1']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time_1']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_time_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_time_1']['settings'] = array(
    'format_type' => 'short_date_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: location */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_location_tid';
  $handler->display->display_options['fields']['name']['ui_name'] = 'location';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: workshop-id */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'workshop-id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: session-id */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['fields']['nid_1']['ui_name'] = 'session-id';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Taxonomy term: اللون */
  $handler->display->display_options['fields']['field_color_1']['id'] = 'field_color_1';
  $handler->display->display_options['fields']['field_color_1']['table'] = 'field_data_field_color';
  $handler->display->display_options['fields']['field_color_1']['field'] = 'field_color';
  $handler->display->display_options['fields']['field_color_1']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_color_1']['label'] = '';
  $handler->display->display_options['fields']['field_color_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_color_1']['settings'] = array(
    'width' => '16',
    'height' => '16',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: workshop-max */
  $handler->display->display_options['fields']['field_max_participants']['id'] = 'field_max_participants';
  $handler->display->display_options['fields']['field_max_participants']['table'] = 'field_data_field_max_participants';
  $handler->display->display_options['fields']['field_max_participants']['field'] = 'field_max_participants';
  $handler->display->display_options['fields']['field_max_participants']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['fields']['field_max_participants']['ui_name'] = 'workshop-max';
  $handler->display->display_options['fields']['field_max_participants']['label'] = '';
  $handler->display->display_options['fields']['field_max_participants']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_max_participants']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_max_participants']['empty'] = '0';
  $handler->display->display_options['fields']['field_max_participants']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_max_participants']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_max_participants']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_max_participants']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: timespace-id */
  $handler->display->display_options['fields']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['fields']['nid_2']['table'] = 'node';
  $handler->display->display_options['fields']['nid_2']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_2']['ui_name'] = 'timespace-id';
  $handler->display->display_options['fields']['nid_2']['label'] = '';
  $handler->display->display_options['fields']['nid_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_2']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: اللون */
  $handler->display->display_options['fields']['field_color']['id'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['table'] = 'field_data_field_color';
  $handler->display->display_options['fields']['field_color']['field'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_color']['label'] = '';
  $handler->display->display_options['fields']['field_color']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_color']['type'] = 'colorfield_raw_rgb';
  $handler->display->display_options['fields']['field_color']['settings'] = array(
    'display_hash' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="slots"></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'tooltip';
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  /* Field: Content: مدربين */
  $handler->display->display_options['fields']['field_trainers']['id'] = 'field_trainers';
  $handler->display->display_options['fields']['field_trainers']['table'] = 'field_data_field_trainers';
  $handler->display->display_options['fields']['field_trainers']['field'] = 'field_trainers';
  $handler->display->display_options['fields']['field_trainers']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['fields']['field_trainers']['label'] = '';
  $handler->display->display_options['fields']['field_trainers']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_trainers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trainers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_trainers']['delta_offset'] = '0';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['text'] = '[body]<br/>[name_1]<br/>[field_trainers]';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['element_wrapper_class'] = 'tooltip';
  /* Field: Content: مدة */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['fields']['field_duration']['label'] = '';
  $handler->display->display_options['fields']['field_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_duration']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_location_tid';
  /* Sort criterion: Content: زمان (field_date_time) */
  $handler->display->display_options['sorts']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['sorts']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: زمان (field_date_time) */
  $handler->display->display_options['arguments']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['arguments']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['arguments']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['arguments']['field_date_time_value']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_date_time_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_date_time_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_date_time_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_date_time_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_date_time_value']['granularity'] = 'day';
  $handler->display->display_options['arguments']['field_date_time_value']['granularity_reset'] = 0;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_participants_target_id';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'timespace' => 'timespace',
  );

  /* Display: Trainers */
  $handler = $view->new_display('block', 'Trainers', 'block_trainers');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_target_id']['id'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['table'] = 'field_data_field_session';
  $handler->display->display_options['relationships']['field_session_target_id']['field'] = 'field_session_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_workshop_target_id']['id'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['table'] = 'field_data_field_workshop';
  $handler->display->display_options['relationships']['field_workshop_target_id']['field'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: مدربين */
  $handler->display->display_options['fields']['field_trainers']['id'] = 'field_trainers';
  $handler->display->display_options['fields']['field_trainers']['table'] = 'field_data_field_trainers';
  $handler->display->display_options['fields']['field_trainers']['field'] = 'field_trainers';
  $handler->display->display_options['fields']['field_trainers']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['fields']['field_trainers']['label'] = '';
  $handler->display->display_options['fields']['field_trainers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trainers']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_trainers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_trainers']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_trainers']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';

  /* Display: Schedule */
  $handler = $view->new_display('page', 'Schedule', 'page_schedule');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'الجدول اليومي';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'schedule';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_location',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'session id-[nid_1] w-[nid] d-[field_duration] daycode-[field_date_time_1] start-[field_date_time]';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: مكان (field_location) */
  $handler->display->display_options['relationships']['field_location_tid']['id'] = 'field_location_tid';
  $handler->display->display_options['relationships']['field_location_tid']['table'] = 'field_data_field_location';
  $handler->display->display_options['relationships']['field_location_tid']['field'] = 'field_location_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_target_id']['id'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['table'] = 'field_data_field_session';
  $handler->display->display_options['relationships']['field_session_target_id']['field'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['label'] = 'Session';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_workshop_target_id']['id'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['table'] = 'field_data_field_workshop';
  $handler->display->display_options['relationships']['field_workshop_target_id']['field'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['label'] = 'Workshop';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'fields' => 'fields',
    'locations' => 0,
    'location_description' => 0,
    'educational_goals' => 0,
    'participant_groups' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: زمان */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['label'] = '';
  $handler->display->display_options['fields']['field_date_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'time_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: مكان */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[field_date_time]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: جلسة */
  $handler->display->display_options['fields']['field_session']['id'] = 'field_session';
  $handler->display->display_options['fields']['field_session']['table'] = 'field_data_field_session';
  $handler->display->display_options['fields']['field_session']['field'] = 'field_session';
  $handler->display->display_options['fields']['field_session']['label'] = '';
  $handler->display->display_options['fields']['field_session']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_session']['settings'] = array(
    'link' => 0,
  );
  /* Field: Taxonomy term: اللون */
  $handler->display->display_options['fields']['field_color']['id'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['table'] = 'field_data_field_color';
  $handler->display->display_options['fields']['field_color']['field'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_color']['label'] = '';
  $handler->display->display_options['fields']['field_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_color']['settings'] = array(
    'width' => '16',
    'height' => '16',
  );
  /* Field: Content: مدة */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['fields']['field_duration']['label'] = '';
  $handler->display->display_options['fields']['field_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_duration']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_duration']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: زمان */
  $handler->display->display_options['fields']['field_date_time_1']['id'] = 'field_date_time_1';
  $handler->display->display_options['fields']['field_date_time_1']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time_1']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_time_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_time_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_time_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_time_1']['settings'] = array(
    'format_type' => 'day_code',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Term ID */
  $handler->display->display_options['sorts']['tid']['id'] = 'tid';
  $handler->display->display_options['sorts']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['tid']['field'] = 'tid';
  $handler->display->display_options['sorts']['tid']['relationship'] = 'field_location_tid';
  /* Sort criterion: Content: زمان (field_date_time) */
  $handler->display->display_options['sorts']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['sorts']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: زمان (field_date_time) */
  $handler->display->display_options['arguments']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['arguments']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['arguments']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['arguments']['field_date_time_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_date_time_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_date_time_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_date_time_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_date_time_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_date_time_value']['granularity'] = 'day';
  $handler->display->display_options['arguments']['field_date_time_value']['use_fromto'] = 'no';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'timespace' => 'timespace',
  );
  $handler->display->display_options['path'] = 'daily';

  /* Display: Bulk Admin */
  $handler = $view->new_display('page', 'Bulk Admin', 'page_admin_vbo');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '25, 50, 100, 200';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'nothing' => 'nothing',
    'field_tech_field' => 'nothing',
    'field_number_sessions' => 'nothing',
    'field_trainers' => 'nothing',
    'created' => 'created',
    'changed' => 'changed',
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
    'field_date_time' => 'field_date_time',
    'field_badge_term' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '<br/>',
      'empty_column' => 0,
    ),
    'field_tech_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_number_sessions' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trainers' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_badge_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::adef_camps_create_session_for_workshop' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Info';
  /* Field: Content: المجال */
  $handler->display->display_options['fields']['field_tech_field']['id'] = 'field_tech_field';
  $handler->display->display_options['fields']['field_tech_field']['table'] = 'field_data_field_tech_field';
  $handler->display->display_options['fields']['field_tech_field']['field'] = 'field_tech_field';
  $handler->display->display_options['fields']['field_tech_field']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: عدد الجلسات */
  $handler->display->display_options['fields']['field_number_sessions']['id'] = 'field_number_sessions';
  $handler->display->display_options['fields']['field_number_sessions']['table'] = 'field_data_field_number_sessions';
  $handler->display->display_options['fields']['field_number_sessions']['field'] = 'field_number_sessions';
  $handler->display->display_options['fields']['field_number_sessions']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: مدربين */
  $handler->display->display_options['fields']['field_trainers']['id'] = 'field_trainers';
  $handler->display->display_options['fields']['field_trainers']['table'] = 'field_data_field_trainers';
  $handler->display->display_options['fields']['field_trainers']['field'] = 'field_trainers';
  $handler->display->display_options['fields']['field_trainers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_trainers']['delta_offset'] = '0';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: زمان */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['label'] = 'وقت';
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'time_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: المجال (field_tech_field) */
  $handler->display->display_options['filters']['field_tech_field_tid']['id'] = 'field_tech_field_tid';
  $handler->display->display_options['filters']['field_tech_field_tid']['table'] = 'field_data_field_tech_field';
  $handler->display->display_options['filters']['field_tech_field_tid']['field'] = 'field_tech_field_tid';
  $handler->display->display_options['filters']['field_tech_field_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tech_field_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tech_field_tid']['expose']['operator_id'] = 'field_tech_field_tid_op';
  $handler->display->display_options['filters']['field_tech_field_tid']['expose']['label'] = 'المجال';
  $handler->display->display_options['filters']['field_tech_field_tid']['expose']['operator'] = 'field_tech_field_tid_op';
  $handler->display->display_options['filters']['field_tech_field_tid']['expose']['identifier'] = 'field_tech_field_tid';
  $handler->display->display_options['filters']['field_tech_field_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_tech_field_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tech_field_tid']['vocabulary'] = 'fields';
  /* Filter criterion: Content: زمان (field_date_time) */
  $handler->display->display_options['filters']['field_date_time_value_1']['id'] = 'field_date_time_value_1';
  $handler->display->display_options['filters']['field_date_time_value_1']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['filters']['field_date_time_value_1']['field'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_date_time_value_1']['group'] = 2;
  /* Filter criterion: Content: زمان (field_date_time) */
  $handler->display->display_options['filters']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['filters']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['group'] = 2;
  $handler->display->display_options['filters']['field_date_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator_id'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'زمان (field_date_time)';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['identifier'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_date_time_value']['group_info']['label'] = 'زمان (field_date_time)';
  $handler->display->display_options['filters']['field_date_time_value']['group_info']['identifier'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_date_time_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_time_value']['default_date'] = 'today';
  $handler->display->display_options['path'] = 'admin/content/bulk';

  /* Display: Participants */
  $handler = $view->new_display('page', 'Participants', 'page_participants');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'المشاركون';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'grid clearfix';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: صورة */
  $handler->display->display_options['fields']['field_profile_picture']['id'] = 'field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['table'] = 'field_data_field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['field'] = 'field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_picture']['settings'] = array(
    'image_style' => 'profile_thumb_large',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: البلد */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = '';
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = FALSE;
  /* Field: Content: تاريخ الميلاد */
  $handler->display->display_options['fields']['field_birthdate']['id'] = 'field_birthdate';
  $handler->display->display_options['fields']['field_birthdate']['table'] = 'field_data_field_birthdate';
  $handler->display->display_options['fields']['field_birthdate']['field'] = 'field_birthdate';
  $handler->display->display_options['fields']['field_birthdate']['label'] = 'السن';
  $handler->display->display_options['fields']['field_birthdate']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_birthdate']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_birthdate']['type'] = 'birthdays_age';
  $handler->display->display_options['fields']['field_birthdate']['settings'] = array(
    'dateformat' => 'Y/m/d',
  );
  /* Field: Content: المجموعة */
  $handler->display->display_options['fields']['field_group']['id'] = 'field_group';
  $handler->display->display_options['fields']['field_group']['table'] = 'field_data_field_group';
  $handler->display->display_options['fields']['field_group']['field'] = 'field_group';
  $handler->display->display_options['fields']['field_group']['label'] = '';
  $handler->display->display_options['fields']['field_group']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_group']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_group']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'الاسم';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'participant' => 'participant',
  );
  $handler->display->display_options['path'] = 'participants';

  /* Display: Workshops */
  $handler = $view->new_display('page', 'Workshops', 'page_workshops');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'الورش';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 50, 100';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_max_participants' => 'field_max_participants',
    'field_edu_goals' => 'field_edu_goals',
    'field_tech_field' => 'field_tech_field',
    'field_number_sessions' => 'field_number_sessions',
    'field_trainers' => 'field_trainers',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_max_participants' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_edu_goals' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tech_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_number_sessions' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trainers' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: اقصى عدد للمشاركين */
  $handler->display->display_options['fields']['field_max_participants']['id'] = 'field_max_participants';
  $handler->display->display_options['fields']['field_max_participants']['table'] = 'field_data_field_max_participants';
  $handler->display->display_options['fields']['field_max_participants']['field'] = 'field_max_participants';
  $handler->display->display_options['fields']['field_max_participants']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_max_participants']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: الاهداف التربوية */
  $handler->display->display_options['fields']['field_edu_goals']['id'] = 'field_edu_goals';
  $handler->display->display_options['fields']['field_edu_goals']['table'] = 'field_data_field_edu_goals';
  $handler->display->display_options['fields']['field_edu_goals']['field'] = 'field_edu_goals';
  $handler->display->display_options['fields']['field_edu_goals']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_edu_goals']['delta_offset'] = '0';
  /* Field: Content: المجال */
  $handler->display->display_options['fields']['field_tech_field']['id'] = 'field_tech_field';
  $handler->display->display_options['fields']['field_tech_field']['table'] = 'field_data_field_tech_field';
  $handler->display->display_options['fields']['field_tech_field']['field'] = 'field_tech_field';
  $handler->display->display_options['fields']['field_tech_field']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: عدد الجلسات */
  $handler->display->display_options['fields']['field_number_sessions']['id'] = 'field_number_sessions';
  $handler->display->display_options['fields']['field_number_sessions']['table'] = 'field_data_field_number_sessions';
  $handler->display->display_options['fields']['field_number_sessions']['field'] = 'field_number_sessions';
  $handler->display->display_options['fields']['field_number_sessions']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_number_sessions']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: مدربين */
  $handler->display->display_options['fields']['field_trainers']['id'] = 'field_trainers';
  $handler->display->display_options['fields']['field_trainers']['table'] = 'field_data_field_trainers';
  $handler->display->display_options['fields']['field_trainers']['field'] = 'field_trainers';
  $handler->display->display_options['fields']['field_trainers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_trainers']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'workshop' => 'workshop',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['path'] = 'workshops';

  /* Display: EVA Field */
  $handler = $view->new_display('entity_view', 'EVA Field', 'entity_view_workshop_sessions');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'الجلسات';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: رقم الجلسة في الورشة (field_serial) */
  $handler->display->display_options['sorts']['field_serial_value']['id'] = 'field_serial_value';
  $handler->display->display_options['sorts']['field_serial_value']['table'] = 'field_data_field_serial';
  $handler->display->display_options['sorts']['field_serial_value']['field'] = 'field_serial_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: ورشة (field_workshop) */
  $handler->display->display_options['arguments']['field_workshop_target_id']['id'] = 'field_workshop_target_id';
  $handler->display->display_options['arguments']['field_workshop_target_id']['table'] = 'field_data_field_workshop';
  $handler->display->display_options['arguments']['field_workshop_target_id']['field'] = 'field_workshop_target_id';
  $handler->display->display_options['arguments']['field_workshop_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_workshop_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_workshop_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_workshop_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_workshop_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['entity_type'] = 'node';
  $handler->display->display_options['bundles'] = array(
    0 => 'workshop',
  );
  $handler->display->display_options['show_title'] = 1;

  /* Display: Trainer Schedule */
  $handler = $view->new_display('block', 'Trainer Schedule', 'block_trainer_schedule');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'جدول اليومين';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_date_time_1',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_location' => 'field_location',
    'title_1' => 'title_1',
    'field_date_time' => 'field_date_time',
  );
  $handler->display->display_options['row_options']['separator'] = ',';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[field_fullname]';
  $handler->display->display_options['header']['area']['format'] = 'plain_text';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_target_id']['id'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['table'] = 'field_data_field_session';
  $handler->display->display_options['relationships']['field_session_target_id']['field'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['label'] = 'Session';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_workshop_target_id']['id'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['table'] = 'field_data_field_workshop';
  $handler->display->display_options['relationships']['field_workshop_target_id']['field'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['label'] = 'Workshop';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_trainers_target_id']['id'] = 'field_trainers_target_id';
  $handler->display->display_options['relationships']['field_trainers_target_id']['table'] = 'field_data_field_trainers';
  $handler->display->display_options['relationships']['field_trainers_target_id']['field'] = 'field_trainers_target_id';
  $handler->display->display_options['relationships']['field_trainers_target_id']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_trainers_target_id']['label'] = 'Trainer';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: day */
  $handler->display->display_options['fields']['field_date_time_1']['id'] = 'field_date_time_1';
  $handler->display->display_options['fields']['field_date_time_1']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time_1']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time_1']['ui_name'] = 'day';
  $handler->display->display_options['fields']['field_date_time_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_time_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_time_1']['settings'] = array(
    'format_type' => 'date_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: session-title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['fields']['title']['ui_name'] = 'session-title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: time */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['ui_name'] = 'time';
  $handler->display->display_options['fields']['field_date_time']['label'] = '';
  $handler->display->display_options['fields']['field_date_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'time_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: مكان */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['type'] = 'taxonomy_term_reference_plain';
  /* Field: session-title-linked-to-timespace */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['ui_name'] = 'session-title-linked-to-timespace';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: User: الاسم الكامل */
  $handler->display->display_options['fields']['field_fullname']['id'] = 'field_fullname';
  $handler->display->display_options['fields']['field_fullname']['table'] = 'field_data_field_fullname';
  $handler->display->display_options['fields']['field_fullname']['field'] = 'field_fullname';
  $handler->display->display_options['fields']['field_fullname']['relationship'] = 'field_trainers_target_id';
  $handler->display->display_options['fields']['field_fullname']['label'] = '';
  $handler->display->display_options['fields']['field_fullname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fullname']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: زمان (field_date_time) */
  $handler->display->display_options['sorts']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['sorts']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_trainers_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: زمان (field_date_time) */
  $handler->display->display_options['arguments']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['arguments']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['arguments']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['arguments']['field_date_time_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_date_time_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_date_time_value']['default_argument_options']['code'] = '$period_date = adef_camps_get_period_date();
return $period_date[\'year\'] . \'-\' . $period_date[\'month\'] . \'-\' . $period_date[\'day\'] . \'--P2D\';';
  $handler->display->display_options['arguments']['field_date_time_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_date_time_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_date_time_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'timespace' => 'timespace',
  );

  /* Display: Trainer Participants */
  $handler = $view->new_display('block', 'Trainer Participants', 'block_trainer_participants');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'المشاركون في الورش';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'small';
  $handler->display->display_options['style_options']['class'] = 'grid clearfix';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_profile_picture' => 'field_profile_picture',
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['separator'] = '&nbsp;';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_target_id']['id'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['table'] = 'field_data_field_session';
  $handler->display->display_options['relationships']['field_session_target_id']['field'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['label'] = 'Session';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_workshop_target_id']['id'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['table'] = 'field_data_field_workshop';
  $handler->display->display_options['relationships']['field_workshop_target_id']['field'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['label'] = 'Workshop';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_participants_target_id']['id'] = 'field_participants_target_id';
  $handler->display->display_options['relationships']['field_participants_target_id']['table'] = 'field_data_field_participants';
  $handler->display->display_options['relationships']['field_participants_target_id']['field'] = 'field_participants_target_id';
  $handler->display->display_options['relationships']['field_participants_target_id']['relationship'] = 'reverse_field_timespace_node';
  $handler->display->display_options['relationships']['field_participants_target_id']['label'] = 'Participant';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_trainers_target_id']['id'] = 'field_trainers_target_id';
  $handler->display->display_options['relationships']['field_trainers_target_id']['table'] = 'field_data_field_trainers';
  $handler->display->display_options['relationships']['field_trainers_target_id']['field'] = 'field_trainers_target_id';
  $handler->display->display_options['relationships']['field_trainers_target_id']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_trainers_target_id']['label'] = 'Trainer';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_timespace_node']['id'] = 'reverse_field_timespace_node';
  $handler->display->display_options['relationships']['reverse_field_timespace_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_timespace_node']['field'] = 'reverse_field_timespace_node';
  $handler->display->display_options['relationships']['reverse_field_timespace_node']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['reverse_field_timespace_node']['label'] = 'Timespace';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: صورة */
  $handler->display->display_options['fields']['field_profile_picture']['id'] = 'field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['table'] = 'field_data_field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['field'] = 'field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['relationship'] = 'field_participants_target_id';
  $handler->display->display_options['fields']['field_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_picture']['settings'] = array(
    'image_style' => 'profile_thumb_small',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_participants_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_participants_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_trainers_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_participants_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'participant' => 'participant',
  );

  /* Display: Participant Schedule */
  $handler = $view->new_display('block', 'Participant Schedule', 'block_participant_schedule');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'جدول';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'printed-schedule-slot';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_participants_target_id']['id'] = 'field_participants_target_id';
  $handler->display->display_options['relationships']['field_participants_target_id']['table'] = 'field_data_field_participants';
  $handler->display->display_options['relationships']['field_participants_target_id']['field'] = 'field_participants_target_id';
  $handler->display->display_options['relationships']['field_participants_target_id']['label'] = 'Participant';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_target_id']['id'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['table'] = 'field_data_field_session';
  $handler->display->display_options['relationships']['field_session_target_id']['field'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['label'] = 'Session';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_workshop_target_id']['id'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['table'] = 'field_data_field_workshop';
  $handler->display->display_options['relationships']['field_workshop_target_id']['field'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: زمان */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['label'] = '';
  $handler->display->display_options['fields']['field_date_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'time_only_12h',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: مكان */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: مدربين */
  $handler->display->display_options['fields']['field_trainers']['id'] = 'field_trainers';
  $handler->display->display_options['fields']['field_trainers']['table'] = 'field_data_field_trainers';
  $handler->display->display_options['fields']['field_trainers']['field'] = 'field_trainers';
  $handler->display->display_options['fields']['field_trainers']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['fields']['field_trainers']['label'] = '';
  $handler->display->display_options['fields']['field_trainers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trainers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_trainers']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: زمان (field_date_time) */
  $handler->display->display_options['sorts']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['sorts']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_participants_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: زمان (field_date_time) */
  $handler->display->display_options['arguments']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['arguments']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['arguments']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['arguments']['field_date_time_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_date_time_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_date_time_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_date_time_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_date_time_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_date_time_value']['granularity'] = 'day';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'timespace' => 'timespace',
  );

  /* Display: Registery Entries */
  $handler = $view->new_display('block', 'Registery Entries', 'block_participant_registry');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'realname' => 'realname',
    'field_tech_field' => 'field_tech_field',
    'field_edu_goals' => 'field_edu_goals',
    'body' => 'body',
    'delete_node' => 'created',
    'edit_node' => 'created',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'realname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tech_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_edu_goals' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_register_participant_target_id']['id'] = 'field_register_participant_target_id';
  $handler->display->display_options['relationships']['field_register_participant_target_id']['table'] = 'field_data_field_register_participant';
  $handler->display->display_options['relationships']['field_register_participant_target_id']['field'] = 'field_register_participant_target_id';
  $handler->display->display_options['relationships']['field_register_participant_target_id']['label'] = 'Participant';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'المدرب';
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: Content: الهدف التربوي */
  $handler->display->display_options['fields']['field_register_edu_goal']['id'] = 'field_register_edu_goal';
  $handler->display->display_options['fields']['field_register_edu_goal']['table'] = 'field_data_field_register_edu_goal';
  $handler->display->display_options['fields']['field_register_edu_goal']['field'] = 'field_register_edu_goal';
  $handler->display->display_options['fields']['field_register_edu_goal']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: في مجال */
  $handler->display->display_options['fields']['field_register_track']['id'] = 'field_register_track';
  $handler->display->display_options['fields']['field_register_track']['table'] = 'field_data_field_register_track';
  $handler->display->display_options['fields']['field_register_track']['field'] = 'field_register_track';
  $handler->display->display_options['fields']['field_register_track']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'ملاحظات';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'توقيت الاضافة';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'تحرير';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'مسح';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_register_participant_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: نوع (field_register_type) */
  $handler->display->display_options['arguments']['field_register_type_value']['id'] = 'field_register_type_value';
  $handler->display->display_options['arguments']['field_register_type_value']['table'] = 'field_data_field_register_type';
  $handler->display->display_options['arguments']['field_register_type_value']['field'] = 'field_register_type_value';
  $handler->display->display_options['arguments']['field_register_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_register_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_register_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_register_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_register_type_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'register_entry' => 'register_entry',
  );

  /* Display: Printed Schedule */
  $handler = $view->new_display('page', 'Printed Schedule', 'page_printed_schedule');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'printed-schedule';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_date_time_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_participants_node']['id'] = 'reverse_field_participants_node';
  $handler->display->display_options['relationships']['reverse_field_participants_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_participants_node']['field'] = 'reverse_field_participants_node';
  $handler->display->display_options['relationships']['reverse_field_participants_node']['label'] = 'Timespace';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_target_id']['id'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['table'] = 'field_data_field_session';
  $handler->display->display_options['relationships']['field_session_target_id']['field'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['relationship'] = 'reverse_field_participants_node';
  $handler->display->display_options['relationships']['field_session_target_id']['label'] = 'Session';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_workshop_target_id']['id'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['table'] = 'field_data_field_workshop';
  $handler->display->display_options['relationships']['field_workshop_target_id']['field'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['label'] = 'Workshop';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h1';
  $handler->display->display_options['fields']['title']['element_class'] = 'pagebreak';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Day */
  $handler->display->display_options['fields']['field_date_time_1']['id'] = 'field_date_time_1';
  $handler->display->display_options['fields']['field_date_time_1']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time_1']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time_1']['relationship'] = 'reverse_field_participants_node';
  $handler->display->display_options['fields']['field_date_time_1']['ui_name'] = 'Day';
  $handler->display->display_options['fields']['field_date_time_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_time_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_time_1']['element_type'] = 'h2';
  $handler->display->display_options['fields']['field_date_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_time_1']['settings'] = array(
    'format_type' => 'date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: زمان */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['relationship'] = 'reverse_field_participants_node';
  $handler->display->display_options['fields']['field_date_time']['label'] = '';
  $handler->display->display_options['fields']['field_date_time']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_date_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'time_only_12h',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: مكان */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['relationship'] = 'reverse_field_participants_node';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: مدربين */
  $handler->display->display_options['fields']['field_trainers']['id'] = 'field_trainers';
  $handler->display->display_options['fields']['field_trainers']['table'] = 'field_data_field_trainers';
  $handler->display->display_options['fields']['field_trainers']['field'] = 'field_trainers';
  $handler->display->display_options['fields']['field_trainers']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['fields']['field_trainers']['label'] = '';
  $handler->display->display_options['fields']['field_trainers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_trainers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_trainers']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_trainers']['multi_type'] = 'ul';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: زمان (field_date_time) */
  $handler->display->display_options['sorts']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['sorts']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['relationship'] = 'reverse_field_participants_node';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: زمان (field_date_time) */
  $handler->display->display_options['arguments']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['arguments']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['arguments']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['arguments']['field_date_time_value']['relationship'] = 'reverse_field_participants_node';
  $handler->display->display_options['arguments']['field_date_time_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_date_time_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_date_time_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_date_time_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_date_time_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_date_time_value']['granularity'] = 'day';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'participant' => 'participant',
  );
  $handler->display->display_options['path'] = 'camps/schedule/print';

  /* Display: Participant Attendance */
  $handler = $view->new_display('block', 'Participant Attendance', 'block_participant_attendance');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'سجل الحضور';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['separator'] = '&nbsp;';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_attended_target_id']['id'] = 'field_attended_target_id';
  $handler->display->display_options['relationships']['field_attended_target_id']['table'] = 'field_data_field_attended';
  $handler->display->display_options['relationships']['field_attended_target_id']['field'] = 'field_attended_target_id';
  $handler->display->display_options['relationships']['field_attended_target_id']['label'] = 'Participant';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_target_id']['id'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['table'] = 'field_data_field_session';
  $handler->display->display_options['relationships']['field_session_target_id']['field'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_session_target_id']['label'] = 'Session';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_workshop_target_id']['id'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['table'] = 'field_data_field_workshop';
  $handler->display->display_options['relationships']['field_workshop_target_id']['field'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['relationships']['field_workshop_target_id']['label'] = 'Workshop';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'Track';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'fields' => 'fields',
    'locations' => 0,
    'location_description' => 0,
    'educational_goals' => 0,
    'participant_groups' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: workshop-id */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'workshop-id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: زمان */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['label'] = '';
  $handler->display->display_options['fields']['field_date_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_session_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Taxonomy term: اللون */
  $handler->display->display_options['fields']['field_color']['id'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['table'] = 'field_data_field_color';
  $handler->display->display_options['fields']['field_color']['field'] = 'field_color';
  $handler->display->display_options['fields']['field_color']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_color']['label'] = '';
  $handler->display->display_options['fields']['field_color']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_color']['settings'] = array(
    'width' => '16',
    'height' => '16',
  );
  /* Field: Content: المجال */
  $handler->display->display_options['fields']['field_tech_field']['id'] = 'field_tech_field';
  $handler->display->display_options['fields']['field_tech_field']['table'] = 'field_data_field_tech_field';
  $handler->display->display_options['fields']['field_tech_field']['field'] = 'field_tech_field';
  $handler->display->display_options['fields']['field_tech_field']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['fields']['field_tech_field']['label'] = '';
  $handler->display->display_options['fields']['field_tech_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tech_field']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: الاهداف التربوية */
  $handler->display->display_options['fields']['field_edu_goals']['id'] = 'field_edu_goals';
  $handler->display->display_options['fields']['field_edu_goals']['table'] = 'field_data_field_edu_goals';
  $handler->display->display_options['fields']['field_edu_goals']['field'] = 'field_edu_goals';
  $handler->display->display_options['fields']['field_edu_goals']['relationship'] = 'field_workshop_target_id';
  $handler->display->display_options['fields']['field_edu_goals']['label'] = '';
  $handler->display->display_options['fields']['field_edu_goals']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_edu_goals']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_edu_goals']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_edu_goals']['delta_offset'] = '0';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'content_blocks';
  $handler->display->display_options['fields']['view']['display'] = 'block_edugoals_icons';
  $handler->display->display_options['fields']['view']['arguments'] = '[!nid]';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: زمان (field_date_time) */
  $handler->display->display_options['sorts']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['sorts']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_attended_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'timespace' => 'timespace',
  );

  /* Display: Participant Info Card */
  $handler = $view->new_display('block', 'Participant Info Card', 'block_participant_infocard');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h1';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: المجموعة */
  $handler->display->display_options['fields']['field_group']['id'] = 'field_group';
  $handler->display->display_options['fields']['field_group']['table'] = 'field_data_field_group';
  $handler->display->display_options['fields']['field_group']['field'] = 'field_group';
  $handler->display->display_options['fields']['field_group']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_group']['element_label_type'] = 'span';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: البلد */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_country']['element_label_type'] = 'span';
  /* Field: Content: تاريخ الميلاد */
  $handler->display->display_options['fields']['field_birthdate_1']['id'] = 'field_birthdate_1';
  $handler->display->display_options['fields']['field_birthdate_1']['table'] = 'field_data_field_birthdate';
  $handler->display->display_options['fields']['field_birthdate_1']['field'] = 'field_birthdate';
  $handler->display->display_options['fields']['field_birthdate_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_birthdate_1']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_birthdate_1']['settings'] = array(
    'dateformat' => 'd M Y ([age])',
  );
  /* Field: Content: بريد الكتروني */
  $handler->display->display_options['fields']['field_participant_email']['id'] = 'field_participant_email';
  $handler->display->display_options['fields']['field_participant_email']['table'] = 'field_data_field_participant_email';
  $handler->display->display_options['fields']['field_participant_email']['field'] = 'field_participant_email';
  $handler->display->display_options['fields']['field_participant_email']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_participant_email']['element_label_type'] = 'span';
  /* Field: Content: تليفون */
  $handler->display->display_options['fields']['field_participant_phone']['id'] = 'field_participant_phone';
  $handler->display->display_options['fields']['field_participant_phone']['table'] = 'field_data_field_participant_phone';
  $handler->display->display_options['fields']['field_participant_phone']['field'] = 'field_participant_phone';
  $handler->display->display_options['fields']['field_participant_phone']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_participant_phone']['element_label_type'] = 'span';
  /* Field: Content: مدرسة */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_school']['element_label_type'] = 'span';
  /* Field: Content: ملاحظات */
  $handler->display->display_options['fields']['field_participant_notes']['id'] = 'field_participant_notes';
  $handler->display->display_options['fields']['field_participant_notes']['table'] = 'field_data_field_participant_notes';
  $handler->display->display_options['fields']['field_participant_notes']['field'] = 'field_participant_notes';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Edugoals Icons */
  $handler = $view->new_display('block', 'Edugoals Icons', 'block_edugoals_icons');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'inline-list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'Edugoals';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'educational_goals' => 'educational_goals',
    'locations' => 0,
    'location_description' => 0,
    'fields' => 0,
    'participant_groups' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: الايقونة */
  $handler->display->display_options['fields']['field_icon']['id'] = 'field_icon';
  $handler->display->display_options['fields']['field_icon']['table'] = 'field_data_field_icon';
  $handler->display->display_options['fields']['field_icon']['field'] = 'field_icon';
  $handler->display->display_options['fields']['field_icon']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_icon']['label'] = '';
  $handler->display->display_options['fields']['field_icon']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_icon']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_icon']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_icon']['settings'] = array(
    'image_style' => 'icon_small',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $translatables['content_blocks'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Zamakan'),
    t('Session'),
    t('Workshop'),
    t('Participant'),
    t('Location'),
    t('track'),
    t('<div class="slots"></div>'),
    t('[body]<br/>[name_1]<br/>[field_trainers]'),
    t('All'),
    t('Trainers'),
    t('Content entity referenced from field_session'),
    t('Content entity referenced from field_workshop'),
    t('Schedule'),
    t('الجدول اليومي'),
    t('term from field_location'),
    t('term'),
    t('[field_date_time]'),
    t('Bulk Admin'),
    t('Content'),
    t('- Choose an operation -'),
    t('Type'),
    t('Info'),
    t('المجال'),
    t('عدد الجلسات'),
    t('مدربين'),
    t('Post date'),
    t('Updated date'),
    t('وقت'),
    t('Title'),
    t('زمان (field_date_time)'),
    t('Participants'),
    t('المشاركون'),
    t('السن'),
    t('الاسم'),
    t('Workshops'),
    t('الورش'),
    t('اقصى عدد للمشاركين'),
    t('الاهداف التربوية'),
    t('EVA Field'),
    t('الجلسات'),
    t('Trainer Schedule'),
    t('جدول اليومين'),
    t('[field_fullname]'),
    t('Trainer'),
    t('[title]'),
    t('Trainer Participants'),
    t('المشاركون في الورش'),
    t('Timespace'),
    t('Participant Schedule'),
    t('جدول'),
    t('Registery Entries'),
    t('author'),
    t('المدرب'),
    t('الهدف التربوي'),
    t('في مجال'),
    t('ملاحظات'),
    t('توقيت الاضافة'),
    t('تحرير'),
    t('مسح'),
    t('Printed Schedule'),
    t('Participant Attendance'),
    t('سجل الحضور'),
    t('Track'),
    t('Participant Info Card'),
    t('المجموعة'),
    t('البلد'),
    t('تاريخ الميلاد'),
    t('بريد الكتروني'),
    t('تليفون'),
    t('مدرسة'),
    t('Edugoals Icons'),
    t('Edugoals'),
  );
  $export['content_blocks'] = $view;

  $view = new view();
  $view->name = 'content_reference';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content Reference';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Contextual filter: Content: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Sessions */
  $handler = $view->new_display('dynamic_select', 'Sessions', 'dynamic_select_sessions');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'dynamic_select_style';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'dynamic_select_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_with_type_arg');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: زمان (field_date_time) */
  $handler->display->display_options['sorts']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['sorts']['field_date_time_value']['field'] = 'field_date_time_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';

  /* Display: Atendees */
  $handler = $view->new_display('entityreference', 'Atendees', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_participants_node']['id'] = 'reverse_field_participants_node';
  $handler->display->display_options['relationships']['reverse_field_participants_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_participants_node']['field'] = 'reverse_field_participants_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: صورة */
  $handler->display->display_options['fields']['field_profile_picture']['id'] = 'field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['table'] = 'field_data_field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['field'] = 'field_profile_picture';
  $handler->display->display_options['fields']['field_profile_picture']['label'] = '';
  $handler->display->display_options['fields']['field_profile_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_picture']['settings'] = array(
    'image_style' => 'profile_thumb_small',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_participants_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_participants_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Timespace for sessions */
  $handler = $view->new_display('entityreference', 'Timespace for sessions', 'entityreference_timespace');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_date_time' => 'field_date_time',
    'field_location' => 0,
    'field_session' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_location' => 'field_location',
    'field_date_time' => 'field_date_time',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: مكان (field_location) */
  $handler->display->display_options['relationships']['field_location_tid']['id'] = 'field_location_tid';
  $handler->display->display_options['relationships']['field_location_tid']['table'] = 'field_data_field_location';
  $handler->display->display_options['relationships']['field_location_tid']['field'] = 'field_location_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: مكان */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: زمان */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['label'] = '';
  $handler->display->display_options['fields']['field_date_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: جلسة */
  $handler->display->display_options['fields']['field_session']['id'] = 'field_session';
  $handler->display->display_options['fields']['field_session']['table'] = 'field_data_field_session';
  $handler->display->display_options['fields']['field_session']['field'] = 'field_session';
  $handler->display->display_options['fields']['field_session']['label'] = '';
  $handler->display->display_options['fields']['field_session']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_session']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_session']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_session']['settings'] = array(
    'link' => 0,
  );
  /* Field: diplay_title */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'diplay_title';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_location] - [field_date_time]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: مكان (field_location) */
  $handler->display->display_options['sorts']['field_location_tid']['id'] = 'field_location_tid';
  $handler->display->display_options['sorts']['field_location_tid']['table'] = 'field_data_field_location';
  $handler->display->display_options['sorts']['field_location_tid']['field'] = 'field_location_tid';
  /* Sort criterion: Content: زمان (field_date_time) */
  $handler->display->display_options['sorts']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['sorts']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: زمان (field_date_time) */
  $handler->display->display_options['arguments']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['arguments']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['arguments']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['arguments']['field_date_time_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_date_time_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_date_time_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_date_time_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_date_time_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_date_time_value']['granularity'] = 'day';
  $handler->display->display_options['arguments']['field_date_time_value']['granularity_reset'] = 0;
  $handler->display->display_options['arguments']['field_date_time_value']['use_fromto'] = 'no';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'timespace' => 'timespace',
  );
  $translatables['content_reference'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('All'),
    t('Sessions'),
    t('Entity Reference'),
    t('Atendees'),
    t('Content referencing Content from field_participants'),
    t('Timespace for sessions'),
    t('term from field_location'),
    t('[field_location] - [field_date_time]'),
  );
  $export['content_reference'] = $view;

  $view = new view();
  $view->name = 'users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_trainers');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Trainers Entity Reference';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'realname' => 'realname',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  $translatables['users'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Entity Reference'),
    t('Trainers Entity Reference'),
  );
  $export['users'] = $view;

  return $export;
}

<?php
/**
 * @file
 * adefcamps_feeds.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function adefcamps_feeds_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'schedule-start-strtotime';
  $feeds_tamper->importer = 'schedule';
  $feeds_tamper->source = 'Start';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['schedule-start-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'workshops-edugoal-explode';
  $feeds_tamper->importer = 'workshops';
  $feeds_tamper->source = 'edugoal';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['workshops-edugoal-explode'] = $feeds_tamper;

  return $export;
}

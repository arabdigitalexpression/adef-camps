<?php
/**
 * @file
 * adef_camps_site_settings.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function adef_camps_site_settings_default_rules_configuration() {
  $items = array();
  $items['rules_notify_of_new_users'] = entity_import('rules_config', '{ "rules_notify_of_new_users" : {
      "LABEL" : "Notify of new users",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Adef Camps" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "112438630" : "112438630" } },
            "subject" : "Adef Camps new user",
            "message" : "A new account [account:name] was created for [account:mail]. View it by following this link [account:url]"
          }
        }
      ]
    }
  }');
  return $items;
}

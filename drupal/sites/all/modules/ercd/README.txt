README.txt
==========

-- SUMMARY --

This is a simple but powerful module for Drupal 7 that allows administrators
to effectively manage child entities when their parent entities are deleted.
Upon parent entity deletion, it gives the option to either delete all
dependent entities or drill down the tree of child entities and unselect any
that you wish to maintain. The term "parent" and "child" depends on the set
up. Some may prefer to set up their children to refer to their parents, and
others may prefer to set up their parents to refer to their children. Only
users who have the correct permissions will be able to access this option;
otherwise, no dependent entities will be deleted.

Currently, this module supports all entities that are in Core and the
Rules:config entity. File entities are supported when using the File Entity
module (http://drupal.org/project/file_entity). There is a bug in Entity
Reference with regard to Comment entity references, but a patch has been
submitted. Once/if this is committed, comment entity references should also
be supported.

-- DISCLAIMER: PLEASE READ CAREFULLY BEFORE USING THIS MODULE --

This module should only be used for very specific situations where entity
reference fields help to build parent-child entity relationships where the
child is dependent on the parent's existence. It is not intended for every
entity reference relationship. Especially in complex setups with many
entities referencing many other other entities, using Entity Reference
Cascade Delete could have catastrophic results. Loss of entities due to
poorly or improperly configuring this module (or any other reason for that
matter) will not be the responsibility of the creator or the maintainer.

That being said, the following fail-safes have been put in place:
1. User id 1 and users with the administrator role will be not subject to
cascade deletion.
2. Entities and their children that have references to other entities
outside of the current cascade will not be subject to cascade deletion.
3. Entities and their children that have multiple reference points within
a cascade will be preserved during cascade deletion if one of the reference
points is selected but the other is unselected.

-- REQUIREMENTS --

Entity Reference: http://drupal.org/project/entityreference

-- OPTIONAL --

File Entity: http://drupal.org/project/file_entity

-- INSTALLATION --

Install as usual. See Installing contributed modules
(http://www.drupal.org/documentation/install/modules-themes/modules-7) for
further information.

-- CONFIGURATION --

1. Go to Entity Reference Cascade Delete settings (admin/config/content/ercd)
to choose the correct entity reference model. Then choose which entities can
trigger a cascade deletion when they are deleted and which entity types will
be subject to the cascade deletion. Keep in mind that users will have the
option of selecting/unselecting all specific entities on the "confirm delete"
pages.
2. Set appropriate permissions for each role. Permissions are broken down to
each parent-child entity reference.

-- TROUBLESHOOTING --

If you don't see any referencing/referenced entities showing up--or not as
many as you expected to see--when deleting an entity, check the following
things:
1. Make sure you have actually enabled a cascade deletion for that entity.
2. Make sure your user role has permission to perform the cascade deletion.
3. Check if the entites you were expecting to see are referenced/referencing
an entity that is outside the scope of the cascade.

-- CONTACT --

Current maintainers:
* Andrew Howell (atozstudio) - http://drupal.org/user/572698

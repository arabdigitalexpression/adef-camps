<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <?php
  $daycode = $view->result[$id]->field_field_date_time[0]['raw']['value'];
  $start = date('Hi', strtotime($daycode));
  $daycode = date('Y-m-d', strtotime($daycode));
  $duration = isset($view->result[$id]->field_field_duration[0]) ? $view->result[$id]->field_field_duration[0]['raw']['value']: "120";
  ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  }?> data-daycode="<?php print $daycode; ?>" data-start="<?php print $start; ?>" data-duration="<?php print $duration; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
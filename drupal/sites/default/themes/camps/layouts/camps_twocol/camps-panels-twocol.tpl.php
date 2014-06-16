<div class="panel-2col clearfix panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
    <div class="panel-col-first panel-panel">
      <div class="inside"><?php print $content['first']; ?></div>
    </div>
    <div class="panel-col-last panel-panel">
      <div class="inside"><?php print $content['last']; ?></div>
    </div>
</div>

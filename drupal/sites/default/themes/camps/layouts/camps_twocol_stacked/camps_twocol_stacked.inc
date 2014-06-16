<?php

// Plugin definition
$plugin = array(
  'title' => t('Camps Two column stacked'),
  'category' => t('Camps'),
  'icon' => 'camps_twocol_stacked.png',
  'theme' => 'camps_panels_twocol_stacked',
  'css' => 'camps_twocol_stacked.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('First'),
    'right' => t('Last'),
    'bottom' => t('Bottom')
  ),
);

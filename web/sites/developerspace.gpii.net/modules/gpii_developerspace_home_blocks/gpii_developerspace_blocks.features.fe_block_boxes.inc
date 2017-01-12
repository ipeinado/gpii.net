<?php
/**
 * @file
 * gpii_developerspace_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function gpii_developerspace_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Home Page Links';
  $fe_block_boxes->format = 'ds_code';
  $fe_block_boxes->machine_name = 'home_links';
  $fe_block_boxes->body = '<div class="col-md-6 col-md-offset-0 col-sm-18 col-sm-offset-3">
<div id="learning-card" class="card">
<header>
<h2>
<span class="glyphicon glyphicon-education"></span>
Learn accessibility
</h2>
</header>
<div class="card-content">
<p>We are building the most comprehensive library of resources on accessibility. Find anything you need!</p>
<p><a href="<?php print url(\'taxonomy/term/740\'); ?>">Quicksheets</a></p>
</div>
</div>
</div>
<div class="col-md-6 col-md-offset-0 col-sm-18 col-sm-offset-3">
<div id="develop-card" class="card">
<header>
<h2>
<span class="glyphicon glyphicon-cog"></span>
Develop new solutions
</h2>
</header>
<div class="card-content">
<p>Find and share components and tools that will help you develop accessible solutions easier and cheaper.</p>
</div>
</div>
</div>
<div class="col-md-6 col-md-offset-0 col-sm-18 col-sm-offset-3">
<div id="market-card" class="card">
<header>
<h2>
<span class="glyphicon glyphicon-globe"></span>
Show and sell
</h2>
</header>
<div class="card-content">
<p>Find what others are doing and market your solutions internationally by using GPII\'s <a href="">Unified Listing</a></p>
</div>
</div>
</div>
<div class="col-md-6 col-md-offset-0 col-sm-18 col-sm-offset-3">
<div id="people-card" class="card">
<header>
<h2>
<span class="glyphicon glyphicon-user"></span>
Find People
</h2>
</header>
<div class="card-content">
<p>Find developers, end users and/or volunteers that can help you ideate, test and develop new ideas.</p>
</div>
</div>
</div>';

  $export['home_links'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Welcome Block';
  $fe_block_boxes->format = 'markdown';
  $fe_block_boxes->machine_name = 'welcome_block';
  $fe_block_boxes->body = '<h1>Welcome to the GPII DeveloperSpace</h1>
<p>The one-stop place to find resources, components and people to conceive, develop, test and market new <span class="highlight">accessibility</span> solutions</p>';

  $export['welcome_block'] = $fe_block_boxes;

  return $export;
}

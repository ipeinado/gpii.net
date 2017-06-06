<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */
?>
<div id="wrap" class="wrapper">
  <header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
    <div class="container-fluid">
      <?php if ($region_info['topbar']['has_columns']): ?>
        <?php print gpii_base_equal_width_column_regions($page, $region_info, 'topbar'); ?>
      <?php endif; ?>
    </div>

    <div class="container-fluid">
      <div class="navbar-header">
        <?php if ($logo): ?>
          <a class="logo navbar-btn pull-left" href="http://www.gpii.net" title="<?php print t('Visit the GPII.net Home Page to learn more about GPII'); ?>">
            <img src="<?php print $logo; ?>" alt="<?php print t('GPII.net Home Page'); ?>" />
          </a>
        <?php endif; ?>
        <?php if (!empty($site_slogan)): ?>
          <p class="lead"><a href="<?php print $front_page; ?>" title="<?php print t($site_slogan . ' Home'); ?>"><?php print $site_slogan; ?></a></p>
        <?php endif; ?>

        <?php if (!empty($site_name)): ?>
          <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
        <?php endif; ?>

        <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation']) || $region_info['menu']['has_columns']): ?>
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
            <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
        <?php endif; ?>
      </div>

      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation']) || $region_info['menu']['has_columns']): ?>
        <div class="navbar-collapse collapse">
          <?php if ($region_info['header']['has_columns']): ?>
            <?php print gpii_base_equal_width_column_regions($page, $region_info, 'header'); ?>
          <?php endif; ?>

          <nav role="navigation">
            <h1 class="sr-only">Main Navigation</h1>
            <?php if (!empty($primary_nav)): ?>
              <?php print render($primary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($secondary_nav)): ?>
              <?php print render($secondary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($page['navigation'])): ?>
              <?php print render($page['navigation']); ?>
            <?php endif; ?>

            <?php if ($region_info['menu']['has_columns']): ?>
              <?php print gpii_base_equal_width_column_regions($page, $region_info, 'menu'); ?>
            <?php endif; ?>
          </nav>
        </div>
      <?php endif; ?>
    </div>
  </header>

  <section id="hero-homepage" role="banner">
    <?php if (!empty($page['hero'])): ?>
      <?php print render($page['hero']); ?>
    <?php endif; ?>
  </section>

  <div id="main-container" class="main-container <?php print $container_class; ?>">
    <div class="row">
      <section <?php print $content_column_class; ?>>
        <?php if (!empty($page['highlighted']) && !$is_front): ?>
          <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
        <?php endif; ?>

        <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if (!empty($title)): ?>
          <h1 class="page-header element-invisible"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php if (!empty($tabs)): ?>
          <?php print render($tabs); ?>
        <?php endif; ?>
        <?php if (!empty($page['help'])): ?>
          <?php print render($page['help']); ?>
        <?php endif; ?>
        <?php if (!empty($action_links)): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>

        <?php if (!empty($page['user_groups'])): ?>
          <h2 class="element-invisible">User Groups</h2>
          <?php print render($page['user_groups']); ?>
        <?php endif; ?>

        <?php if (!empty($page['content_preface'])): ?>
          <?php print render($page['content_preface']); ?>
        <?php endif; ?>

        <?php print render($page['content']); ?>

        <?php if (!empty($page['content_postscript'])): ?>
          <?php print render($page['content_postscript']); ?>
        <?php endif; ?>
      </section>

      <?php if (!empty($page['sidebar_first'])): ?>
        <aside id="sidebar_first" class="<?php print $sidebar_first_column_class; ?>" role="complementary">
          <?php print render($page['sidebar_first']); ?>
        </aside>  <!-- /#sidebar-first -->
      <?php endif; ?>

      <?php if (!empty($page['sidebar_second'])): ?>
        <aside id="sidebar_second" class="<?php print $sidebar_second_column_class; ?>" role="complementary">
          <?php print render($page['sidebar_second']); ?>
        </aside>  <!-- /#sidebar-second -->
      <?php endif; ?>
    </div>

    <?php if ($region_info['secondary']['has_columns']): ?>
      <section id="secondary" class="<?php print $container_class; ?>">
        <?php print gpii_base_equal_width_column_regions($page, $region_info, 'secondary'); ?>
      </section>
    <?php endif; ?>

    <?php if ($region_info['tertiary']['has_columns']): ?>
      <section id="tertiary" class="<?php print $container_class; ?>">
        <?php print gpii_base_equal_width_column_regions($page, $region_info, 'tertiary'); ?>
      </section>
    <?php endif; ?>
  </div>
</div>

<div id="push"></div>

<?php if ($has_footer_regions): ?>
  <div id="footer-wrap">
    <footer id="footer" class="footer container-fluid">
      <section>
        <h1 class="element-invisible">Footer</h1>
        <?php if ($region_info['footer']['has_columns']): ?>
          <?php
            $widths = array(
              'first' => '4',
              'second' => '5',
              'third' => '5',
              'fourth' => '5',
              'fifth' => '5',
              );
            print gpii_base_variable_width_column_regions($page, $region_info, 'footer', $widths);
          ?>
        <?php endif; ?>

        <?php if ($region_info['fine_print']['has_columns']): ?>
          <?php print gpii_base_equal_width_column_regions($page, $region_info, 'fine_print'); ?>
        <?php endif; ?>
      </section>
    </footer>
  </div>
<?php endif; ?>

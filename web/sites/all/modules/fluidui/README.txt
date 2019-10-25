-- SUMMARY --

This module integrates the fluidproject.org UI Options accessibility framework,
which allows visitors to customize site appearance, including font size, line
height, site contrast, generate a table of contents from the <h> tags, and
underlining and bolding links.

The module adds a "+ show display preferences" tab to the top right of the page,
which toggles the UI Options. The framework uses cookies to save user
preferences.


-- REQUIREMENTS --

* The Libraries API module (https://www.drupal.org/project/libraries) and the Fluid UI Options framework source files (at least version 3.0.0).

* jquery_update to update jquery to at least version 1.7.

-- INSTALLATION --

* Install as usual, see http://drupal.org/node/895232 for further information.

* Download the source files from
  https://github.com/fluid-project/infusion/ (version 3.0) 

  - From the project root directory, run:

    npm install

    For installing/updating the project dependencies

  - Also from the project root directory, run:

    grunt custom --exclude="jQuery" --include="uiOptions"

    For building the uiOptions package from the source files

  - On the "sites/all/libraries" directory from your site's document root, create the "fluid" directory.

  - Copy "lib", "framework", and "components" folders from the build/src/ folder
  to your sites/all/libraries/fluid folder.

  - create the "infusion" directory in sites/all/libraries/fluid/lib.

  - Copy infusion-custom.js from the build directory to sites/all/libraries/fluid/lib/infusion


-- CONFIGURATION --

* You can control the list of pages where the toolbox will not be displayed and also if you want the toolbox to be displayed on admin pages (such as /admin/content, /admin/structure, etc.). The configuration form is found on /admin/config/fluidui/adminsettings

-- CUSTOMIZATION --

* Style customization

  Use the module's css/fluid.css file to customize the appearance and placement
  of the "+ show display preferences" tab.

  You can also use this file for changing the appearance of the html elements inside the panel (boxes, titles, input elements, etc).

* Multilingual support

  The framework supports multilingual labels and text, but it must be created
  manually and cannot be created from the Drupal admin UI. The js/load.js needs
  to be modified and translated files created for the TableOfContents.html file
  and the /messages directory. You can use Drupal.settings.basePath or
  document.location.origin to determine the URL. An example configuration
  follows:

  var origin = document.location.host;

  if (origin == "[English URL]"1) {
    fluid.uiOptions.prefsEditor(".flc-prefsEditor-separatedPanel", {
      tocTemplate: origin + "/sites/all/libraries/fluid/components/
      tableOfContents/html/TableOfContents.html",
      templatePrefix: origin + "/sites/all/libraries/fluid/framework/
      preferences/html/",
      messagePrefix: origin + "/sites/all/modules/fluid/messages/en/",
     )};
	} else if (origin == "[French URL]") {
    fluid.uiOptions.prefsEditor(".flc-prefsEditor-separatedPanel", {
      tocTemplate: origin + "/sites/all/libraries/fluid/components/
      tableOfContents/html/TableOfContentsFR.html",
      templatePrefix: origin + "/sites/all/libraries/fluid/framework/
      preferences/html/",
      messagePrefix: origin + "/sites/all/modules/fluid/messages/fr/",
    });
  }

-- TROUBLESHOOTING --

* This module has been tested on the most popular themes successfully. Font
  sizing and line height modifications will only work if the sizes are
  percentage or EM based, they will not work if they are set to pixel sizes or
  if the base font size is not set in the <body> tag (i.e. Bootstrap theme).
  Setting the font-size:100% in the <body> tag solves the issue.


-- CONTACT --

Current maintainers:
* Ash Ahmadzadeh (ashopin)- https://www.drupal.org/u/ashopin
* Steve Lavigne (Nugg) - https://www.drupal.org/u/nugg
* Jess Hunte (jess.hunte) - https://www.drupal.org/u/jess.hunte
* Daniel Rodriguez (danrod) - https://www.drupal.org/u/danrod


This project has been sponsored by:
* OpenConcept Consulting Inc.
* OPIN Software Inc.
  OPIN is a provider of enterprise content management solutions built with
  Drupal. At OPIN, our vision is to assist clients through Drupal
  implementation and consulting and to help them achieve an effective web
  presence.

# Introduction

The GPII OAuth2 Authentication module authenticates users via the GPII OAuth2 Identity and Access Management component. It is tailored to both the GPII Drupal site and the IAM component.

# Installation

Make sure to install the [Libraries](https://www.drupal.org/project/libraries) module and its dependencies. Then, install the necessary libraries. The libraries require [composer](https://getcomposer.org/) to install their dependencies, so make sure it's installed as well.

If using composer on a production machine isn't desirable or feasible, the libraries can be copied from a development machine after using running the composer command below. Just make sure that the server meets the PHP version and extension requirements of the libraries as listed in the `composer.json` files.

## Guzzle

Download the [Guzzle](https://github.com/guzzle/guzzle) library and [extract it to one of the library directories](https://www.drupal.org/docs/7/modules/libraries-api/installing-an-external-library-that-is-required-by-a-contributed-module), e.g., `sites/all/libraries/guzzle`. Then, install its dependencies:

    $ cd sites/all/libraries/guzzle
    $ composer install --no-dev

The latest version tested and known to work is the v6.2.3 release.

## constant\_time\_encoding

Download the [constant\_time\_encoding](https://github.com/paragonie/constant_time_encoding) library and [extract it to one of the library directories](https://www.drupal.org/docs/7/modules/libraries-api/installing-an-external-library-that-is-required-by-a-contributed-module), e.g., `sites/all/libraries/constant_time_encoding`. Then, install its dependencies:

    $ cd sites/all/libraries/constant_time_encoding
    $ composer install --no-dev

The latest version tested and known to work is the v1.0.1 release. Note that the v2.x series doesn't support PHP 5.x.

## hash-compat

Download the [hash-compat](https://github.com/indigophp/hash-compat) library and [extract it to one of the library directories](https://www.drupal.org/docs/7/modules/libraries-api/installing-an-external-library-that-is-required-by-a-contributed-module), e.g., `sites/all/libraries/hash-compat`. Then, install its dependencies:

    $ cd sites/all/libraries/hash-compat
    $ composer install --no-dev

The latest version tested and known to work is the v1.1.0 release.

# Configuration

After installing the module and its dependencies, configure the settings for the module from the configuration page. Once that is done, the *GPII OAuth2 user menu* block should be placed somewhere so that users can easily log in, log out, and access their single sign-on accounts. It might also be useful to disable user registrations and the default user blocks.

# Credits

This module was originally developed by [Tim Baumgard](https://www.bmgrd.com/).

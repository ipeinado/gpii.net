# Introduction

The GPII Base theme is using the Sass Starterkit from the Drupal Bootstrap base theme.

# Drupal Theme Settings

These settings should be set automatically when enabling the theme but are here for reference.

- `General` > `Forms` > `Smart form descriptions (via Tooltips)` => `off`
- `General` > `Tables` > `Hover rows` => `off`
- `Components` > `Navbar` > `Navbar Position` => `Static Top`
- `Components` > `Region Wells` > `Sidebar First` => `None`
- `Advanced` > `CDN` > `CDN Provider` => `None`
- `Toggle Display` > `Site slogan` => `off`

# CSS Generation

## Setup

CSS generation for the theme requires a few processors. Install Node.js and Ruby first, then install the necessary packages and gems:

    $ npm install -g postcss-cli autoprefixer
    $ gem install sass

## Bootstrap-related CSS

The files in the `bootstrap/bootstrap` and `bootstrap/bootstrap-em` directories should only be changed when there has been an update to one of the libraries. The `bootstrap/bootstrap` directory should contain the Sass-version of the Bootstrap CSS library. The `bootstrap/bootstrap-em` directory should contain the Sass files from the bootstrap-em.scss code.

## GPII Base Theme

To generate the CSS for the theme, go to the GPII base theme directory and use `sass` and `postcss`:

    $ cd sites/all/themes/gpii_base
    $ sass --update --style compressed --sourcemap=none scss:css
    $ postcss --use autoprefixer --config css/postcss.json --dir css css/*.css

When developing or debugging, the `--style compressed` and `--sourcemap=none` options should be omitted.

# Useful Links

- [Bootstrap Documentation](https://getbootstrap.com/getting-started/)
- [Drupal Bootstrap](https://www.drupal.org/project/bootstrap)
- [Drupal Bootstrap Documentation](http://drupal-bootstrap.org/api/bootstrap)
- [Sass](http://sass-lang.com/)
- [Sass port of jasny/bootstrap-em.less](https://gist.github.com/neil-h/631c5e848ba1f2ae92d1)

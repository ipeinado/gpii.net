# Introduction

The GPII Developer Space theme is a branch of the GPII Base theme.

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

## GPII Base Theme

To generate the CSS for the theme, go to the GPII base theme directory and use `sass` and `postcss`:

    $ cd sites/all/themes/gpii_devspace
    $ sass --update --style compressed --sourcemap=none scss:css
    $ postcss --use autoprefixer --config css/postcss.json --dir css css/*.css

When developing or debugging, the `--style compressed` and `--sourcemap=none` options should be omitted.

# Useful Links

- [Bootstrap Documentation](https://getbootstrap.com/getting-started/)
- [Drupal Bootstrap](https://www.drupal.org/project/bootstrap)
- [Drupal Bootstrap Documentation](http://drupal-bootstrap.org/api/bootstrap)
- [Sass](http://sass-lang.com/)

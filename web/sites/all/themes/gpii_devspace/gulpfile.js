var gulp = require('gulp'),
  sass = require('gulp-sass'),
  postcss = require('gulp-postcss'),
  autoprefixer = require('autoprefixer'),
  cssnano = require('cssnano'),
  sourcemaps = require('gulp-sourcemaps'),
  browserSync = require('browser-sync').create();

var paths = {
  styles: {
    src: './scss/**/*.scss',
    dest: './css'
  },
  scripts: {
    src: './js/**/*.js'
  }
};

var proxy = 'dev.ds.gpii.net';

function style() {
  return gulp
    .src(paths.styles.src)
    .pipe(sourcemaps.init())
    .pipe(sass({ precision: 8 }))
    .on('error', sass.logError)
    .pipe(postcss([autoprefixer(), cssnano()]))
    .pipe(sourcemaps.write())
    .pipe(gulp.dest(paths.styles.dest))
    .pipe(browserSync.stream());
}

function reload() {
  browserSync.reload();
}

function watch() {
  browserSync.init({ proxy: proxy });
  gulp.watch(paths.styles.src, style);
  gulp.watch([paths.styles.dest, paths.scripts.src]).on('change', browserSync.reload);
}

// Don't forget to expose the task!
exports.watch = watch;
exports.style = style;

/*
 * Specify if tasks run in series or parallel using `gulp.series` and `gulp.parallel`
 */
var build = gulp.parallel(style, watch);

exports.default = build;

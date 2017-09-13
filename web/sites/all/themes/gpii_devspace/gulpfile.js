var gulp = require('gulp'),
    gutil = require('gulp-util'),
    watch = require('gulp-watch'),
    sass = require('gulp-sass'),
    postcss = require('gulp-postcss'),
    autoprefixer = require('autoprefixer'),
    livereload = require('gulp-livereload'),
    sourcemaps = require('gulp-sourcemaps'),
    scsslint = require('gulp-scss-lint');


    gulp.task('default', ['watch']);

    var input = './scss/**/*.scss';
    var output = './tmpcss';

    gulp.task('sass', function () {
      return gulp
        // Find all `.scss` files from the `stylesheets/` folder
        .src(input)
        // Run Sass on those files
        .pipe(sass({precision: '8'}).on('error', sass.logError))
        // Write the resulting CSS in the output folder
        .pipe(gulp.dest(output))
        .pipe(livereload());
    });

    gulp.task('watch', function() {
      //livereload.listen();
      return gulp
        // Watch the input folder for change,
        // and run `sass` task when something happens
        .watch(input, ['sass', 'tmpcss'])
        // When there is a change,
        // log a message in the console
        .on('change', function(event) {
          console.log('File ' + event.path + ' was ' + event.type + ', running tasks...');
        });
    });

    gulp.task('tmpcss', function () {
      var processors = [
        autoprefixer({browsers: [
          "Android 2.3",
          "Android >= 4",
          "Chrome >= 20",
          "Firefox >= 24",
          "Explorer >= 8",
          "iOS >= 6",
          "Opera >= 12",
          "Safari >= 6"
        ]}),
      ];
      return gulp.src('./tmpcss/*.css')
        .pipe(sourcemaps.init())
        .pipe(postcss(processors))
        .pipe(sourcemaps.write('.'))
        .pipe(gulp.dest('./css'));
    });

    // if working on a remote server, use by ssh port forwarding -L 35729:localhost:35729 username@server

    // server = livereload.createServer();
    // server.watch([__dirname + "/js", __dirname + "/css"]);

var gulp = require('gulp'),
    gutil = require('gulp-util'),
    watch = require('gulp-watch'),
    sass = require('gulp-sass'),
    livereload = require('livereload');

    gulp.task('default', ['watch']);

    var input = './sass/**/*.scss';
    var output = './css';

    gulp.task('sass', function () {
      return gulp
        // Find all `.scss` files from the `stylesheets/` folder
        .src(input)
        // Run Sass on those files
        .pipe(sass())
        // Write the resulting CSS in the output folder
        .pipe(gulp.dest(output));
    });

    gulp.task('watch', function() {
      return gulp
        // Watch the input folder for change,
        // and run `sass` task when something happens
        .watch(input, ['sass'])
        // When there is a change,
        // log a message in the console
        .on('change', function(event) {
          console.log('File ' + event.path + ' was ' + event.type + ', running tasks...');
        });
    });

    // if working on a remote server, use by ssh port forwarding -L 35729:localhost:35729 p7sbcadocsweb@qual-msn-stg06

    server = livereload.createServer();
    server.watch([__dirname + "/js", __dirname + "/css"]);

var gulp = require('gulp'),
    gutil = require('gulp-util'),
    watch = require('gulp-watch'),
    sass = require('gulp-sass'),
    livereload = require('livereload');

    gulp.task('default', ['watch']);

gulp.task('sass', function () {
 gulp.src('./sass/**/*.scss')
   .pipe(sass({outputStyle: 'compressed'}))
   .pipe(gulp.dest('./css'));
});
     
    gulp.task('sass:watch', function () {
      gulp.watch('./sass/**/*.scss', ['sass']);
    });



 //    gulp.task('sass', function() {
	// gulp.src('sass/**/*.scss')
 //        .pipe(sass().on('error', sass.logError))
 //        .pipe(sass({outputStyle: 'compressed'}))
 //        .pipe(gulp.dest('css'))
 //    });

    gulp.task('watch', function () {
      gulp.watch('./sass/**/*.scss', ['sass']);  // Watch all the .scss files, then run the sass task
    });

    // if working on a remote server, use by ssh port forwarding -L 35729:localhost:35729 p7sbcadocsweb@qual-msn-stg06

    server = livereload.createServer();
    server.watch([__dirname + "/js", __dirname + "/css"]);

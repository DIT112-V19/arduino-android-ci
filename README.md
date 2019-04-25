# TravisCI for Android & Arduino [![Build Status](https://travis-ci.org/DIT112-V19/arduino-android-ci.svg?branch=master)](https://travis-ci.org/DIT112-V19/arduino-android-ci)
A sample repository with a Travis Continuous Integration setup for an Arduino sketch and an Android application.

## What?
This repository includes a sample TravisCI configuration for a system that includes an Android application
and an Arduino sketch. After being triggered, it performs the following actions:
* Builds the Android application
* Runs the Android application's unit tests
* Runs the Android application's instrumented tests
* Builds the Arduino sketch(es)

## Why?
Continuous Integration is **good for you**. It ensures the development team their newly introduced changes do not
break the already existing functionality and do not introduce regressions. Furthermore, it potentially enables
them to continuously deliver or deploy their software.

## How?
When using the default TravisCI configuration, the CI job gets triggered whenever a new commit is pushed
on any branch or a pull request is created.

It performs all actions defined in [.travis.yml](https://github.com/DIT112-V19/arduino-android-ci/blob/master/.travis.yml)
and if one of them fails it designates the entire build as unsuccessful.
Each stage of the [job lifecycle](https://docs.travis-ci.com/user/job-lifecycle/) is rather excessively documented
and explained, however especially the parts regarding the Android application are rather tricky and, sadly, tend
to break upon the release of new API and SDK versions.
particle-skycons
================

![Animated demo](https://github.com/wgbartley/particle-skycons/blob/master/images/movie.gif)

_* Note the screen refresh line you see in the animated gif is from the recorded video--it's not apparent to the human eye._

About
-----
A port of the popular [Skycons](https://darkskyapp.github.io/skycons/) JavaScript
library to the Particle Photon (and possibly other Arduino-compatible microcontrollers).

This library is very much a work in progress.  As of the initial publish (v0.0.1), it does
not have the windy or fog icons completed.  It is definitely not optimal or optimized.  Any
help is greatly appreciated.  Especially if you could help make this extend the Adafruit GFX
library instead of the SSD1306 so that this library can be used on many different types of
displays.


What You Need
-------------

 - A Particle Photon (or other compatible device)
 - An SSD1306 OLED display


How to Use
----------
This library extends the Adafruit SSD1306 library ([here](https://github.com/pkourany/Adafruit_SSD1306)
or [here](https://github.com/pkourany/Adafruit_SSD1306_mfGFX_IDE)), so you will
need to use it and its Adafruit GFX dependency.

To-Do
-----

 - Get windy/leaf working
 - Add fog
 - Fix random pixels inside clouds
 - Fix jerkiness with rain/sleet/snow
 - Optimize float/int usage
 - Extend GFX library instead of SSD1306 library


Static Images
-------------
_Sunny_

![Sunny](https://github.com/wgbartley/particle-skycons/blob/master/images/sunny.jpg "Sunny")

_Cloudy_

![Cloudy](https://github.com/wgbartley/particle-skycons/blob/master/images/cloudy.jpg "Cloudy")

_Moon/Clear Night_

![Moon](https://github.com/wgbartley/particle-skycons/blob/master/images/moon.jpg "Moon")

_Cloudy Night_

![Cloudy Night](https://github.com/wgbartley/particle-skycons/blob/master/images/cloudy_night.jpg "Cloudy Night")

_Partly Sunny_

![Partly Sunny](https://github.com/wgbartley/particle-skycons/blob/master/images/partly_sunny.jpg "Partly Sunny")

_Rain_

![Rain](https://github.com/wgbartley/particle-skycons/blob/master/images/rain.jpg "Rain")

_Sleet_

![Sleet](https://github.com/wgbartley/particle-skycons/blob/master/images/sleet.jpg "Sleet")

_Snow_

![Snow](https://github.com/wgbartley/particle-skycons/blob/master/images/snow.jpg "Snow")

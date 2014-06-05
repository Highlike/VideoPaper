VideoPaper
==========

**A project to replace blank sheets of papers with movies or pictures**

Description
----------

VideoPaper uses a camera or a file as background.
Then you can specify a *movie* or a *picture* to fill the blank sheets of papers with.

Preview
-------

This is how running VideoPaper can look like!

![alt text][screen]

[screen]: https://github.com/Highlike/VideoPaper/raw/master/screens/screen03.png "screen"

Usage
-----

### Starting the application

Looking up the options is as easy as typing:

    $ ./videopaper --help
      -c, --cam=[0]               camera number
      -f, --file                  file to use instead of camera
      -h, --help=[true]           print help message
      -m, --movie                 movie file
      -p, --picture               a picture

In DCIM you can see lots of example pictures.
To make a slideshow out of them, you can use *create_slideshow.sh*.

### Using it

After opening VideoPaper, you can see 2 windows.
In one you can see the edges of the current picture and in the other one you can see the edited video.

#### Edge Frame

First of all, you need to get a good view of the contours of the piece of paper.
Adjust the sliders *low threshold* and *high threshold* to get a good view of the contours of the piece of paper and to remove unnecessary ones.
If you can't seem to get all the contours, try to adjust aperture size.

#### Main Window

In the main window you can see the slider *area size*. Try to adjust it. The bigger your piece of paper is, the higher you can set this value.
The slider *epsilon* indicates how straight the contours of the sheet of paper are. If you can't see a a filled piece of paper, raise this value.
*length precision* and *parallel precision* are used to only let squares be captured. If you set the value of these sliders to 0, all objects with 4 edges get detected.

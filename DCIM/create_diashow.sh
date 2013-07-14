#!/bin/bash

cat "$@" | ffmpeg      `: # pipe command line arguments through ffmpeg` \
	   -f image2pipe   `: # file format` \
	   -r 1/15         `: # duration in seconds for each image (here 15 seconds)` \
	   -vcodec mjpeg   `: # select an encoder` \
       -i -            `: # read from stdin` \
	   -r 10           `: # set output frame rate` \
	   -vcodec libx264 `: # select a decoder` \
	   -s 1280x720     `: # set frame size` \
       out.mp4         `: # output file name`

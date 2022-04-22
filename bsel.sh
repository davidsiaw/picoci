#!/bin/bash

sudo stty -F /dev/ttyACM0 1200

echo waiting

while [ ! -b /dev/sda1 ]; do sleep 0.1; done

sleep 0.5

if [ "$*" = "" ]; then echo rebooting; sudo picotool reboot; exit; fi

echo copying

sudo sh upload.sh $1

echo done


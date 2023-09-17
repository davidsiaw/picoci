Skeleton Pi Pico application
=============================

This is a skeleton/example pi pico application. It consists of the bare minimum scripts to make starting programming a Raspberry Pi Pico as trivial as possible.

## Building

To build the example simply run `make`

The Makefile in this directory will automatically list the sources for CMake and then run the compilation in a purpose-built container that contains all the necessary dependencies to build a Pi Pico application.

Simply add sources and headers to the `src` directory.

At least one of the sources must contain a `main` function.

It will output a `main.uf2` file to the `build` folder

## Testing

To test your application write each test in separate `.c` file in the `tests/` folder.

Each test file should specify what source files it needs to link to like this:

```c
/*+test+src/myfile.c*/

#include "myfile.h"
```

See the examples for a fuller example.

Each test must return 0 to be considered passing, and return any other value for failure.

To run your tests simply run `make tests`

All the output from a test goes into a `<testname>.test.result` file in the `test_objs/` folder. You can use that to produce useful logs from your tests.

Tests are unit tests so they do not run on your pico but they are useful for testing functionality. Importing any pico headers or libraries will not work, so you should build interfaces out to pico libraries if you use them from your functions.

## Deploying

Simply run `make deploy`

Caution: this uses the `--privileged` flag on Docker and also assumes that the pi pico will appear as /dev/sda1. If this assumption is wrong and/or you don't trust me or Docker, do the normal RPI Pico way of holding the BOOTSEL button down while re-connecting the Pi Pico, and copy the `build/main.uf2` file obtained by running `make` to the mounted RPI Pico using your local file manager.

## UART connect

Run `make connect`

This assumes `ttyACM0` is the port. It will launch `minicom` for this purpose. In case you are unfamiliar with minicom, to quit press `Ctrl-A` and then `Q` and just say yes.

## What does this example do?

It runs a small program that waits for input on the UART. If it recieves a '1', which you can do like

```
echo -n 1 > /dev/ttyACM0
```

Assuming the PI Pico comes up on that port, and you are on the dialout group, and readwrite is allowed.

```
sudo adduser $USER dialout
sudo chmod a+rw /dev/ttyACM0
```

The LED will light up. Otherwise the LED will turn off. Try it!

You can also just go `make deploy` and press the '1' or '0' keys and see what it does on your Pi Pico!

## Starting out

Check out the repo, and copy the examples folder somewhere and rename it to your application name to start doing RPI Pico stuff!

## Conclusion

Have fun coding!!

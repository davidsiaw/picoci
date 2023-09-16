Skeleton Pi Pico application
=============================

This is a skeleton/example pi pico application. It consists of the bare minimum scripts to make starting programming a Raspberry Pi Pico as trivial as possible.

## Building

To build the example simply run `make`

The Makefile in this directory will automatically list the sources for CMake and then run the compilation in a purpose-built container that contains all the necessary dependencies to build a Pi Pico application.

Simply add sources and headers to the `src` directory.

At least one of the sources must contain a `main` function.

It will output a `main.uf2` file to the `build` folder

## Deploying

Simply run `make deploy`

Caution: this uses the `--privileged` flag on Docker and also assumes that the pi pico will appear as /dev/sda1. If this assumption is wrong and/or you don't trust me or Docker, do the normal RPI Pico way of holding the BOOTSEL button down while re-connecting the Pi Pico, and copy the `build/main.uf2` file obtained by running `make` to the mounted RPI Pico using your local file manager.

## UART connect

Run `make connect`

This assumes `ttyACM0` is the port. It will launch `minicom` for this purpose. In case you are unfamiliar with minicom, to quit press `Ctrl-A` and then `Q` and just say yes.

## Starting out

Check out the repo, and copy the examples folder somewhere and rename it to your application name to start doing RPI Pico stuff!

## Conclusion

Have fun coding!!

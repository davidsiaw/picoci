FROM alpine

ARG USERNAME=user
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Install toolchain
RUN apk update && \
    apk upgrade && \
    apk add git \
            python3 \
            py3-pip \
            cmake \
            build-base \
            libusb-dev \
            bsd-compat-headers \
            newlib-arm-none-eabi \
            gcc-arm-none-eabi \
            g++-arm-none-eabi \
            minicom

# Raspberry Pi Pico SDK
ARG SDK_PATH=/usr/share/pico_sdk
RUN git clone --depth 1 --branch 1.5.1 https://github.com/raspberrypi/pico-sdk $SDK_PATH && \
    cd $SDK_PATH && \
    git submodule update --init

ENV PICO_SDK_PATH=$SDK_PATH

# Picotool installation
RUN git clone --depth 1 --branch 1.1.2 https://github.com/raspberrypi/picotool.git /home/picotool && \
    cd /home/picotool && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    cp /home/picotool/build/picotool /bin/picotool && \
    rm -rf /home/picotool

RUN addgroup -g $USER_GID -S $USERNAME && \
    mkdir -p /src && \
    adduser -S $USERNAME -G $USERNAME -u $USER_GID -h /src && \
    chgrp -R $USERNAME /src && \
    chown -R $USERNAME /src && \
    chmod -R 777 /src

USER $USERNAME
WORKDIR /src


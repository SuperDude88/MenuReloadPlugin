FROM wiiuenv/devkitppc:20220917

ENV PATH=$DEVKITPPC/bin:$PATH

WORKDIR /

# Install wut
RUN git clone https://github.com/devkitPro/wut wut --single-branch && \
    cd wut && \
    git checkout 2c331d22ce5fc82856e9431dad8c872c08430db3 && \
    make -j$(nproc) && \
    make install && \
    cd .. && \
    rm -rf wut

# Install plugin system
RUN git clone https://github.com/wiiu-env/WiiUPluginSystem wups --single-branch && \
    cd wups && \
    git checkout bf8d3005888517c321faf38945ca2ecd36a0e1c5 && \
    make -j$(nproc) && \
    make install && \
    cd .. && \
    rm -rf wups

# Things for building
VOLUME /src
WORKDIR /src

CMD mkdir -p build && \
    cd build && \
    rm -rf * && \
    $DEVKITPRO/portlibs/wiiu/bin/powerpc-eabi-cmake ../ && \
    make

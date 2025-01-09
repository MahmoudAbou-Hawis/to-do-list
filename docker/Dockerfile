FROM ubuntu:22.04
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    && apt-get clean
RUN ln -fs /usr/share/zoneinfo/Europe/London /etc/localtime && \
echo "Europe/London" > /etc/timezone

RUN apt-get update && \
    apt-get install -y \
    build-essential \
    qt5-qmake \
    qtbase5-dev \
    qtchooser \
    qtbase5-dev-tools \
    qtdeclarative5-dev \
    libqt5svg5-dev \
    libqt5x11extras5-dev \
    qtcreator \
    x11-apps \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

    RUN apt-get update && apt-get install -y \
    wget \
    build-essential \
    sudo \
    libssl-dev \
    git

RUN apt-get update && \
    apt-get install -y \
    libx11-xcb1 \
    libxcb-xinerama0 \
    libxcb1 \
    libxrender1 \
    libfontconfig1 \
    libxext6


    RUN wget https://download.oracle.com/berkeley-db/db-18.1.40.tar.gz || true && \
    tar -xvzf db-18.1.40.tar.gz || true && \
    cd db-18.1.40/build_unix || true && \
    ../dist/configure \
        --enable-cxx \
        --enable-stl \
        --with-cryptography=yes \
        --disable-replication \
        --disable-shared \
        --prefix=/usr/local/BerkeleyDB.18.1 || true && \
    make -j$(nproc) || true && \
    sudo make install || true && \
    cd ../../ || true && \
    rm -rf db-18.1.40 db-18.1.40.tar.gz || true

ENV LD_LIBRARY_PATH="/usr/local/BerkeleyDB.18.1/lib"
ENV PATH="/usr/local/BerkeleyDB.18.1/bin:$PATH"
ENV QT_QPA_PLATFORM_PLUGIN_PATH=/usr/lib/qt5/plugins/platforms


RUN rm -rf /app && \
    git clone https://github.com/MahmoudAbou-Hawis/to-do-list.git /app

WORKDIR /app

RUN mkdir build && cd build && cmake .. && make
ENV DISPLAY=:0
CMD ["./build/to-do-list"]
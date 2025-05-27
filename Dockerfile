FROM docker.io/silkeh/clang:17-bookworm AS buildstage1

RUN apt-get update -y && \
    apt-get -y install \
    git \
    wget \
    uuid-dev \
    gdb \
    ninja-build \
    python3 \
    python3-pip \
    python3-venv && \
    pip3 install conan==1.64.1 catboost==1.2.7 --break-system-packages

WORKDIR /app

COPY 0001-test-shap.patch ./

# COPY ./catboost ./catboost
RUN git clone --depth 1 --branch v1.2.7 https://github.com/catboost/catboost.git

WORKDIR /app/catboost

RUN git apply ../0001-test-shap.patch
RUN python3 build/build_native.py --build-root-dir=./build_ --targets catboostmodel --build-type Debug

WORKDIR /app

COPY train.py CMakeLists.txt main.cpp ./

WORKDIR /app/build

RUN cmake .. -DCMAKE_BUILD_TYPE=Debug && \
    make

WORKDIR /app

RUN cp ./build/main ./main

RUN python3 train.py

CMD [ "main" ]
FROM ubuntu:bionic

RUN apt-get update
RUN apt-get -y install apt-transport-https ca-certificates gnupg software-properties-common wget gpg
RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null
RUN apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic main'
RUN apt-get update
RUN apt-get -y install protobuf-compiler protobuf-compiler-grpc git cmake g++
RUN g++ --version
RUN cmake --version

RUN mkdir -p /srv/cloudstate_build/src
WORKDIR /srv/cloudstate_build/src
COPY ./src/cloudstate /srv/cloudstate_build/src/cloudstate
COPY ./src/main.cpp .
COPY ./src/CMakeLists.txt .

# build it
RUN cmake ../src && make

FROM ubuntu:bionic
RUN mkdir -p /srv/cloudstate
WORKDIR /srv/cloudstate
COPY --from=0 /srv/cloudstate_build/src/cloudstate-tck .
EXPOSE 8080
ENV HOST 0.0.0.0
ENV PORT 8080
ENTRYPOINT ["/srv/cloudstate/cloudstate-tck"]
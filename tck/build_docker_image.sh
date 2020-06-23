#!/usr/bin/env bash

export DOCKER_BUILDKIT=1
docker build -t gcr.io/mrcllnz/cloudstate-cpp-tck:latest -f tck/Dockerfile .

#!/usr/bin/env bash

mkdir -p src/cloudstate/proto
protoc -I cloudstate/proto -I cloudstate/proto/protocol --grpc_out=./src/cloudstate/proto/ --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` cloudstate/proto/protocol/cloudstate/entity.proto
protoc -I cloudstate/proto -I cloudstate/proto/protocol --cpp_out=./src/cloudstate/proto/ cloudstate/proto/protocol/cloudstate/entity.proto
protoc -I cloudstate/proto -I cloudstate/proto/protocol --grpc_out=./src/cloudstate/proto/ --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` cloudstate/proto/protocol/cloudstate/event_sourced.proto
protoc -I cloudstate/proto -I cloudstate/proto/protocol --cpp_out=./src/cloudstate/proto/ cloudstate/proto/protocol/cloudstate/event_sourced.proto

protoc -I cloudstate/proto -I cloudstate/proto/protocol --grpc_out=./src/cloudstate/proto/ --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` cloudstate/proto/protocol/cloudstate/function.proto
protoc -I cloudstate/proto -I cloudstate/proto/protocol --grpc_out=./src/cloudstate/proto/ --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` cloudstate/proto/protocol/cloudstate/crdt.proto

protoc -I cloudstate/proto -I cloudstate/proto/protocol --grpc_out=./src/cloudstate/proto/ --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` cloudstate/proto/frontend/cloudstate/entity_key.proto

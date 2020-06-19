#---------------
#protoc.sh
#(c) H.Buchmann 2020
#---------------
#we are in work
PROTOS=${PWD}/../src/proto

FILE=first.proto
PLUGIN=$(which grpc_cpp_plugin)
protoc -I ${PROTOS} --cpp_out=. ${FILE}
protoc -I ${PROTOS} --grpc_out=. --plugin=protoc-gen-grpc=${PLUGIN} ${FILE}


g++ -I. ../src/first-server.cc first.pb.cc first.grpc.pb.cc -lgrpc++ -lprotobuf -o first-server


#------------------------
#Makefile
#(c) H.Buchmann 2020
#------------------------
SRC=${PWD}/../src/
PROTO=${SRC}/proto
vpath %.proto ${PROTO}
vpath %.grpc.pb.h ${PWD}
vpath %.grpc.pb.cc ${PWD}
vpath %.pb.h ${PWD}
vpath %.pb.cc ${PWD}

vpath %.cc ${PWD}/../src/

CXX=g++

PROTOC=protoc
PLUGIN=$(shell which grpc_cpp_plugin)

%.pb.h:		%.proto;${PROTOC} -I ${PROTO} --cpp_out=. ${<}
%.grpc.pb.h:	%.proto;${PROTOC} -I ${PROTO} --grpc_out=. --plugin=protoc-gen-grpc=${PLUGIN}  ${<}

#%.o:	%.cc ${@}.pb.h ${@}.grpc.pb.h;${CXX} -c -I. -I ${PROTO} -I ${SRC} -o ${@} ${<}
#%:	%.o ${@}.pb.o ${@}.grpc.pb.o;${CXX} -o ${@} ${^} -lgrpc++ -lprotobuf


%.o:	%.cc;${CXX} -c -I. -I ${PROTO} -I ${SRC} -o ${@} ${<}
%:	%.o;${CXX} -o ${@} ${^} -lgrpc++ -lprotobuf


first-server.o: first-server.cc first.pb.h first.grpc.pb.h
first-server:	first-server.o first.pb.o first.grpc.pb.o 

first-client.o: first-client.cc first.pb.h first.grpc.pb.h
first-client:	first-client.o first.pb.o first.grpc.pb.o 

//------------------------
//first-service.cc
//(c) H.Buchmann 2020
//------------------------
#include "first.grpc.pb.h"
#include <string>
#include <memory>
#include <grpcpp/server_builder.h>
#include <grpcpp/server.h>
namespace first
{
 class Service final:public Counter::Service
 {
  grpc::Status getCount(grpc::ServerContext* context,
                       const CountRequest* req, CountResponse* resp)
  {
   resp->set_count(100);
   return grpc::Status::OK;
  }
  
 };
}

std::string addr="0.0.0.0:60000";
grpc::ServerBuilder builder;

first::Service service;
int main(int argc,char** args)
{
 builder.AddListeningPort(addr, grpc::InsecureServerCredentials());
 builder.RegisterService(&service);
 std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
 std::cout << "Server listening on " << addr<<"\n";
 server->Wait();
 return 0;
}

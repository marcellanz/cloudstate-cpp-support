//------------------------
//first.cc
//(c) H.Buchmann 2020
//------------------------
#include <string>
#include <memory>
#include <cstring>
#include <grpcpp/server_builder.h>
#include <grpcpp/server.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/channel.h>

#include "first.grpc.pb.h"

namespace first
{
 static const constexpr char PORT[]="60000";
 
 class Service final:public Counter::Service
 {
  public:
   Service();

  private: 
   grpc::Status getCount(grpc::ServerContext* context,
                const CountRequest* req, CountResponse* resp)
   {
    resp->set_count(count++);
    return grpc::Status::OK;
   }
   
   int count=0;
 };

 Service::Service()
 {
  std::unique_ptr<grpc::Server> server(
     grpc::ServerBuilder()
    .AddListeningPort(std::string("0.0.0.0:")+PORT, grpc::InsecureServerCredentials())
    .RegisterService(this)
    .BuildAndStart());
  std::cout<<"Listening on Port "<<PORT<<"\n";
  server->Wait();
 } 
 
 class Client
 {
  public:
   Client(const char ip[]);
 };
 
 Client::Client(const char ip[])
 {
  first::CountRequest   req;
  req.set_id("1234");
  grpc::ClientContext context;
  first::CountResponse  resp;
  auto client=first::Counter::NewStub(grpc::CreateChannel(std::string(ip)+":"+PORT,
                                      grpc::InsecureChannelCredentials()));
  auto status=client->getCount(&context,req,&resp);
  std::cout<<"status="<<status.ok()<<": "
           <<status.error_message()<<"\n"
	   <<"count="<<resp.count()<<"\n";
 }
} //namespace first



static void usage(const char prog[])
{ 
 std::cerr<<"usage "<<prog<<" service | client ip\n"; 
}

int main(int argc,char** args)
{
 switch(argc)
 {
  case 2: //service
  {
   if (std::strcmp("service",args[1])!=0) return 1;
   first::Service service;
  }
  return 0;
  
  case 3: //client
  {
   if (std::strcmp("client",args[1])!=0) return 1;
   first::Client client(args[2]);
  }
  return 0;
 }
 
 usage(args[0]);
 return 2;
}

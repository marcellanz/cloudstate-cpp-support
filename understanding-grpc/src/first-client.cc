//------------------------
//first-client.cc
//(c) H.Buchmann 2020
//------------------------
#include "first.grpc.pb.h"
#include <string>
#include <memory>
#include <grpcpp/create_channel.h>
#include <grpcpp/channel.h>

int main(int argc,char** args)
{
 auto client=first::Counter::NewStub(grpc::CreateChannel("localhost:60000",
                                     grpc::InsecureChannelCredentials()));
 first::CountRequest   req;
 first::CountResponse  resp;
 req.set_id("1234");
 grpc::ClientContext context;
 auto status=client->getCount(&context,req,&resp);
 std::cout<<"status="<<status.ok()<<"\n"
            "'"<<status.error_message()<<"'\n"
	  <<resp.count()<<"\n";
 return 0;
}

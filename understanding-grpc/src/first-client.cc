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
 auto client=Clock::NewStub(grpc::CreateChannel("localhost:60000",
                            grpc::InsecureChannelCredentials()));
 TimeRequest   req;
 TimeResponse  resp;
 req.set_id("1234");
 grpc::ClientContext context;
 auto status=client->getTime(&context,req,&resp);
 std::cout<<"status="<<status.ok()<<"\n"
            "'"<<status.error_message()<<"'\n"
	  <<resp.time()<<"\n";
 return 0;
}

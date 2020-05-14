/*
 *  Copyright 2020 Lightbend Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include <iostream>
#include "cloudstate/proto/protocol/cloudstate/entity.grpc.pb.h"

#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/security/server_credentials.h>

class entity_discovery_service final : public cloudstate::EntityDiscovery::Service {
public:
    entity_discovery_service() {
    }

    ~entity_discovery_service() {
    }

    ::grpc::Status discover(::grpc::ServerContext *context,
                            const ::cloudstate::ProxyInfo *request,
                            ::cloudstate::EntitySpec *response) override {
        std::cout << "Received discovery call from sidecar ["
                  << request->proxy_name()
                  << " v" << request->proxy_version()
                  << "] supporting Cloudstate " << request->protocol_major_version()
                  << "."
                  << request->protocol_minor_version() << std::endl;
        return grpc::Status::OK;
    }

    ::grpc::Status reportError(::grpc::ServerContext *context,
                               const ::cloudstate::UserFunctionError *request,
                               ::google::protobuf::Empty *response) override {
        std::cerr << request->message() << std::endl;
        return grpc::Status::OK;
    }
};

int main() {
    std::string server_address("localhost:8080");
    entity_discovery_service service;
    grpc::ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
    return 0;
}
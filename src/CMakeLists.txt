cmake_minimum_required(VERSION 3.16)
project(${PACKAGE_NAME} LANGUAGES C CXX)

set(PACKAGE_NAME "cloudstate-cpp")
set(PACKAGE_VERSION "0.0.1-dev")
set(CMAKE_CXX_STANDARD 17)

include_directories(cloudstate-cpp PUBLIC cloudstate/proto/)
include(FetchContent)
FetchContent_Declare(
        gRPC
        GIT_REPOSITORY https://github.com/grpc/grpc
        GIT_TAG v1.28.0  # e.g v1.28.0
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(gRPC)

add_executable(cloudstate-tck main.cpp
        cloudstate/proto/protocol/cloudstate/entity.grpc.pb.cc
        cloudstate/proto/protocol/cloudstate/entity.pb.cc
        )

target_link_libraries(cloudstate-tck grpc++)

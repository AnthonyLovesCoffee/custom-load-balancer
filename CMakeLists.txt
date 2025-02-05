cmake_minimum_required(VERSION 3.30)
project(load_balancer)

set(CMAKE_CXX_STANDARD 20)

add_executable(load_balancer main.cpp
        request.cpp
        webserver.cpp
        loadbalancer.h
        loadbalancer.cpp)

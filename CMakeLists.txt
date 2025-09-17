cmake_minimum_required(VERSION 4.1)
project(Tap)

set(CMAKE_CXX_STANDARD 26)

find_package(CURL REQUIRED)

add_executable(Tap main.cpp
        package.h
        manager.h
        remote.h
        manager.cpp
        package.cpp
        remote.cpp)

add_executable(Test test.cpp
        package.h
        manager.h
        remote.h
        manager.cpp
        package.cpp
        remote.cpp)

target_include_directories(Tap PRIVATE ${CURL_INCLUDE_DIRS})

target_link_libraries(Tap PRIVATE CURL::libcurl)

cmake_minimum_required(VERSION 4.1)
project(Tap)

set(CMAKE_CXX_STANDARD 26)

find_package(CURL REQUIRED)
find_package(OpenSSL REQUIRED)

file(GLOB_RECURSE SOURCES src/classes/*.cpp src/classes/*.h)

add_executable(Tap src/main.cpp ${SOURCES})

add_executable(Test src/test.cpp ${SOURCES})

target_include_directories(Tap PRIVATE ${CURL_INCLUDE_DIRS})

target_link_libraries(Tap PRIVATE CURL::libcurl crypto)

#add_executable(Test src/test.cpp ${SOURCES})

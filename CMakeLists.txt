cmake_minimum_required(VERSION 3.2)
project(networkTest)


find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML2 REQUIRED sfml-network>=2.1)


set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        networkTest.cc
        networkTest.h)

add_executable(networkTest ${SOURCE_FILES})

target_link_libraries(networkTest
        ${SFML2_LIBRARIES})

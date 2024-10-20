cmake_minimum_required(VERSION 3.28)

project(algorithms)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CPM)
include(CTest)

set(CATCH2_VERSION    3.7.0)

CPMAddPackage(
    NAME catch2
    VERSION ${CATCH2_VERSION}
    URL https://github.com/catchorg/Catch2/archive/refs/tags/v${CATCH2_VERSION}.tar.gz
    URL_HASH MD5=f0cd2b73baf5e965a2d2430871f2c2cf
)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

add_subdirectory(implementation/cpp/add-two-numbers)
add_subdirectory(implementation/cpp/add-binary)

enable_testing()

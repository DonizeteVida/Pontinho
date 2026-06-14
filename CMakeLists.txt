cmake_minimum_required(VERSION 3.22)
project(Pontinho LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(yoga
    GIT_REPOSITORY https://github.com/react/yoga.git
    GIT_TAG v3.2.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(yoga)

if(ANDROID)
    add_library(pontinho SHARED src/main.cpp)
    target_link_libraries(pontinho PRIVATE SFML::Main)
else()
    add_executable(pontinho src/main.cpp)
endif()

add_subdirectory(assets)
add_subdirectory(widget)

target_link_libraries(
    pontinho 
    PRIVATE
    assets
    widget
    yogacore
    SFML::System
    SFML::Graphics)

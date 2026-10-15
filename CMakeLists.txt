cmake_minimum_required(VERSION 4.3)
project(2436_Fall2026)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

##########"old 2436 content from this semester###############################
FetchContent_Declare(
        2436 #this is the project name in CMakeLists.txt in the repo linked directly below (GIT_REPOSITORY)
        GIT_REPOSITORY https://github.com/setnormTJC/2436
)

FetchContent_MakeAvailable(2436)

###########matplotplusplus########################################################
FetchContent_Declare(
        matplotplusplus
        GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
        GIT_TAG v1.2.2
        GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(matplotplusplus)

# Suppress warnings for the matplot target
#(as of Jul. 17, matplotplusplus has at least one warning that escalates to error)
if(TARGET matplot)
    target_compile_options(matplot PRIVATE -Wno-unused-but-set-variable -Wno-unused-variable)
endif()

###########raylib########################################################
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib
        GIT_TAG 6.2
        GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(raylib)

add_executable(2436_Fall2026 main.cpp
        MyStack.cpp
        MyStack.h
        LinkedList.cpp
        LinkedList.h)

target_link_libraries(2436_Fall2026
    2436 #a repo/project from a class that I teach
    matplot#matplotplusplus
    raylib
)
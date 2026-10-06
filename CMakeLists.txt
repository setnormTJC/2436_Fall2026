cmake_minimum_required(VERSION 4.3)
project(2436_Fall2026)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        2436
        GIT_REPOSITORY https://github.com/setnormTJC/2436
)

FetchContent_MakeAvailable(2436)

#matplotplusplus
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


add_executable(2436_Fall2026 main.cpp
        MyStack.cpp
        MyStack.h
        LinkedList.cpp
        LinkedList.h)

target_link_libraries(2436_Fall2026
    2436
    matplot)
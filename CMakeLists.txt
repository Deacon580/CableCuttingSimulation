cmake_minimum_required(VERSION 3.28)
project(CableCuttingSimulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(CableCuttingSimulation main.cpp
        initCamera.cpp
        initCamera.h
        debugOption.cpp
        debugOption.h
        staticParts.h
        staticParts.cpp
        movingParts.h
        movingParts.cpp
        operationControl.h
        operationControl.cpp
)

target_link_libraries(${PROJECT_NAME} raylib winmm gdi32 opengl32 kernel32)
cmake_minimum_required(VERSION 3.12)
project(Task_2_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task_2_0 main.cpp src/factory.cpp include/factory.h src/objects.cpp include/objects.h include/options.h include/ICreator.h src/TImpl.cpp include/TImpl.h include/exceptions.h include/gradient_descent.h)
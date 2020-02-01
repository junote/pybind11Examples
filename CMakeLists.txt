cmake_minimum_required(VERSION 3.8)

project(pybindExamples)



add_compile_options("-std=c++11")

# set(PYBIND11_CPP_STANDARD -std=c++11)
add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/pybind11)


pybind11_add_module(simpleExample ${CMAKE_SOURCE_DIR}/pybindCpp/simpleExample.cpp)

pybind11_add_module(point ${CMAKE_SOURCE_DIR}/pybindCpp/point.cpp)
pybind11_add_module(pylist ${CMAKE_SOURCE_DIR}/pybindCpp/pylist.cpp)
pybind11_add_module(stl ${CMAKE_SOURCE_DIR}/pybindCpp/STLVectorMap.cpp)
pybind11_add_module(classEnum ${CMAKE_SOURCE_DIR}/pybindCpp/classEnum.cpp)
# pybind11_add_module(exception ${CMAKE_SOURCE_DIR}/pybindCpp/exception.cpp)
pybind11_add_module(smartPointer ${CMAKE_SOURCE_DIR}/pybindCpp/smartPointer.cpp)
pybind11_add_module(callback ${CMAKE_SOURCE_DIR}/pybindCpp/callback.cpp)






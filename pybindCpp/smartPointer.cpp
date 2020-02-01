#include <iostream>
#include <memory>

#include <pybind11/pybind11.h>


struct Point
{
    int x;
    int y;
};

std::unique_ptr<Point> createUniquePtr()
{
    Point p;
    p.x = 4;
    p.y = 4;
    return std::make_unique<Point>(p);
}


PYBIND11_MODULE(smartPointer, m) {
    m.def("createUniquePtr", &createUniquePtr);
}
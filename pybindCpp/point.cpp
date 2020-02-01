#include "pybind11/pybind11.h"

#include <cstdint>
#include <iostream>
#include <memory>

namespace py = pybind11;

struct Point
{
    int x;
    int y;
};

Point* getPoint() {
    Point* dotA = new Point;
    
    dotA->x = 10;
    dotA->y = 20;

    return dotA;

}


void myMemCp(int *a, int aLen, int *b, int bLen)
{
    if (aLen == bLen)
    {
        for( int i = 0; i < aLen; ++i)
            *b++ = *a++;
    } else
    {
        std::cout << "need aLen === bLen";
    }
}


PYBIND11_MODULE(point, m) {

    py::class_<Point>(m, "Point")
        .def_readwrite("x", &Point::x)
        .def_readwrite("y", &Point::y);

    m.def("getPoint", &getPoint);
    // m.def("getPoint", &getPoint, py::return_value_policy::reference);//same

    m.def("myMemCP",[](py::list dataA, py::list dataB){
        // std::cout << dataA.size() << dataB.size() <<std::endl;
        if (dataA.size() == dataB.size())
        {
            // std::unique_ptr<int[]> a(new int[dataA.size()]);
            // std::unique_ptr<int[]> b(new int[dataB.size()]);
            int *a = new int[dataA.size()];
            int *b = new int[dataB.size()];
            const int len = dataA.size();
            // int a[len],b[len];
            for(int i = 0; i < len; ++i)
            {
                a[i] = dataA[i].cast<int>();
                // std::cout << dataA[i].cast<int>() << std::endl;
                std::cout << a[i] << std::endl;
            }
            myMemCp(a,len, b, len);
            py::list data;
            for(int i = 0; i < len; ++i)
            {
                std::cout << b[i] << std::endl;
                data.insert(i, b[i]);
            }
            delete []a;
            delete []b;
            dataB= data;
            return data;
        }
    });

}



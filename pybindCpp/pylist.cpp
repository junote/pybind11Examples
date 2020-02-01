#include "pybind11/pybind11.h"

#include <cstdint>
#include <iostream>
namespace py = pybind11;



int a[] = {1,2,3,4,5};
int b[5];   



PYBIND11_MODULE(pylist, m) {


    m.def("getList", [](){
    py::list data;
    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        data.append(a[i]);
    }

    return data;
    });
    m.def("listGet", [](py::list data){
    // for (py::handle obj : data) {  // iterators!
        // std::cout << "  - " << obj.attr("__str__")().cast<std::string>() << std::endl;
        std::cout << data[0].cast<int>() << std::endl;
    // }
    });
    m.def("getTuple", [](int len){
        py::tuple data(len);
        for (int i = 0; i < len; ++i)
            data[i] = i;
        return data;
    });
}
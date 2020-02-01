
#include "pybind11/pybind11.h"

#include <string>

int add(int a, int b)
{
    return a + b;
}

struct  Pet 
{
    Pet(const std::string &name): name(name){}
    void setName(const std::string &name_){ name = name_;}
    const std::string &getName(){return name;}

    std::string name;
};  


namespace py = pybind11;

PYBIND11_MODULE(simpleExample, m)
{
    m.def("add", &add, "function to add two int");

    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName)
        .def("__repr__", 
            [](const Pet &a)
                {return "simpleExample.Pet named " + a.name;});
    //Exporting variables
    m.attr("num1") = 100;
    py::object world = py::cast("World");
    m.attr("what") = world;
}
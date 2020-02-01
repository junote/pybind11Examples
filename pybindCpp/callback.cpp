#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "pybind11/functional.h"
#include "pybind11/complex.h"
#include "pybind11/chrono.h"

#include <cstdint>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

int dummy_function(int i) { return i + 1; }

namespace py = pybind11;

PYBIND11_MODULE(callback, m) {
    m.def("test_callback1", [](py::object func) { return func(); });
    m.def("test_callback2", [](py::object func) { return func("Hello", 'x', true, 5); });
    // m.def("transform",      [](py::object func){
    //     std::string s("string");
    //     return std::transform(s.begin(), s.end(), s.begin(),func);});
            m.def("dummy_function", &dummy_function);

        m.def("test_dummy_function", [](const std::function<int(int)> &f) -> std::string {
        using fn_type = int (*)(int);
        auto result = f.target<fn_type>();
        if (!result) {
            auto r = f(1);
            return "can't convert to function pointer: eval(1) = " + std::to_string(r);
        } else if (*result == dummy_function) {
            auto r = (*result)(1);
            return "matches dummy_function: eval(1) = " + std::to_string(r);
        } else {
            return "argument does NOT match dummy_function. This should never happen!";
        }
    });

    
}
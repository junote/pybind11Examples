#include<pybind11/stl.h>
#include<vector>
#include<list>
#include<array>
#include<map>
#include<set>



namespace py = pybind11;

std::vector<float> vec_add(std::vector<float>& a, std::vector<float>& b) {

    std::vector<float> out;
    assert(a.size() == b.size());
    for (int i = 0; i < a.size(); i++)
    {
        out.push_back(a[i] + b[i]);
    }

    return out;

}

std::array<float, 20> vec_sin(std::array<float, 20>& x) {
    std::array<float, 20> out;
    for (int i = 0; i < x.size(); i++)
    {
        out[i] = sinf(i);
    }
    return out;
}

std::map<std::string, int> get_map(std::vector<std::string>& keys, std::vector<int> values) {
     
    std::map<std::string, int> out;
    
    for (int i = 0; i < keys.size(); i++)
    {
        out.insert({ keys[i], values[i] });
    }

    return out;
}

std::set<std::string> get_set(std::vector<std::string>& values) {

    std::set<std::string> out;
    for (auto& i:values)
    {
        out.insert(i);
    }

    return out;
}

PYBIND11_MODULE(stl, m) {

    m.doc() = "This is a simple demo using C++ STL";

    m.def("vec_add", &vec_add, py::return_value_policy::reference);
    m.def("vec_sin", &vec_sin, py::return_value_policy::reference);
    m.def("get_map", &get_map, py::return_value_policy::reference);
    m.def("get_set", &get_set, py::return_value_policy::reference);

}

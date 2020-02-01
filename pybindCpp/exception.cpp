#include <exception>
#include <string>
#include "pybind11/pybind11.h"


class MyException : public std::exception {
public:
    explicit MyException(const char * m) : message{m} {}
    virtual const char * what() const noexcept override {return message.c_str();}
private:
    std::string message = "";
};

PYBIND11_MODULE(exception, m) {

        m.def("throw_std_exception", []() {
        throw std::runtime_error("This exception was intentionally thrown.");
    });

    // make a new custom exception and use it as a translation target
    static py::exception<MyException> ex(m, "MyException");
    py::register_exception_translator([](std::exception_ptr p) {
        try {
            if (p) std::rethrow_exception(p);
        } catch (const MyException &e) {
            // Set MyException as the active python error
            ex(e.what());
        }
    });
}
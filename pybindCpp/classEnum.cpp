#include<iostream>
#include<pybind11/pybind11.h>

namespace py = pybind11;

class Person
{

public:
    std::string habbit;             //兴趣爱好

private:
    std::string name;               //姓名
    std::string gender;             //性别
    int age;                        //年龄


public:
    void setName(std::string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setGender(std::string gender) {
        this->gender = gender;
    }



    std::string getName() {
        return this->name;
    }

    std::string getGender() {
        return this->gender;
    }

    int getAge() {
        return this->age;
    }




public:
    //
    static std::string university;
    static std::string getUniversity() {
        return university;
    }

public:
    Person() {};
    Person(std::string name, std::string gender, int age) {
        this->name = name;
        this->gender = gender;
        this->age = age;
    }
    ~Person() {};

};

std::string Person::university = "xidian University";


/*
Teacher类， 继承于Person
*/

class Teacher: public Person
{

private: 
    float salary;
    std::string subject;
    std::string level;
    
public:
    Teacher():Person("xiaoMing", "male", 35)
    {
        this->salary = 5000;
        this->subject = "Math";
        this->level = "Professor";
    };
    ~Teacher() {};

    Teacher(std::string name, std::string gender, int age, float salary, std::string subject, std::string level) {
        this->setName(name);
        this->setAge(age);
        this->setGender(gender);
        this->salary = salary;
        this->subject = subject;
        this->level = level;
    }

public:
    //setter 
    void setSalary(float salary) {
        this->salary = salary;
    }

    void setSubject(std::string subject) {
        this->subject = subject;
    }

    void setLevel(std::string level) {
        this->level = level;
    }

    std::string getSubject() {
        return this->subject;
    }

    float getSalary() {
        return this->salary;
    }

    std::string getLevel() {
        return this->level;
    }

public:
    //重载  overload
    void eat(std::string food) {
        std::cout << this->getName() + " " + "eat" + " " + food << std::endl;
    }

    void eat() {
        std::cout << this->getName() + " " + "eat" + " " + "rice(default)" << std::endl;
    }

    void eat(std::string food, int time) {
        std::cout << this->getName() + " " + "eat" + " " + food + ". At "+ std::to_string(time) + "clock."<< std::endl;
    }

};

enum Items
{
    Chinese = 0,
    Math,
    English,
    Science,
    Bialogy
};



PYBIND11_MODULE(classEnum, m) {

    m.doc() = "Simple Class";
    
    py::class_<Person>(m, "Person")
        .def(py::init())
        .def(py::init<std::string, std::string, int>())
        .def("setName", &Person::setName)
        .def("setAge", &Person::setAge)
        .def("setGender", &Person::setGender)
        .def("getName", &Person::getName)
        .def("getAge", &Person::getAge)
        .def("getGender", &Person::getGender)
        .def_static("getUniversity", &Person::getUniversity)
        .def_readonly_static("university", &Person::university)
        .def_readwrite("habbit", &Person::habbit)
        .def_property("name", &Person::getName, &Person::setName)
        .def_property("age", &Person::getAge, &Person::setAge)
        .def_property("gender", &Person::getGender, &Person::setGender);


    /*
    继承
    class_<子类， 父类>
    */
    py::class_<Teacher, Person>(m, "Teacher")
        .def(py::init())
        .def(py::init<std::string, std::string, int, float, std::string, std::string>())
        .def("setSalary", &Teacher::setSalary)
        .def("setSubject", &Teacher::setSubject)
        .def("setLevel", &Teacher::setLevel)
        .def_property("salary", &Teacher::getSalary, &Teacher::setSalary)
        .def_property("subject", &Teacher::getSubject, &Teacher::setSubject)
        .def_property("level", &Teacher::getLevel, &Teacher::setLevel);
        // .def("eat", py::overload_cast<std::string>(&Teacher::eat))
        // .def("eat", py::overload_cast<std::string, int>(&Teacher::eat))
        // .def("eat", py::overload_cast<>(&Teacher::eat));

    /*
    枚举
    */
    py::enum_<Items>(m, "Items")
        .value("Chinese", Items::Chinese)
        .value("Math", Items::Math)
        .value("English", Items::English)
        .value("Science", Items::Science)
        .value("Bialogy", Items::Bialogy)
        .export_values();

}

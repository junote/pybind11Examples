#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "pybind11/pybind11.h"

class MyMenu{
    public:
        explicit MyMenu(int x):x(x){}
        int addY(int y){return x +y;}
        void menu(int argc, char ** argv);
    private:
        int x;
};

void MyMenu::menu(int argc, char ** argv)
{
    if (argc > 0){
        if (argv[0][0] == 'v'){
            std::cout << "version = 111" << std::endl;
        }else if (argv[0][0] == 'r'){
            std::cout << "x=" << x << std::endl;
        }else if ((argv[0][0] == 'd') & (argv[1][0]=='s')){
            std::cout << "x=" << x << std::endl;
        }else if ((argv[0][0] == 'a')){

            std::cout << "addY=" << x << std::endl;
        }else{
            std::cout << "help" << std::endl;
        }
    }
}

void exec(std::string cmd)
{
    const char separator = ' ';
    pybind11::list inlist;
    std::stringstream streamData(cmd);
    std::string val;
    while (std::getline(streamData, val, separator)) {
        inlist.append(val);
    }

    int argc = (int)inlist.size();
    char** argv = (char**)malloc(argc * sizeof(char*));

    for (int i = 0; i < argc; ++i)
        argv[i] = (char*)PyUnicode_AsUTF8(inlist[i].ptr());

    // for (int i = 0; i < argc; ++i)
    //     fprintf(stderr, "%s\n", argv[i]);

    MyMenu m(10);
    m.menu(argc,argv);

    free(argv);

}

PYBIND11_MODULE(tclmenu, m) {
    m.def("run", &exec, "runs the example");
}


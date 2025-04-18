#ifndef Corepad_H
#define Corepad_H
#include <iostream>
#include <string>
#include <fstream>
std::string text;
std::fstream arquivo;
void make_file(){
    std::cout << "List name for your file : \n" << std::endl;
    std::cin >> text;
    std::string comando = "type nul > " + text;
    system(comando.c_str());

}
std::string value;
void select_get(){
    arquivo.open(text);
    std::cout << "\n List your text for your file : \n" << std::endl;
    getline(std::cin, value);
    arquivo << value;
    arquivo.close();
}
void return_file(){
    system(text.c_str());
}

#endif
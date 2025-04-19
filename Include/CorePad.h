#ifndef corepad_h
#define corepad_h
#include <iostream>
#include <string>
#include <fstream>
std::string text;
std::fstream arquivo;
void make_file(){
    std::cout << "List name for your file : \n";
    std::cin >> text;
    std::string comando = "type nul > " + text;
    system(comando.c_str());
}
std::string value;
void select_file_add(){
    arquivo.open(text);
    getline(std::cin, value);
    arquivo << value;
    arquivo.close();
}
std::string dir;
void return_file(){
    std::cout << "enter your file for view : \n";
    std::cin >> dir;
    system(dir.c_str());
}
std::string rm_file;
void remove_file(){
    std::cout << "enter your name file to remove : \n";
    std::cin >> rm_file;
    std::string value_rm = "del " + rm_file;
    system(value_rm.c_str());
}
void Core_version(){
    std::cout << "\n Version: {1.0}, Last-Varsion: {NoN} \n";
}
void Core_comands(){
    std::cout << "\n { < Core_version(), remove_file(), select_file_add(), make_file() > Now-Version-comands: [1,0] } \n";
}
#endif
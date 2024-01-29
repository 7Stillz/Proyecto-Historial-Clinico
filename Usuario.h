#ifndef USUARIO_H
#define USUARIO_H
#include<iostream>
#include<string>
using namespace std;
class Usuario{
  protected:
    string dni;
    string nombre;
    int edad;
    string userID;
    string password;
  public:
    void menu();
    void login();
    void registration();
    void forgot();
};
#include "Usuario.cpp"
#endif

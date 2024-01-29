#include "Usuario.h"
#include<iostream>
#include<fstream>
#include<string>
#include<locale.h>
using namespace std;
int main(){

  setlocale(LC_ALL, "");
  Usuario u;
  u.menu();
  return 0;
}

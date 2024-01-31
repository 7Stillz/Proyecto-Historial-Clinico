#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;

class Paciente{
  protected:
    string snombre;
    string sdni;
    string fecha_nacimiento;
    int tedad;
    string direccion;
    string genero;
    string telefono;
    string antecedentes_medicos;
  public:
    Paciente(string, string,string, int, string, string, string, string);
    string getNombre();
    string getDNI();
    string getFecha();
    int getEdad();
    string getDireccion();
    string getGenero();
    string getTelefono();
    string getAntecedentes();
    void DATOS();
    void mostrarDatos();
};

Paciente::Paciente(string a, string b, string c, int d, string e, string f, string g, string h){
  snombre = a;
  sdni = b;
  fecha_nacimiento = c;
  tedad = d;
  direccion = e;
  genero = f;
  telefono = g;
  antecedentes_medicos = h;
}
string Paciente::getNombre(){
  return snombre;
}
string Paciente::getDNI(){
  return sdni;
}
string Paciente::getFecha(){
  return fecha_nacimiento;
}
int Paciente::getEdad(){
  return tedad;
}
string Paciente::getDireccion(){
  return direccion;
}
string Paciente::getGenero(){
  return genero;
}
string Paciente::getTelefono(){
  return telefono;
}
string Paciente::getAntecedentes(){
  return antecedentes_medicos;
}
void Paciente::DATOS(){
  ofstream file;
  file.open("datos1.txt", ios::out);
  if(file.is_open()){
    file << snombre << " " << sdni << " " << fecha_nacimiento << " " << tedad << " " << direccion << " " << telefono << " " << antecedentes_medicos << endl;
  }
  else{
    cout << "El archivo no se abrio correctamente";
  }
  file.close();
}
void Paciente::mostrarDatos(){
  string znombre, zdni, zfecha, zdir, gen, ztelf, zantecendentes;
  int zedad;
  ifstream file1;
  file1.open("datos1.txt", ios::in);
  int i = 0;
  if(file1.is_open()){
    while(file1>>znombre>>zdni>>zfecha>>zedad>>zdir>>gen>>ztelf>>zantecendentes){
      cout << "Nombre: " << znombre << "\t";
      cout << "\t"
           << "DNI: " << zdni << "\t";
      cout << "Fecha de Nacimiento: " << zfecha << "\t";
      cout << "Edad: " << zedad << "\t" << endl;
      cout << "Genero: " << gen;
      cout<< "Direccion: " << zdir << "\t";
      cout << "\t"
           << "Telefono: " << ztelf << "\t";
      cout << "\t"
           << "Antecendentes medicos: " << zantecendentes << endl;
      i++;
    }
  }
  else{
    cout << "No se abrio el archivo";
  }
  file1.close();
}


#endif
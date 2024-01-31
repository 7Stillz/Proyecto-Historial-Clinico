#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED

#include <fstream>
#include "Usuario.h"
#include "Paciente.h"
using namespace std;

class Doctor : public Usuario{
  protected:
    Paciente *pPaciente;
    string especialidad;
  public:
    Doctor(string, string, int, string);
    void registro();
    void agregarPaciente();
    void RealizarDiagnostico();
    void hacerRegistro(Paciente *);
    void mostrarDatosDoc();
};
Doctor::Doctor(string pdni, string pnombre, int _edad, string es) : Usuario(pdni, pnombre, _edad){
  especialidad = es;
}

void Doctor::registro(){

  ofstream archivo;
  archivo.open("datos.txt", ios::out | ios::app);
  if(archivo.is_open()){
    archivo << dni << " " << nombre << " " << edad << " " << especialidad << endl;
  }
  else{
    cout<<"No se abrio correctamente el archivo";
  }
  archivo.close();
}
void Doctor::hacerRegistro(Paciente *pP){
  pPaciente = pP;
}
void Doctor::agregarPaciente(){
  menu();
  int opc;
  do{
    cout<<"\t\t\t____________________________________________________________________\n\n\n";
    cout << "\t\t\t                     BIENVENIDO AL SISTEMA                \n\n\n";
    cout << "Escriba 1 para ver el historial clinico (DATOS) del paciente: " << endl;
    cout << "Escriba 2 para agregar el diagnostico del paciente: "<< endl;
    cout << "Escriba 3 para salir" << endl;
    cin >> opc;
    system("cls");
    switch (opc){
      case 1: {
        pPaciente->DATOS();
        string n, d, f, di, t, an;
        int e, encontrado = 0;
        string auxdni;
        cout << "Digite el DNI del paciente: ";
        cin >> auxdni;
        ifstream z;
        z.open("datos1.txt", ios::in);
        if(z.is_open()){
          while(z>>n>>d>>f>>e>>di>>t>>an){
            if(d==auxdni){
              encontrado = 1;
              pPaciente->mostrarDatos();
            }
            if(!encontrado){
              cout<<"No existe el paciente con el dicho dni ingresado";
            }
          }
          break;
        }
        z.close();
      }
      case 2: {
        RealizarDiagnostico();
        break;
      }
      default:
        break;
    }
  } while (opc !=3);
}
void Doctor::RealizarDiagnostico(){
  string diag;
  ofstream i;
  cout << "Escriba el diagnostico del paciente: ";
  cin >> diag;
  i.open("datos2.txt", ios::app);
  if(i.is_open()){
    i << " " << diag;
  }
  else{
    cout << "el archivo no se abrio correctamente";
  }
  i.close();
}
#endif
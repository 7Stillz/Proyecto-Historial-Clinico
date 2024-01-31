#include<iostream>
#include<string>
#include<fstream>
#include "Paciente.h"
#include "Usuario.h"
#include "Doctor.h"
using namespace std;




/*class Consulta{
  protected:
    Paciente *pPaciente;
    Doctor *pDoctor;

  public:
    void DatosPaciente();
    void menu2();
};
void menu2(){
  do{
    cout<<"\t\t\t____________________________________________________________________\n\n\n";
    cout << "\t\t\t                     BIENVENIDO AL SISTEMA                \n\n\n";
    cout << "Escriba 1 para ver el historial clinico del paciente: ";
    cout << "Escriba 2 para agregar el diagnostico del paciente: ";

  }while(opc)
  
}
void DatosPaciente(){*/

int main(){
  
  setlocale(LC_ALL, "");
  Paciente a("Alexis","7673", "12/07/24", 19, "Asoc", "Masculino", "988302786", "Gastritis");
  Doctor u("324324", "Erik", 39, "Cirujano");
  u.registro();
  u.hacerRegistro(&a);
  u.agregarPaciente();
  //u.hacerRegistro(&a);
  //u.agregarPaciente();
  return 0;
}

#include<iostream>
#include<fstream>
#include<string.h>
#include<locale.h>
using namespace std; 
class Usuario{
  protected:
    string DNI;
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
void Usuario::menu(){
		cout<<"\t\t\t____________________________________________________________________\n\n\n";
		cout<<"\t\t\t              BIENVENIDO A LA PAGINA DE INICIO DE SESION            \n\n\n";
		cout<<"\t\t\t____________________________ MENU __________________________________\n\n";
		cout<<"                                                                          \n\n";
		cout<<"\t|  Pulse 1 para INICIAR SESION              |"<<endl;
		cout<<"\t|  Pulse 2 para REGISTRARSE                 |"<<endl;
		cout<<"\t|  Pulse 3 si olvido su CONTRASEÑA          |"<<endl;
		cout<<"\t|  Pulse 4 para SALIR                       |"<<endl;
    int op;
		cout<<"\n\t\t\t Por favor escriba su eleccion: "; cin>>op;
		cout<<endl;
		switch(op){
			case 1:
        	login();
        		break;
			case 2:
        registration();
        break;
			case 3:
        forgot();
        break;
			case 4:
        cout << "\t\t\t Gracias! \n\n";
        break;
			default:
				system("cls");
				cout<<"\t\t\t Por favor seleccione una de las opciones anteriores \n"<<endl;
        menu();
    }
}
void Usuario::login(){
  int count=0;
  string id, pass;
  system("cls");
  cout << "\t\t\t Nombre de usuario: ";
  cin >> userID;
  cout << "\t\t\t Contraseña: ";
  cin >> password;
  ifstream input("DataBase.txt");
  while(input>>id>>pass){
    if(id==userID && pass==password){
      count = 1;
      system("cls");
    }
  }
  input.close();
    if(count==1){
      cout << userID << "\n Ha iniciado sesion correctamente \n";
    }
    else{
      cout << "\n Error en el inicio de sesion \n Compruebe su nombre de usuario y contraseña \n";
      menu();
      }
}
void Usuario::registration(){
  string ruserID, rpassword;
  system("cls");
  cout << "Escriba su Nombre: ";
  cin >> nombre;
  cout << "Escriba su DNI: ";
  cin >> DNI;
  cout << "Escriba su Edad: ";
  cin >> edad;
  cout << "\t\t\t Creé un nombre de usuario: ";
  cin >> ruserID;
  cout << "\t\t\t Creé una contraseña: ";
  cin >> rpassword;
  ofstream f1("DataBase.txt", ios::app);
  f1 << ruserID << ' ' << rpassword <<' '<<nombre<<' '<<DNI<<' '<<edad<<endl;
  system("cls");
  cout << "\n\t\t\t El REGISTRO se ha realizado de correctamente \n";
  menu();
}
void Usuario::forgot() {
  int option;

  system("cls");
  cout << "\t\t\t Has olvidado tu contrase, no te preocupes \n";
  cout << "Presiona 1 para buscar su id por su nombre de usuario ";
  cout << "Presiona 2 para volver al menu ";
  cout << "\t\t\t Ingrese su eleccion: ";
  cin >> option;

  switch (option) {
    case 1: {
      int conts = 0;
      string suserId, sId, spass;
      cout << "\n\t\t\t Ingrese nombre de usuario: ";
      cin >> suserId;

      ifstream f2("DataBase.txt");
      while (f2 >> sId >> spass) {
            if (sId == suserId) {
                conts = 1;
            }
            }
            f2.close();

            if (conts == 1) {
                cout << "\n\n Se encontro su cuenta! \n";
                cout << "\n\n Su contraseña es: " << spass << endl;
                menu();
            } else {
                cout << "\n\t Lo siento no se encontro su cuenta! \n";
                menu();
            }
            break;
        }

        case 2:
            menu();
            break;

        default:
            cout << "\t\t\t Eleccion incorrecta por favor intentelo de nuevo " << endl;
            forgot();
    }
}
int main(){
  setlocale(LC_ALL, "");
  Usuario u;
  u.menu();
  return 0;
}

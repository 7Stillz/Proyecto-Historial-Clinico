#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Usuario{
  protected:
    int opcion;
    string nombre;
  public:
    void menu();
};
void Usuario::menu(){
		cout<<"\t\t\t____________________________________________________________________\n\n\n";
		cout<<"\t\t\t              BIENVENIDO A LA PAGINA DE INICIO DE SESION            \n\n\n";
		cout<<"\t\t\t____________________________ MENU __________________________________\n\n";
		cout<<"                                                                          \n\n";
		cout<<"\t|  Pulse 1 para INICIAR SESION              |"<<endl;
		cout<<"\t|  Pulse 2 para REGISTRARSE                 |"<<endl;
		cout<<"\t|  Pulse 3 si olvido su Password            |"<<endl;
		cout<<"\t|  Pulse 4 para SALIR                       |"<<endl;
    int op;
		cout<<"\n\t\t\t Por favor escriba su eleccion: "; cin>>op;
		cout<<endl;
		switch(op){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
        cout << "\t\t\t Gracias! \n\n";
        break;
			default:
				system("cls");
				cout<<"\t\t\t Por favor seleccione una de las opciones anteriores \n"<<endl;
		}
}

int main(){
  Usuario u;
  u.menu();
  return 0;
}
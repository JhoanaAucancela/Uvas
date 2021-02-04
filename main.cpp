#include <iostream>
#include <fstream>
using namespace std;

float recargo(char tipo,int tam);
void info(float pre_ini, float pre_fin, float k, int tam, char tipo,float precio);

int main() {
  
  float precio_inicial, precio_Final,kilos,precio;
  int tam_Uva;
  char tipo_Uva, res;
  

  cout<<"Ingrese el precio incial por kilo: ";
  cin>>precio_inicial;


  cout<<"Ingrese el numero de kilos: ";
  cin>>kilos;

  cout<<"Ingrese el tipo de Uva [A/B]: ";
  cin>>tipo_Uva;


  cout<<"Ingrese el tamaño de Uva [1/2]: ";
  cin>>tam_Uva;


  precio = recargo(tipo_Uva, tam_Uva);
  
  if(precio!=0) {
    precio_Final = (precio_inicial+precio) * kilos;
    cout<<"La ganancia es: "<<precio_Final;
  }
  else cout<<"Los Datos ingresados son incorrectos";

  info(precio_inicial, precio_Final,kilos,tam_Uva,tipo_Uva,precio);

}


///Recargo
float recargo(char tipo,int tam){
  float precio = 0;

  if (tipo == 'A' or tipo == 'a'){
    if(tam == 1){
      precio =  0.20;
    }
    else if (tam == 2){
      precio =  0.30;
    }
  }

  else if(tipo == 'B' or tipo == 'b'){
    if(tam == 1){
     precio =  0.30;
    }
    else if (tam == 2){
     precio =  0.50;
    }
  }

  return  precio;
}

//Información
void info (float pre_ini, float pre_fin, float k, int tam, char tipo,float precio){

  ofstream archivoUvas;
  string nombrearchivo;
  archivoUvas.open("Uvas.txt", ios::app);
  if(precio!=0) {
    archivoUvas<<"=======================================\n";
    archivoUvas<<"Precio Inicial: "<<pre_ini<<endl;
    archivoUvas<<"Numero de kilos: "<<k<<endl;
    archivoUvas<<"Tamaño de la uva: "<<tam<<endl;
    archivoUvas<<"Tipo de la uva: "<<tipo<<endl;
    archivoUvas<<"Recargo por tamaño y tipo: "<<precio<<endl;
    archivoUvas<<"Ganancia: "<<pre_fin<<endl<<endl;
  }
  else {
    archivoUvas<<"=======================================\n";
    archivoUvas<<"Precio Inicial: "<<pre_ini<<endl;
    archivoUvas<<"Numero de kilos: "<<k<<endl;
    archivoUvas<<"Tamaño de la uva: "<<tam<<endl;
    archivoUvas<<"Tipo de la uva: "<<tipo<<endl;
    archivoUvas<<"Ingreso Datos incorrectos"<<endl<<endl;
  }
  archivoUvas.close();
}
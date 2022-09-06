#include <iostream>
#include <fstream>
using namespace std;

void peso13mil(int n1, int numprod){ //solo ejercicio 1
 // variables, matrices y flujo de datos
  int filas=120;int columnas=4;int x=0;int y=0;int cant=0;string texto;int q=0;
  float matriz[filas][columnas];
  string clientes[8]={};string productos[5]={};

ifstream data("Datos.txt");ifstream Nombres("Nombres.txt");

while(!Nombres.eof()){getline(Nombres,texto);++cant;if (cant>8) {productos[x]=texto;x++;}if (cant>0 && cant<9) {clientes[y]=texto;y++;}}clientes[0]="Bat";

for(int f=0;f<filas;f++){
for(int c=0;c<columnas;c++){data>>matriz[f][c];}}

int suma=0;

for(int f=0;f<filas;f++){
        if(matriz[f][0]==n1 && matriz[f][1]==numprod){
          suma+=matriz[f][2]; // se suma el peso del producto/cliente seleccionado
        }
      }
if (suma>13000) { // si el peso excede los 13000kg se informa en consola, sino, no se devuelve nada
  cout<<'\n'<<clientes[n1]<< ": ["<<productos[numprod]<<"]";
}
}



//-------------------------------------------------------
int main(){
// variables, matrices y flujo de datos
int filas=120;int columnas=4;int x=0;int y=0;int cant=0;string texto;
float matriz[filas][columnas];
string clientes[8]={};string productos[5]={};
ifstream data("Datos.txt");ifstream Nombres("Nombres.txt");
for(int f=0;f<filas;f++){
for(int c=0;c<columnas;c++){data>>matriz[f][c];}}


while(!Nombres.eof()){ //Busqueda de los nombres clientes/productos del .txt para guardarlo en dos vectores distintos
  getline(Nombres,texto);
  ++cant;
    if (cant>8) {
      productos[x]=texto; //productos nombres a guardar en vector productos
      x++;
    }if (cant>0 && cant<9) {
      clientes[y]=texto;y++; //clientes nombres a guardar en vector nombres
    }

  }clientes[0]="Bat"; //tuve que agregar a este cliente forzozamente

for(int x=0;x<8;x++){
  for(int y=0;y<5;y++){
        peso13mil(x,y);   //Ejercicio 1 Resuelto, perdon por como aparece en consola, es por la funcion que la tengo que usar asi
      }
    }



cout<< '\n';

int q=0;
float matriz_dist[5][2];

while (q<5) { //Ejercicio 2
  float dist=0;
  for(int f=0;f<filas;f++){
  for(int c=0;c<columnas;c++){data>>matriz[f][c];}}
  for(int f=0;f<filas;f++){

  if (matriz[f][0]==1 && matriz[f][1]==q) { //arbitrariedad, no busque al cliente, solo lo introduje en base al ejercicio 1

    dist+=matriz[f][3]; //se suman las distancias de cada producto
    matriz_dist[q][0]=dist; //guardo las distancias en columna 0
    matriz_dist[q][1]=q; //guardo el id producto en columna 1
    }
  }
  q++;
}

std::cout << "\n";

//matriz_dist *a ordenar de forma ascedente (columna 0)
/*
      (0)   (1)
(0)   124   0
(1)   74    1
(2)   132   2
(3)   139   3
(4)   131   4

*/

float i,j,aux;
int aux2;

for(int x=0;x<5;x++){ //Ordenamiento de las distancias sin perder su id producto de referencia
  for(int j=0;j<4;j++){
    if (matriz_dist[j][0] > matriz_dist[j+1][0]) {
      aux=matriz_dist[j][0];
      aux2=matriz_dist[j][1];
      matriz_dist[j][0] = matriz_dist[j+1][0];
      matriz_dist[j][1] = matriz_dist[j+1][1];
      matriz_dist[j+1][0]=aux;
      matriz_dist[j+1][1]=aux2;
    }
  }
}

int aux3=0;
for(int x=0;x<5;x++){
  aux3=matriz_dist[x][1];
  cout << productos[aux3] <<" : "<<matriz_dist[x][0]<<" km"<<endl; //ejercicio 2 hecho!
}
//------------------------------------

int ejercicio3=0; //ejercicio 3
for(int f=0;f<filas;f++){
  if (matriz[f][1]==3) { //buscar en todo el Datos.txt todas las veces que aparezca el producto textiles
    ++ejercicio3; //contabilizarlo  y guardarlo
  }
}
cout <<"\n"<<"Cantidad de entregas para : "<<productos[3]<<" son en total : "<<ejercicio3 <<'\n';
//ejercicio 3 hecho!


data.close();
return 0;
}

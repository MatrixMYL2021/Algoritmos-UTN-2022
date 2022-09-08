#include <iostream>
#include <fstream>
using namespace std;

int main(){
// variables, matrices y flujo de datos
int filas=120;int columnas=4;int x=0;int y=0;int cant=0;string texto;
float matriz[filas][columnas];
string clientes[8]={};string productos[5]={};
ifstream data("Datos.txt");ifstream Nombres("Nombres.txt");
for(int f=0;f<filas;f++){
for(int c=0;c<columnas;c++){data>>matriz[f][c];}} //guardado de Datos.txt en "matriz"


while(!Nombres.eof()){ //Busqueda de los nombres clientes/productos del .txt para guardarlo en dos vectores distintos
  getline(Nombres,texto);
  ++cant;
    if (cant>8) {
      productos[x]=texto; //productos nombres a guardar en vector productos
      x++;
    }if (cant>0 && cant<9) {
      clientes[y]=texto;y++; //clientes nombres a guardar en vector nombres
    }

  }clientes[0]="Bat"; //tuve que agregar a este cliente forzadamente en el vector



int masproductos[8]={}; //vector para guardar cant de productos > 13000kg, ordenado del cliente 0 al 7

for(int x=0;x<8;x++){ // int x variable iteradora del id cliente

  int suma=0; //ejercicio 1
  int q3=0; //int q3 iteradora del id producto referencia
  int q4=0; //contabilizador de veces que se repite un producto con mas de 13000kg

  while (q3<5) {
    for(int f=0;f<filas;f++){
      if(matriz[f][0]==x && matriz[f][1]==q3){
        suma+=matriz[f][2];
      }
  }
    if (suma>13000) {
      cout <<clientes[x]<<" : "<<productos[q3]<< '\n';
      suma=0;
      ++q4;
      }
  ++q3;
  suma=0;
  masproductos[x]=q4; //guardado en la matriz
  }
}

// int masproductos[8]={2,4,2,3,2,1,3,2};
//  masproductos[8]={0,1,2,3,4,5,6,7}, su posicion esta enlazada al id cliente


int mayor= masproductos[0];
int dato_for_ejercicio2;

for(int x=0;x<8;x++){if (masproductos[x]>mayor) {mayor=masproductos[x];}} //buscar mayor cant de repeticiones
for(int x=0;x<8;x++){if(mayor==masproductos[x]) {dato_for_ejercicio2=x;}} //buscar posicion id cliente del que tuvo mas cant de repeticiones > 13000kg a usar en el ejercicio 2
//ejercicio 3 hecho!
//-------------------------------------------

cout<< '\n';

int q=0;
float matriz_dist[5][2]; //matriz para guardar las distancias y sus id producto

while (q<5) { //Ejercicio 2
  float dist=0;
  for(int f=0;f<filas;f++){
  for(int c=0;c<columnas;c++){data>>matriz[f][c];}}
  for(int f=0;f<filas;f++){

  if (matriz[f][0]==dato_for_ejercicio2 && matriz[f][1]==q) {

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
} //ejercicio 2 hecho!

int aux3=0;
for(int x=0;x<5;x++){
  aux3=matriz_dist[x][1];
  cout << productos[aux3] <<" : "<<matriz_dist[x][0]<<" km"<<endl; //ejercicio 2 hecho!
}

int dato_for_ej3; //variable para guardar el producto con mas recorrido
for(int x=0;x<5;x++){
  dato_for_ej3=matriz_dist[x][1]; //como matriz_dist en la col 0 esta ordenado de forma ascedente, se da por sentado que su ultimo valor guarda en su posicion col 1 el valor del producto con mas recorrido
}

int ejercicio3=0; //ejercicio 3
for(int f=0;f<filas;f++){
  if (matriz[f][1]==dato_for_ej3) { //buscar en todo el Datos.txt todas las veces que aparezca el producto textiles
    ++ejercicio3; //contabilizarlo  y guardarlo
  }
}
cout <<"\n"<<"Cantidad de entregas para : "<<productos[dato_for_ej3]<<" son en total : "<<ejercicio3 <<'\n';
//ejercicio 3 hecho!


data.close();
return 0;
}

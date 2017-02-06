/*
  Id.Programa: Ejercicio 7
  Autor......: Vladyslav Tokmak
  Fecha......: Febrero-2017
  Comentario.: Busquedo por legajo
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include<iomanip>
using namespace std;

typedef char str20[21];

struct StructDatos {
	int legajo;
	str20 	nombre,
			materia;
};

void ObtDatos(StructDatos &);

int main() {
	FILE *Datos;
	StructDatos sDatos;

	Datos = fopen("Datos.bin","rb");

	int cantidadRegistros;
	int posicion = -1;
	int	principio = 0;
	int numBuscar;
	 
	fseek(Datos,0,SEEK_END);
	
	cantidadRegistros = ftell(Datos) / sizeof(sDatos);
	
	cout<<"La cantidad de registros que posee el archivo es: "<<cantidadRegistros <<endl<<endl;
	
	fseek(Datos,0,SEEK_SET);	
	cout<<"Ingrese numero de legajo que busca: ";
	cin>> numBuscar;
	
	while((posicion == -1) && principio <= cantidadRegistros){
		
		int mitad = (principio + cantidadRegistros)/2;
		fseek(Datos,mitad*sizeof(sDatos),SEEK_SET);
		fread(&sDatos,sizeof(sDatos),1,Datos);
		if(sDatos.legajo == numBuscar)
		{
			posicion = mitad;
		}
		else
		{
			if(numBuscar > sDatos.legajo)
			{
				principio = mitad + 1;
			}
			else{
				cantidadRegistros = mitad - 1;
			}
		}
	}
	if(posicion == -1){
		cout<<"No se pudo encontrar tal legajo"<<endl;
	}
	else{
			cout<<endl<<"El dato se encuentra en la posicion: "<< posicion <<endl<<endl;
			fseek(Datos,posicion*sizeof(sDatos),SEEK_SET);
			cout<< setw(10) << "Legajo" << setw(15) << "Materia" << setw(15) << "Nombre" << endl<<endl;
			cout<< setw(9) << sDatos.legajo << " " << setw(14) << sDatos.materia << " " << setw(14) << sDatos.nombre << endl;
	}
	
	fclose(Datos);
}



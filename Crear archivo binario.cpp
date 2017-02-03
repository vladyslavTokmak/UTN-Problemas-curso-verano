/*
  Id.Programa: Crear archivo binario
  Autor......: Vladyslav Tokmak
  Fecha......: Febrero-2017
  Comentario.: Creacion de archivo de Datos.bin
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>
using namespace std;

typedef char str20[21];

struct StructDatos {
	int cmpClv,
        cmp1;
    float cmp2;
	str20 cmp3;
};

void ObtDatos(StructDatos &);

int main() {
	FILE *Datos;
	StructDatos sDatos;

	Datos = fopen("Datos.bin","wb");

	ObtDatos(sDatos);

	while (sDatos.cmpClv) {
		fwrite(&sDatos,sizeof(sDatos),1,Datos);
		ObtDatos(sDatos);
	}
	fclose(Datos);
}

void ObtDatos(StructDatos &rDatos) {

	cout << "Introdusca el cmpClv (entero). Para finalizar introdusca 0: ";
	cin >> rDatos.cmpClv;
	if (rDatos.cmpClv) {
		do {
			cout << "Cmp1 (entero): ";
			cin >> rDatos.cmp1;
		}
		while (rDatos.cmp1 == 0);
		do {
			cout << "Cmp2 (real): ";
			cin >> rDatos.cmp2;
		}
		while (rDatos.cmp2 == 0);
		do {
			cout << "Cmp3 (cadCar): ";
			cin >> rDatos.cmp3;
		}
		while (strcmp(rDatos.cmp3,"") == 0);
	}
} 


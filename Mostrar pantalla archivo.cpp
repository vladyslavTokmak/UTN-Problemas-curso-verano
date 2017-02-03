/*
    Id.Programa: Mostrar por pantalla archivo bin
    Autor......: Vladyslav Tokmak
    Fecha......: Febrero-2017
    Comentario.: Muestra en pantalla el contenido del archivop binario.
*/

#include <iostream>
#include<iomanip>

using namespace std;

typedef char str20[21];

struct structDatos {
	int cmpClv,
        cmp1;
    float cmp2;
	str20 cmp3;
};

int main() {
	
	FILE *archivoDatos;
	
	structDatos sDatos;
	
	archivoDatos = fopen("Datos.bin","rb");
	
	fseek(archivoDatos,0,SEEK_SET);
	
	cout<< setw(10) << "cmpClv" << setw(10) << "cmp1" << setw(10) << "cmp2" << setw(20) << "cmp3" <<endl<<endl;
	
	while(fread(&sDatos,sizeof(sDatos),1,archivoDatos)){
		
		cout<< setw(9) << sDatos.cmpClv << " " << setw(9) << sDatos.cmp1 << " " << setw(9) << sDatos.cmp2 << " " << setw(20) << sDatos.cmp3 << endl;
		
	}
	return 0;
}

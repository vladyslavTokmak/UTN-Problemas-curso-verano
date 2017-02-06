/*
    Id.Programa: Ejercicio 6
    Autor......: Tokmak Vladyslav
    Fecha......: Fedrero - 2017
    Comentario.: Mostrar una parte del vector ,curso de verano 2017
*/
#include <iostream>
using namespace std;
int main()
{
    int conjunto[21],cont = 0;
    int posInicial,posFinal;
    int i;
    float sumaTotal = 0,promedio = 0;
    do{
        cout << "Ingrese el numero " << cont << ":";
        cin>>conjunto[cont];
        if(conjunto[cont] == 0){
            break;
        }
        cont++;
    }
    while(cont < 20 || conjunto[cont] == 0);
    
    cout << "Ingrese la posicion inical: ";
    cin >> posInicial;
    cout << "Ingrese la posicion final: ";
    cin >> posFinal;
    
    for(i = posInicial; i <= posFinal; i++){
    	cout << "Posicion " << i << ": " << conjunto[i] << endl;
	}
    
}

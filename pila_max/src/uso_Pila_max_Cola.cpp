#include <iostream>
#include "Pila_max_Cola.h"

using namespace std;

int main(){
    Pila_max_Cola p;
    int i;

    for ( i=0; i<=10 ; i++)
      p.poner(i);
  
    while (!p.vacia() ){
        Celda_pila x = p.tope();
        cout << "El valor es: " << x.valor <<endl;
        cout << "El maximo es: " << x.maximo <<endl;
        cout << endl;
        p.quitar();
    }

    return 0;
}

#include <iostream>
#include "Cola_max.h"

using namespace std;

int main(){
    Cola_max c;
    int i;

    for ( i=0; i<=10 ; i++){
      c.poner(i);
    }

    while (!c.vacia()){
        Celda_cola x = c.frente();
        cout << "El valor es: " << x.valor <<endl;
        cout << "El maximo es: " << x.maximo <<endl;
        cout << endl;
        c.quitar();
    }

    return 0;
}
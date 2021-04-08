#include "Cola_max.h"

void Cola_max::actualizar_max(){
    std::stack<Celda_cola> aux(pila1);
    max = aux.top().valor;

    while(!aux.empty()){
        if(aux.top().valor > max)
            max = aux.top().valor;
        aux.pop();
    }

    while(!pila1.empty()){
        Celda_cola c;
        c.valor = pila1.top().valor;
        c.maximo = max;
        aux.push(c);
        pila1.pop();
    }

    while(!aux.empty()){
        pila1.push(aux.top());
        aux.pop();
    }
}

Cola_max::Cola_max(Cola_max & otra){
    pila1 = otra.pila1;
    pila2 = otra.pila2;
    max = otra.max;
}

bool Cola_max::vacia() const{
    return(pila1.empty());
}

void Cola_max::poner(const int elemento){
    Celda_cola c;
    c.valor = elemento;
    if(vacia()){
        max = elemento;
        c.maximo = max;
        pila1.push(c);
    }
    else{
        if(max < elemento)
            max = elemento;

        while(!pila1.empty()){
            pila2.push(pila1.top());
            pila1.pop();
        }

        c.maximo = max;
        pila2.push(c);

        while(!pila2.empty()){
            pila1.push(pila2.top());
            pila2.pop();
        }
    }
    actualizar_max();
}

void Cola_max::quitar(){
    pila1.pop();
    if(!vacia())
        actualizar_max();    
}

Celda_cola Cola_max::frente() const{
    return pila1.top();
}

int Cola_max::num_elementos() const{
    return pila1.size();
}
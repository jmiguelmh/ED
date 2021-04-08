#include <Pila_max_Cola.h>

Pila_max_Cola::Pila_max_Cola(){
    size = 0;
    max = 0;
}

Pila_max_Cola::Pila_max_Cola(const Pila_max_Cola & original){
    cola1 = original.cola1;
    cola2 = original.cola2;
    size = original.size;
    max = original.max;
}

bool Pila_max_Cola::vacia() const{
    return(cola1.vacia());
}

Celda_pila & Pila_max_Cola::tope(){
    return cola1.frente();
}

void Pila_max_Cola::quitar(){
    cola1.quitar();
    size--;

    if(!cola1.vacia())
        max = cola1.frente().maximo;
    else
        max = 0;
}

void Pila_max_Cola::poner(const int & elemento){
    size++;
    Celda_pila c;
    c.valor = elemento;
    
    if(cola1.vacia()){
        max = elemento;
        c.maximo = elemento;
        cola1.poner(c);
        
    }

    else{
        if(elemento > max)
            max = elemento;

        c.maximo = max;
        cola2.poner(c);
        
        while(!cola1.vacia()){
            cola2.poner(cola1.frente());
            cola1.quitar();
        }
        
        std::swap(cola1, cola2);
    }
}

int Pila_max_Cola::num_elementos() const{
    return size;
}
#include <Pila_max_VD.h>

Pila_max_VD::Pila_max_VD(){  
    max = 0;
}

Pila_max_VD::Pila_max_VD(const Pila_max_VD & original){
    v = original.v;
    max = original.max;
}

bool Pila_max_VD::vacia() const{
    return v.empty();
}

Celda_pila & Pila_max_VD::tope(){
    return(v[v.size()-1]);
}

void Pila_max_VD::quitar(){
    if(!v.empty()){
        v.pop_back();
        max = v[v.size()-1].maximo;
    }
}

void Pila_max_VD::poner(const int & elemento){
    Celda_pila c;
    c.valor = elemento;
    
    if(v.empty())
        max = elemento;
    else{
        if(max < elemento)
            max = elemento;
    }
    
    c.maximo = max;
    v.push_back(c);
}

int Pila_max_VD::num_elementos() const{
    return v.size();
}
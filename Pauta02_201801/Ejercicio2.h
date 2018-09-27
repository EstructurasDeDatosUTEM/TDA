#ifndef EJERCICIO2_H_INCLUDED
#define EJERCICIO2_H_INCLUDED

#include "HeapTemplate.h"
typedef HeapTemplate <int>Heap;

float promedio(Heap h, int suma, int cantidad){
    if(h.vacio())
        return suma / cantidad;

    int numero = h.extraer();
    return promedio(h, suma + numero, cantidad+1);
}

float promedio2(Heap h, int suma, int cantidad){
    if(h.vacio()) {
        if(cantidad > 0)
            return suma / cantidad;
        else
            return -1;
    }
    int numero = h.extraer();
    return promedio2(h, suma + numero, cantidad+1);
}

int cantidad(Heap h){
    if(h.vacio())
        return 0;
    h.extraer();
    return cantidad(h) + 1;
}

int suma(Heap h){
    if(h.vacio())
        return 0;
    return h.extraer() + suma(h);
}

float promedio3(Heap h){
    if(cantidad(h) > 0)
        return suma(h) / cantidad(h);
    else
        return -1;
}



void ejercicio2(){
/**2.	Implementar, recursivamente, la función promedio(H, s, n) que devuelve le promedio de los valores contenidos en un heap H no vacío. La invocación inicial es promedio(H, 0, 0).**/

    Heap h;
    h.agregar(1,1);
    h.agregar(2,2);
    h.agregar(3,3);
    h.agregar(4,4);
    h.agregar(5,5);
    h.agregar(5,5);

    cout <<endl<< "Promedio1 "<<promedio(h, 0, 0);
    cout <<endl<< "Promedio2 "<<promedio2(h, 0, 0);
    cout <<endl<< "Promedio3 "<<promedio3(h);
}

#endif // EJERCICIO2_H_INCLUDED



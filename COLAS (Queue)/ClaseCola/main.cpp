using namespace std;

#include <iostream>
#include "ClaseCola.h"

typedef int Tipo;
typedef ClaseCola<Tipo> Cola;
int main() {
    cout << "Colas (Queue)" << endl;

    Cola c;
    c.Agregar(4);
    c.Agregar(5);
    c.Agregar(6);
    c.Agregar(7);


    while (!c.Vacio()){
        cout <<endl <<c.Extraer();
    }
    return 0;
}

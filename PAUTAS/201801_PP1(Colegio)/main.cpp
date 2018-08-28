#include <iostream>

using namespace std;
struct Alumno {
    int edad;
    struct Alumno *link;
};

typedef Alumno *Lista;
typedef Lista Colegio[10];

int SumaEdades(Lista _c) {
    if(_c == NULL)
        return 0;

    int totalEdades = 0;
    Lista centinela = _c;
    do{
        totalEdades += _c->edad;
        _c = _c->link;
    } while (centinela != _c);
    return totalEdades;
}

int CursoMayor(Colegio _colegio, int _n) {
    int sumaMayor = -1, sumaActual =0;
    int posicionMayor = -1;
    for(int i = 0; i<_n; i++){
        sumaActual = SumaEdades(_colegio[i]);
        if(sumaActual > sumaMayor ) {
            sumaMayor = sumaActual;
            posicionMayor = i;
        }
        cout << "revisando "<< i << ":"<<sumaActual<< endl;
    }
    return posicionMayor;
}

int main() {

    Lista L = NULL;

    //primer registro lo trabajamos diferente, lo enlazamos a si mismo
    Lista a= new(Alumno);
    a->edad = 1;
    L = a;
    L->link = L;

    a= new(Alumno);
    a->edad = 2;
    a->link= L->link;
    L->link= a;
    L = a;

    a= new(Alumno);
    a->edad =3;
    a->link= L->link;
    L->link = a;
    L = a;

    a= new(Alumno);
    a->edad =4;
    a->link= L->link;
    L->link = a;
    L = a;

    //ajuste para ver el primero
    L = L->link;
    Lista centinela = L;
    do {
        cout<< endl <<L->edad;
        L = L->link;
    } while (L != centinela);

    cout << endl <<" Total Edades:" <<SumaEdades(L) << endl;

    //ahora creamos un colegio
    Colegio colegio;

    for(int i= 0; i < 10; i++)
        colegio[i] = NULL;

    //primer registro lo trabajamos diferente, lo enlazamos a si mismo
    Lista alumno = new(Alumno);
    alumno->edad = 23;
    colegio[0] = alumno;
    colegio[0]->link = colegio[0];


    alumno = new(Alumno);
    alumno->edad = 25;
    alumno->link = colegio[0]->link;
    colegio[0]->link = alumno;
    colegio[0] = alumno;

    alumno = new(Alumno);
    alumno->edad = 19;
    alumno->link = colegio[0]->link;
    colegio[0]->link = alumno;
    colegio[0] = alumno;

    //primer registro lo trabajamos diferente, lo enlazamos a si mismo
    alumno = new(Alumno);
    alumno->edad = 99;
    colegio[1] = alumno;
    colegio[1]->link = colegio[1];

    alumno = new(Alumno);
    alumno->edad = 24;
    alumno->link = colegio[1]->link;
    colegio[1]->link = alumno;
    colegio[1] = alumno;

    //tercer curso
    Lista curso3 = new (Alumno);
    curso3->edad = 20;
    colegio[3] =curso3;
    colegio[3]->link = colegio[3];



    //Ahora a mostrar
    Lista centinela2 = colegio[0];
    do{
        cout << endl << colegio[0] ->edad;
        colegio[0] = colegio[0]->link;
    } while (colegio[0] != centinela2);

    cout << endl;
    cout << endl << "CursoMayor:" << CursoMayor(colegio, 10);
    return 0;
}


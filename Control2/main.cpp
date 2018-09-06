#include <iostream>

using namespace std;
#include "StackTemplate.h"
#include "ColaTemplate.h"


struct Elemento{
    int coeficiente;
    int exponente;
};

typedef StackTemplate <Elemento>Stack;
typedef ColaTemplate <int>Cola;

int Evalua(Stack S, int x) {
    if(S.empty())
        return 0;
    else {
        int calExp = 1;
        Elemento e = S.pop();
        for(int i = 0; i < e.exponente;i++)
            calExp = x * calExp;

        return e.coeficiente*calExp + Evalua(S, x);
    }
}

void mostrarPolinomio(Stack s){
    while(!s.empty()) {
        Elemento e = s.pop();
        cout <<e.coeficiente <<"X^"<<e.exponente<<" ";
    }
}

int Sumar(Stack &S, int coeficiente, int exponente){
    Stack aux;
    while (!S.empty()) {
        Elemento elemento = S.pop();
        if(elemento.exponente == exponente) {
            elemento.coeficiente = elemento.coeficiente + coeficiente;
        }
        aux.push(elemento);
    }
    //recupero el Stack
    while (!aux.empty())
        S.push(aux.pop());

}

void ejercicio1() {
    Stack P;

    Elemento e1;
    e1.coeficiente = 3;
    e1.exponente = 0;

    Elemento e2;
    e2.coeficiente = -2;
    e2.exponente = 1;

    Elemento e3;
    e3.coeficiente = 1;
    e3.exponente = 2;

    P.push(e1);
    P.push(e2);
    P.push(e3);
    //X2 -2X +2
    cout <<"Mostrar Polimonio"<<endl;
    mostrarPolinomio(P);
    cout <<endl;
    cout <<"Evalua(0)" << Evalua(P, 0) <<endl;
    cout <<"Evalua(2)" << Evalua(P, 2) <<endl;
    cout <<"Evalua(-2)"<< Evalua(P,-2) <<endl;
    cout <<"Evalua(6)" << Evalua(P, 6) <<endl;
    cout <<"Evalua(-6)"<< Evalua(P,-6) <<endl;


    cout <<"Sumar Polimonio"<<endl;
    Sumar(P, 2,1);
    cout <<endl;
    cout <<"Mostrar Polimonio"<<endl;
    mostrarPolinomio(P);
    cout <<endl;
}

/************************************************/

void mostrarCola(Cola c) {
    cout <<"{";
    while(!c.vacio()) {
        cout <<"("<<c.extraer();
        if(!c.vacio())
            cout <<","<< c.extraer()<<")";
        else
            cout << "),"<<endl;
    }
    cout <<"}";
}

void agregarNumFreq(Cola &c, int num, int freq) {
    bool bExiste=false;
    Cola aux;
    int _num    = 0;
    int _freq   = 0;

    while (!c.vacio()) {
        _num =c.extraer();
        if(!c.vacio())
            _freq = c.extraer();

        if(_num == num ) {
            _freq +=  freq;
            bExiste = true;
        }
        if(_freq > 0) {
            aux.agregar(_num);
            aux.agregar(_freq);
        }
    }

    if(bExiste == false && freq > 0) {
        aux.agregar(num);
        aux.agregar(freq);
    }
    //reponemos los valores
    while(!aux.vacio())
        c.agregar(aux.extraer());
}

/*void Cola::agregarNumFreq(int num, int freq) {
    agregar(num);
    agregar(freq);
}*/

void resta(Cola c1, Cola c2, Cola &R){
    int numC1   = 0;
    int freqC1  = 0;
    int numC2   = 0;
    int freqC2  = 0;
    Cola aux;
    bool bNoExiste = true;

    while(!c1.vacio()){
        bNoExiste = true;
        //Primero extraigo el número
        numC1 = c1.extraer();
        //luego extraigo la frecuencia del numero
        if(!c1.vacio())
            freqC1 = c1.extraer();

        while(!c2.vacio()){
            numC2 = c2.extraer(); //numero a restar

            if(!c2.vacio())
                freqC2 = c2.extraer(); //frecuencia a restar

            aux.agregar(numC2);
            aux.agregar(freqC2);

            //si es el mismo numero restamos las frecuencias
            if(numC1 == numC2) {
                if(freqC1-freqC2 > 0) { //Validamos que sea mayor que 0
                    R.agregar(numC1);
                    R.agregar(freqC1-freqC2);
                }
                bNoExiste = false;
            }
        }

        //Restablecemos la cola 2
        while (!aux.vacio())
            c2.agregar(aux.extraer());

        //no encontro su igual en la cola de resta
        if(bNoExiste) {
            R.agregar(numC1);
            R.agregar(freqC1);
        }
    }
}

void ejercicio2Cola(){
    //Ejercicio2
    Cola c1;
    agregarNumFreq(c1, 2,3);
    agregarNumFreq(c1, 5,1);
    agregarNumFreq(c1, 6,12);

    cout<<endl<< "Cola 1: "<<endl;
    mostrarCola(c1);

    Cola c2;
    agregarNumFreq(c2, 2,2);
    agregarNumFreq(c2, 100,6);
    agregarNumFreq(c2, 6,2);

    cout<<endl<< "Cola 2: "<<endl;
    mostrarCola(c2);


    cout<<endl<<"Resta de Colas: "<<endl;
    Cola r;
    resta(c1,c2,r);
    mostrarCola(r);
}

int main() {

    //ejercicio1();
    ejercicio2Cola();

    return 0;
}

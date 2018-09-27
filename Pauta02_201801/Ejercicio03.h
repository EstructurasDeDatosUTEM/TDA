#ifndef EJERCICIO03_H_INCLUDED
#define EJERCICIO03_H_INCLUDED

/**
3.	Se dispone de un ABB cuyos datos son elementos (ver declarativa) utilizando como clave: letra
    typedef struct elemento{
           int cantidad;  //de veces
           char letra;
    };**/

struct Elemento{
    int cantidad; //veces
    char letra;
};

/**a)	La declarativa para implementar un ABB.**/
struct Nodo{
    int key;
    Elemento elemento;
    struct Nodo *izq;
    struct Nodo *der;
};
typedef Nodo *ABB;

/**b)	Escribir la función Insertar(T, e), que permite insertar un elemento e en un ABB T. Si el elemento ya existe sólo deberá aumentar el campo cantidad.**/
void Insertar(ABB &T, Elemento e){
    if(T == NULL) {
        ABB nuevo = new(Nodo);
        nuevo->elemento = e;
        nuevo->key = e.letra;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        T= nuevo;
    } else {
      if(e.letra < T->key)
            Insertar(T->izq, e);
        else
            if(e.letra > T->key)
                Insertar(T->der, e);
            else
                T->elemento.cantidad = T->elemento.cantidad + e.cantidad;
    }
}


/**c)	Escribir la función Mayor( T ), que retorna la cantidad de veces que se encuentra la letra mayor del árbol. Si es vacío retorna -1.**/
int Mayor(ABB T){
    if(T == NULL)
        return -1;

    if(T->der == NULL)
        return T->elemento.cantidad;
    else
        return Mayor(T->der);
}


int Menor(ABB T){
    if(T == NULL)
        return -1;

    if(T->izq == NULL)
        return T->elemento.cantidad;
    else
        return Menor(T->izq);
}
void Preorden(ABB T) {
    if(T != NULL) {
        cout <<endl << T->elemento.letra <<"("<<T->elemento.cantidad<<")";
        Preorden(T->izq);
        Preorden(T->der);
    }
}

void ejercicio3(){
    ABB T = NULL;
    Elemento e;
    e.letra     = 'j';
    e.cantidad  = 10;
    Insertar(T, e);

    e.letra     = 'z';
    e.cantidad  = 4;
    Insertar(T, e);

    e.letra     = 'b';
    e.cantidad  = 6;
    Insertar(T, e);

    e.letra     = 'a';
    e.cantidad  = 1;
    Insertar(T, e);

    Preorden(T);
    cout <<endl<< "Mayor :"<<Mayor(T);
    cout <<endl<< "Menor :"<<Menor(T);
}
#endif // EJERCICIO03_H_INCLUDED

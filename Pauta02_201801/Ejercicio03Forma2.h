#ifndef EJERCICIO03FORMA2_H_INCLUDED
#define EJERCICIO03FORMA2_H_INCLUDED

/**3.Se dispone de un ABB cuyos datos son elementos (ver declarativa) utilizando como clave: letra
    typedef struct elemento{
           int cantidad;  //de veces
           char letra;
    };**/

/**a)	La declarativa para implementar un ABB.**/
struct NodoElemento{
    int cantidad; //veces
    char letra; //key
    struct NodoElemento *izq;
    struct NodoElemento *der;
};
typedef NodoElemento *AB;

/**b)	Escribir la función Insertar(T, e), que permite insertar un elemento e en un ABB T. Si el elemento ya existe sólo deberá aumentar el campo cantidad.**/
void Insertar(AB &T, char _letra, int _cantidad){
    if(T == NULL) {
        AB nuevo       = new(NodoElemento);
        nuevo->letra    = _letra;
        nuevo->cantidad = _cantidad;
        nuevo->izq      = NULL;
        nuevo->der      = NULL;
        T= nuevo;
    } else {
      if(_letra < T->letra)
            Insertar(T->izq, _letra, _cantidad);
        else
            if(_letra > T->letra)
                Insertar(T->der, _letra, _cantidad);
            else
                T->cantidad = T->cantidad + _cantidad;
    }
}


/**c)	Escribir la función Mayor( T ), que retorna la cantidad de veces que se encuentra la letra mayor del árbol (a es menor, z es mayor). Si es vacío retorna -1.**/
int Mayor(AB T){
    if(T == NULL)
        return -1;

    if(T->der == NULL)
        return T->cantidad;
    else
        return Mayor(T->der);
}


int Menor(AB T){
    if(T == NULL)
        return -1;

    if(T->izq == NULL)
        return T->cantidad;
    else
        return Menor(T->izq);
}
void Preorden(AB T) {
    if(T != NULL) {
        cout <<endl << T->letra <<"("<<T->cantidad<<")";
        Preorden(T->izq);
        Preorden(T->der);
    }
}

void ejercicio3Forma2(){
    AB T = NULL;
    cout <<endl<< "Mayor :"<<Mayor(T);
    Insertar(T, 'j', 10);
    Insertar(T, 'z', 4);
    Insertar(T, 'b', 6);
    Insertar(T, 'a', 1);

    Preorden(T);
    cout <<endl<< "Mayor :"<<Mayor(T);
    cout <<endl<< "Menor :"<<Menor(T);
}


#endif // EJERCICIO03FORMA2_H_INCLUDED

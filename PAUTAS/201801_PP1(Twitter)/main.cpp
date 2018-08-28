#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    string texto;
    int cantidadCaracteres;
    string destinatario;
    struct Nodo *link;
};

typedef Nodo *Lista;

void mostrarLista(Lista _l) {
    while(_l != NULL) {
        cout << endl << _l->destinatario <<":"<<_l->texto<<"("<<_l->cantidadCaracteres<<")";
        _l = _l->link;
    }
}

void agregarNodo(Lista L, string texto, string destinatario) {
    if(L==NULL)
        return;

    //lo agregaremos al final de la lista
    while(L != NULL) {
        if((L->link == NULL)&&(L->cantidadCaracteres > 100)) {
            //agrego en nodo
            Lista nuevo = new (Nodo);
            nuevo->texto = texto;
            nuevo->cantidadCaracteres = texto.length();
            nuevo->destinatario = destinatario;
            nuevo->link = NULL;
            L->link = nuevo;
        }
        L = L->link; //avanzamos
    }
}

void agregarNodoR(Lista L, string texto, string destinatario) {
    //lo dejaremos al final pero de forma recursiva
    if(L == NULL)
        return;

    if(L->link != NULL)
        agregarNodoR(L->link, texto, destinatario);

    if((L->link == NULL)&&(L->cantidadCaracteres > 100)) {
            //agrego en nodo
            Lista nuevo = new (Nodo);
            nuevo->texto = texto;
            nuevo->cantidadCaracteres = texto.length();
            nuevo->destinatario = destinatario;
            nuevo->link = NULL;
            L->link = nuevo;
    }
}

int suma(Lista L) {
    int sumaCaracteres = 0;
    while(L != NULL){
        sumaCaracteres += L->cantidadCaracteres;
        L = L->link;
    }
    return sumaCaracteres;
}

int sumaR(Lista L){
    if(L == NULL)
        return 0;
    else {
        return L->cantidadCaracteres + sumaR(L->link);
    }
}

int main()
{
    cout << "CASO TWITTER" << endl;
    Lista L = NULL;

    Lista mensaje = new (Nodo);
    mensaje->texto = "Estoy en prueba, no molestar";
    mensaje->cantidadCaracteres = (mensaje->texto).length();
    mensaje->destinatario = "Amigos de Robotica";
    mensaje->link = L;
    L = mensaje;

    Lista m = new (Nodo);
    m->texto = "Estudie mucho para esta prueba";
    m->cantidadCaracteres = (m->texto).length();
    m->destinatario = "Mis padres";
    m->link = L;
    L = m;

    m = new (Nodo);
    m->texto = "No estudié nada!!!!!! y esta muy difícil";
    m->cantidadCaracteres = (m->texto).length();
    m->destinatario = "Mis compañeros";
    m->link = L;
    L = m;

    //este lo voy a aagregar al final
    Lista aux = L;
    while(aux->link != NULL) {
        //cout<< aux->destinatario<<endl;
        aux = aux->link;
    }
    m = new (Nodo);
    m->texto = "voy a sacarme un 70!!! voy a sacarme un 70!!! voy a sacarme un 70!!! voy a sacarme un 70!!! voy a sacarme un 70!!! voy a sacarme un 70!!! voy a sacarme un 70!!! voy a sacarme un 70!!! voy a sacarme un 70!!! voy a sacarme un 70!!! ";
    m->cantidadCaracteres = (m->texto).length();
    m->destinatario = "Mis compañeros";
    m->link = NULL;
    aux->link = m;


    //agregarNodo(L, "nuevoo", "destinatario 100");
    agregarNodoR(L, "nuevoo", "destinatario 100"); //recursivo


    mostrarLista(L);
    cout <<endl <<"totalCaracteres Recursivo: "<<sumaR(L) << endl;
    cout <<endl <<"totalCaracteres: "<<suma(L) << endl;
    return 0;
}

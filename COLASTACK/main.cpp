#include <iostream>

using namespace std;

#include <queue>
template <class Tipo>
class ClaseCola : private std::queue<Tipo>{
    public:
        ClaseCola();
        virtual ~ClaseCola();
        void Agregar(Tipo _valor);
        Tipo Extraer();
        bool Vacio();
        /*Funciones Miembro*/
        void Reset();
    protected:

    private:
};

template <class Tipo>
ClaseCola<Tipo>::ClaseCola(){};

template <class Tipo>
ClaseCola<Tipo>::~ClaseCola() {};

template <class Tipo>
void ClaseCola<Tipo>::Agregar(Tipo _valor){
   std::queue<Tipo>::push(_valor);
}

template <class Tipo>
Tipo ClaseCola<Tipo>::Extraer(){
    Tipo aux;
    aux = std::queue<Tipo>::front();
    std::queue<Tipo>::pop();
    return aux;
}

template <class Tipo>
bool ClaseCola<Tipo>::Vacio(){
    return std::queue<Tipo>::empty();
}

template <class Tipo>
void ClaseCola<Tipo>::Reset() {
    while(!Vacio())
        Extraer();
};



typedef int Tipo;
typedef ClaseCola<Tipo> Cola;


int main()
{
    Cola c;
    c.Agregar(4);
    c.Agregar(5);
    c.Agregar(6);
    c.Agregar(7);
    //c.Reset();
    cout <<"Mostrar"<<endl;
    mostrar(c);
    cout << "Hello world!" << endl;
    return 0;
}

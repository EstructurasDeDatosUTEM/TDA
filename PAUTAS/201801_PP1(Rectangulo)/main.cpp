#include <iostream>

using namespace std;

class Rectangulo{
public:
    Rectangulo();
    Rectangulo(int _largo, int _ancho);
    Rectangulo(Rectangulo &r);

    void setAncho(int _valor);
    void setLargo(int _valor);
    int getAncho();
    int getLargo();

    int area();
    int perimetro();
private:
    int largo;
    int ancho;
};

Rectangulo::Rectangulo(){
    largo =0;
    ancho =0;
}

Rectangulo::Rectangulo(int _largo, int _ancho){
    largo = _largo;
    ancho = _ancho;
}

Rectangulo::Rectangulo(Rectangulo &r){
    largo = r.largo;
    ancho = r.ancho;
}

void Rectangulo::setAncho(int _valor) {
    ancho = _valor;
}
void Rectangulo::setLargo(int _valor){
    largo = _valor;
}
int Rectangulo::getAncho() {
    return ancho;
}
int Rectangulo::getLargo() {
    return largo;
}


int Rectangulo::area() {
    return (largo * ancho);
}
int Rectangulo::perimetro() {
    return (largo*2 + ancho*2);
}

int mayorArea(Rectangulo a[], int _n){
    int _mayorArea = 0;
    for(int i=0;i< _n; i++) {
        if(a[i].area() > _mayorArea)
            _mayorArea = a[i].area();
    }
    return _mayorArea;
}


int main()
{
    Rectangulo r(10,5);
    cout <<endl <<r.area()<<endl;

    Rectangulo estructura[100];

    estructura[0] = Rectangulo(10,6);
    estructura[1] = Rectangulo(1,4);
    estructura[2] = Rectangulo(14,24);
    cout <<endl<< "MayorArea:" << mayorArea(estructura, 3);
    //mas datos
    cout <<endl<< "Area[0]:" << estructura[0].area();
    cout <<endl<< "Area[1]:" << estructura[1].area();
    cout <<endl<< "Area[3]:" << estructura[3].area();
    cout <<endl<< "Area[4]:" << estructura[0].area();

    cout << "" << endl;
    return 0;
}

#ifndef EJERCICIO01_H_INCLUDED
#define EJERCICIO01_H_INCLUDED


#include "ColaTemplate.h"
#include "StackTemplate.h"

/**a)	Escribir la declarativa necesaria para representar la información del colegio.**/

struct Informe{
    string titulo;
    int numeroPaginas;
};
typedef StackTemplate <Informe>Alumno;
typedef ColaTemplate <Alumno>Colegio;


/**b)	Escribir la función recursiva SumaPáginas(S), que retorna la suma total de todas las páginas de los informes que lleva un alumno S.**/
int SumaPaginas(Alumno s){
    if(s.empty())
        return 0;
    Informe temp = s.pop();

    return temp.numeroPaginas + SumaPaginas(s);
}

/**c)	Escribir la función Titulo(C), que retorna el título del aquel informe que posea mayor cantidad de páginas, entre todos los alumnos del colegio C..**/
string Titulo(Colegio c) {
    Informe informeMayor;
    informeMayor.titulo="Sin datos";
    informeMayor.numeroPaginas=0;

    while(!c.vacio()){
        Alumno tempAlumno = c.extraer();
        while(!tempAlumno.empty()) {
            Informe tempInforme = tempAlumno.pop();
            if(tempInforme.numeroPaginas > informeMayor.numeroPaginas)
                informeMayor = tempInforme;
        }
    }
    return informeMayor.titulo;
}

int ejercicio1() {
    /*
    1.	En un colegio se ha dispuesto de una cola de alumnos, que son atendidos por orden de llegada.
        Cada alumno lleva una pila de informes, en donde se considera por informe: número de páginas y título.
        a)	Escribir la declarativa necesaria para representar la información del colegio.
        b)	Escribir la función recursiva SumaPáginas(S), que retorna la suma total de todas las páginas de los informes que lleva un alumno S.
        c)	Escribir la función Titulo(C), que retorna el título del aquel informe que posea mayor cantidad de páginas, entre todos los alumnos del colegio C..
    */
    Colegio colegio;
    Alumno alumno;
    Informe informe;

    informe.titulo ="Estructuras de Datos en C++";
    informe.numeroPaginas = 300;
    alumno.push(informe);

    informe.titulo ="Quimica Analítica";
    informe.numeroPaginas = 450;
    alumno.push(informe);

    informe.titulo ="Programación C";
    informe.numeroPaginas = 124;
    alumno.push(informe);

    colegio.agregar(alumno);

    cout <<endl<<"Suma Páginas: " << SumaPaginas(alumno);
    cout <<endl<<"Titulo Mayor: " << Titulo(colegio);
    return 0;
}



#endif // EJERCICIO01_H_INCLUDED

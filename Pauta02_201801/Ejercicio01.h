#ifndef EJERCICIO01_H_INCLUDED
#define EJERCICIO01_H_INCLUDED


#include "ColaTemplate.h"
#include "StackTemplate.h"

/**a)	Escribir la declarativa necesaria para representar la informaci�n del colegio.**/

struct Informe{
    string titulo;
    int numeroPaginas;
};
typedef StackTemplate <Informe>Alumno;
typedef ColaTemplate <Alumno>Colegio;


/**b)	Escribir la funci�n recursiva SumaP�ginas(S), que retorna la suma total de todas las p�ginas de los informes que lleva un alumno S.**/
int SumaPaginas(Alumno s){
    if(s.empty())
        return 0;
    Informe temp = s.pop();

    return temp.numeroPaginas + SumaPaginas(s);
}

/**c)	Escribir la funci�n Titulo(C), que retorna el t�tulo del aquel informe que posea mayor cantidad de p�ginas, entre todos los alumnos del colegio C..**/
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
        Cada alumno lleva una pila de informes, en donde se considera por informe: n�mero de p�ginas y t�tulo.
        a)	Escribir la declarativa necesaria para representar la informaci�n del colegio.
        b)	Escribir la funci�n recursiva SumaP�ginas(S), que retorna la suma total de todas las p�ginas de los informes que lleva un alumno S.
        c)	Escribir la funci�n Titulo(C), que retorna el t�tulo del aquel informe que posea mayor cantidad de p�ginas, entre todos los alumnos del colegio C..
    */
    Colegio colegio;
    Alumno alumno;
    Informe informe;

    informe.titulo ="Estructuras de Datos en C++";
    informe.numeroPaginas = 300;
    alumno.push(informe);

    informe.titulo ="Quimica Anal�tica";
    informe.numeroPaginas = 450;
    alumno.push(informe);

    informe.titulo ="Programaci�n C";
    informe.numeroPaginas = 124;
    alumno.push(informe);

    colegio.agregar(alumno);

    cout <<endl<<"Suma P�ginas: " << SumaPaginas(alumno);
    cout <<endl<<"Titulo Mayor: " << Titulo(colegio);
    return 0;
}



#endif // EJERCICIO01_H_INCLUDED

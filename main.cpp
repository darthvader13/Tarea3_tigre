#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{

    ofstream MiArchivo(nombre_archivo.c_str(),ios::in | ios::binary);
    MiArchivo.seekp( posicion*10);
    MiArchivo.write(mascota->nombre.c_str(),6);
    MiArchivo.write((char *) &mascota->edad,4);
    MiArchivo.close();

}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{
    Mascota *m;
    ifstream MiArchivo(nombre_archivo.c_str());
    MiArchivo.seekg(posicion*10);
    char nombre[6];
    int edad;
    MiArchivo.read(nombre,6);
    MiArchivo.read((char*)&edad,4);
    m=  new Mascota(edad,nombre);
    return m;
}

//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo)
{
    vector<Mascota*>respuesta;
    Mascota *m ;
    ifstream MiArchivo(nombre_archivo.c_str());
    MiArchivo.seekg(0,MiArchivo.end);
    int tam = MiArchivo.tellg()/10;
    MiArchivo.seekg(0,MiArchivo.beg);

    for(int i =0 ; i< tam; i++)
    {
        char nombre[6];
        int edad;
        MiArchivo.read(nombre,6);
        MiArchivo.read((char*)&edad,4);
        m = new Mascota(edad,nombre);
        respuesta.push_back(m);
    }
    return respuesta;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

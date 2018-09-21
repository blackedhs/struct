#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
typedef struct {
    int ID;
    char video[15];
    char cuit[10];
    int dias;
    int idPantalla;
    int isEmpty;
}Contratacion;

int con_inicializarArray(Contratacion* pBuffer,int limite);
int con_borrarPorID(Contratacion* pBuffer,int limite,int id);
int con_obtenerID();
int contratarPublicidad(Contratacion* pBuffer,int indice);
int con_buscarIndiceVacio(Contratacion* pBuffer,int limite,int*indice);

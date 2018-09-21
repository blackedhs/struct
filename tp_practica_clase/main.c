#include <stdio.h>
#include <stdlib.h>
#include  "pantalla.h"
#include "utn.h"
#include "contrataciones.h"
#define CANTIDAD_PANTALLAS 100
#define CANTIDAD_CONTRATACIONES 1000
int menu(int*opcion);
int main()
{
    Pantalla pantallas[CANTIDAD_PANTALLAS];
    Contratacion contrataciones [CANTIDAD_CONTRATACIONES];
    int indiceVacio;
    int opcion;
    int ID;
    pan_inicializarArray(pantallas,CANTIDAD_PANTALLAS);
    con_inicializarArray(contrataciones,CANTIDAD_CONTRATACIONES);
    do{
        menu(&opcion);
        switch (opcion){
            case 1:
                if(pan_buscarIndiceVacio(pantallas,CANTIDAD_PANTALLAS,&indiceVacio)==0){
                    pan_altaPantalla(pantallas,indiceVacio);
                }else {
                    printf("No hay mas espacio");
                }
                break;
            case 2:
                if(utn_getEntero(&ID,3,"Ingrese el ID de la pantalla a modificar","Error Intente nuevamente",0,999)==0&&
                    pan_busquedaPorID(pantallas,CANTIDAD_PANTALLAS,ID,&indiceVacio)==0){
                        pan_modificarPantallaPorIndice(pantallas,indiceVacio);
                }else{
                    printf("El ID ingresado no es valido");
                }
                break;
            case 3:
                if(utn_getEntero(&ID,3,"Ingrese el ID de la pantalla a modificar","Error Intente nuevamente",0,999)==0&&
                pan_busquedaPorID(pantallas,CANTIDAD_PANTALLAS,ID,&indiceVacio)==0){
                    pan_borrarPorIndice(pantallas,indiceVacio);
                    con_borrarPorID(contrataciones,CANTIDAD_CONTRATACIONES,ID);
                }
                break;
            case 9:
                pan_imprimirListaPantalla(pantallas,CANTIDAD_PANTALLAS);
                getchar();
                getchar();
                system("clear");
                break;
            case 5:

                break;
        }
    }while(opcion!=11);
    return 0;
}
int menu(int*opcion){
    int aux;
        system("clear");
        printf("1- Alta de pantalla\n");
        printf("2- Modificar datos de pantalla\n");
        printf("3- Borrar Pantalla\n");
        printf("4- Contratar publicidad\n");
        printf("5- Modificar condiciones de publicacion\n");
        printf("6- Cancelar contratacion\n");
        printf("7- Consultar Facturacion\n");
        printf("8- Listar contrataciones\n");
        printf("9- Listar pantallas\n");
        printf("10-Informar\n");
        printf("11- Salir\n");
        utn_getEntero(&aux,10,"Ingrese una opcion","Error Ingrese Una Opcion Valida",1,11);
        *opcion=aux;
    return 0;
}
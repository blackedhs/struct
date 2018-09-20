#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#define CANTIDAD 200
int main()
{
    int indice;
    int opcion;
    Producto productos[CANTIDAD];
    inicializarArray(productos,CANTIDAD);
    do{
        menuProductos(&opcion);
        switch(opcion){
            case 1:
                  buscarIndiceVacio(productos,CANTIDAD,&indice);
                  printf("\nIndice : %d",indice);
                  cargaProducto(productos,indice);
                  break;
            case 2:
                imprimirArray(productos,CANTIDAD);
                break;
        }
    }while(opcion!=3);

    return 0;
}

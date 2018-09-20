#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#define CANTIDAD 200
int main()
{
    int indice;
    int opcion;
    int ID;
    int indiceID;
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
                getchar();
                getchar();
                break;
            case 3:
                if(utn_getEntero(&ID,3,"Ingrese el ID del producto: ","Error intente nuevamente :",-1,CANTIDAD)==0){
                    if(busquedaPorID(productos,CANTIDAD,ID,&indiceID)==0){
                        modificarProductoPorIndice(productos,indiceID);
                    }else{
                    printf("No existe ningun producto con el ID ingresado\n");
                    getchar();
                    getchar();
                    }
                }
                break;
            case 4:
                if(utn_getEntero(&ID,3,"Ingrese el ID del producto: ","Error intente nuevamente :",-1,CANTIDAD)==0){
                    if(busquedaPorID(productos,CANTIDAD,ID,&indiceID)==0){
                        borrarPorID(productos,indiceID);
                    }else{
                    printf("No existe ningun producto con el ID ingresado\n");
                    getchar();
                    getchar();
                    }
                }
                break;
        }
    }while(opcion!=5);

    return 0;
}

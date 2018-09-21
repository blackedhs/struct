#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "contrataciones.h"
int con_inicializarArray(Contratacion* pBuffer,int limite){
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i].isEmpty=1;
    }
    return 0;
}
int con_borrarPorID(Contratacion* pBuffer,int limite,int id){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==0&& pBuffer[i].ID==id){
            pBuffer[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}
int con_contratarPublicidad(Contratacion* pBuffer,int indice,int id){
    pBuffer[indice].ID=con_obtenerID();
    pBuffer[indice].isEmpty=0;
    pBuffer[indice].idPantalla=id;
    printf("Ingrese el nombre del video\n");
    getString(pBuffer[indice].video,15);
    printf("Ingrese el cuit\n");
    getString(pBuffer[indice].cuit,10);
    utn_getEntero(&pBuffer[indice].dias,3,"Ingrese la cantidad de dias","Error Ingrese una cantidad de dias validos",1,200);
    return 0;
}
int con_obtenerID(){
    static int ID=0;
    return ID++;
}
int con_buscarIndiceVacio(Contratacion* pBuffer,int limite,int*indice){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==1){
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

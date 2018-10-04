#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"
#include "informar.h"

int informar_conMayorMenorTo(Contratacion* pBufferCon,int limiteCon,Pantalla* pBufferPan,int limitePan,int valorComparar,int flag){
    int retorno=-1;
    int i,j;
    float auxTotal;
    Pantalla auxPan;
    if(pBufferCon!=NULL && pBufferPan!= NULL && limiteCon>0&&limitePan>0){
        retorno=0;
        for(i=0;i<limiteCon;i++){
            if((flag==0 && pBufferCon[i].dias<valorComparar)||
            (flag==1 && pBufferCon[i].dias>valorComparar)){
                for(j=0;j<limitePan;j++){
                    if(pBufferCon[i].idPantalla == pBufferPan[j].idPantalla){
                        auxPan=pBufferPan[j];
                        break;
                    }
                }
                auxTotal=(pBufferCon[i].dias)*(auxPan.precio);
                printf("\nNombre: %s Precio: %.2f Dias: %d Total: %2.f",auxPan.nombre,auxPan.precio,pBufferCon[i].dias,auxTotal);
            }
        }
    }
    return retorno;
}
int informar_panPromedio(Pantalla* pBuffer,int limite){
    int i;
    float acumulador=0;
    int cantidad=0;
    float  promedio;
    for(i=0;i<limite;i++) {
        if(pBuffer[i].isEmpty==0){
            acumulador+=pBuffer[i].precio;
            cantidad++;
        }
    }
    promedio=acumulador/cantidad;
    return promedio;
}
int informar_panMayorOrMenorPrecioTo(Pantalla* pBuffer,int limite,int valorAcomparar,int flag){
    int retorno=-1;
    int i;
    if(pBuffer!=NULL&&limite>0&&(flag==0||flag==1)){
        retorno=0;
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==0&&((flag==0 &&pBuffer[i].precio<=valorAcomparar)||
            (flag==1&&pBuffer[i].precio>=valorAcomparar))){
                printf("[RELEASE] - %d - %s - %.2f\n",pBuffer[i].idPantalla, pBuffer[i].nombre, pBuffer[i].precio);
            }
        }
    }
    return retorno;
}
int informar_ordenarbyPrecioOrName(Pantalla* pBuffer,int limite){
    int i;
    int flagOrden=1;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        while(flagOrden==1){
            flagOrden=0;
            for(i=0;i<(limite-1);i++){
                if(pBuffer[i].precio<pBuffer[i+1].precio||
                (pBuffer[i].precio==pBuffer[i+1].precio&&
                strcmp(pBuffer[i].nombre,pBuffer[i+1].nombre)>0)){
                        flagOrden=1;
                        retorno=0;
                        pan_swap(pBuffer,i,i+1);

                }
            }
        }
    }
    return retorno;
}
int pan_swap(Pantalla* pBuffer,int indiceDestino,int indiceOrigen){
    Pantalla aux[1];
    if(pBuffer!=NULL && indiceDestino!=indiceOrigen){
        strcpy(aux[0].direccion,pBuffer[indiceDestino].direccion);
        strcpy(aux[0].nombre,pBuffer[indiceDestino].nombre);
        aux[0].precio=pBuffer[indiceDestino].precio;
        aux[0].tipo=pBuffer[indiceDestino].tipo;
        aux[0].idPantalla=pBuffer[indiceDestino].idPantalla;
        aux[0].isEmpty=pBuffer[indiceDestino].isEmpty;

        strcpy(pBuffer[indiceDestino].direccion,pBuffer[indiceOrigen].direccion);
        strcpy(pBuffer[indiceDestino].nombre,pBuffer[indiceOrigen].nombre);
        pBuffer[indiceDestino].precio=pBuffer[indiceOrigen].precio;
        pBuffer[indiceDestino].tipo=pBuffer[indiceOrigen].tipo;
        pBuffer[indiceDestino].idPantalla=pBuffer[indiceOrigen].idPantalla;
        pBuffer[indiceDestino].isEmpty=pBuffer[indiceOrigen].isEmpty;

        strcpy(pBuffer[indiceOrigen].direccion,aux[0].direccion);
        strcpy(pBuffer[indiceOrigen].nombre,aux[0].nombre);
        pBuffer[indiceOrigen].precio=aux[0].precio;
        pBuffer[indiceOrigen].tipo=aux[0].tipo;
        pBuffer[indiceOrigen].idPantalla=aux[0].idPantalla;
        pBuffer[indiceOrigen].isEmpty=aux[0].isEmpty;
    }
    return 0;
}

int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;


    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}

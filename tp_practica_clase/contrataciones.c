#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "contrataciones.h"

static int con_buscarIndiceVacio(Contratacion* pBuffer,int limite,int*indice);
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
int con_contratarPublicidad(Contratacion* pBuffer,int id,int limite){
    int indice;
    if(con_buscarIndiceVacio(pBuffer,limite,&indice)==0){
        pBuffer[indice].ID=con_obtenerID();
        pBuffer[indice].isEmpty=0;
        pBuffer[indice].idPantalla=id;
        utn_getLetrasYNumeros(pBuffer[indice].video,15,"\nIngrese el nombre del video: ");
        utn_getLetrasYNumeros(pBuffer[indice].cuit,10,"\nIngrese el CUIT: ");
        utn_getEntero(&pBuffer[indice].dias,3,"\nIngrese la cantidad de dias: ","\nError Ingrese una cantidad de dias validos",1,200);
    }
    return 0;
}
int con_obtenerID(){
    static int ID=0;
    return ID++;
}
static int con_buscarIndiceVacio(Contratacion* pBuffer,int limite,int*indice){
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
int con_imprimirPorCuit(Contratacion* pBuffer,int limite,char* cuit){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0&&cuit!=NULL){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==0&&strcmp(pBuffer[i].cuit,cuit)==0){
                retorno=0;
                printf("\nID: %d",pBuffer[i].ID);
                printf("\tID Pantalla: %d",pBuffer[i].idPantalla);
                printf("\tDias: %d",pBuffer[i].dias);
                printf("\tVideo: %s",pBuffer[i].video);
            }
        }
    }
    return retorno;
}
int con_modificarPorIdPantalla(Contratacion* pBuffer,int limite,int idPantalla){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for (i=0;i<limite;i++){
            if(pBuffer[i].idPantalla==idPantalla&& pBuffer[i].isEmpty==0){
                retorno=0;
                utn_getEntero(&pBuffer[i].dias,3,"\nIngrese la cantidad de dias: ","\nError Ingrese una cantidad de dias validos",1,200);
            }
        }
    }
    return retorno;
}
int con_cancelarById(Contratacion* pBuffer,int limite,int idPantalla){
    int i;
    int retorno=-1;
        if(pBuffer!=NULL&&limite>0){
            for(i=0;i<limite;i++){
                if(pBuffer[i].idPantalla==idPantalla&& pBuffer[i].isEmpty==0){
                    retorno=0;
                    pBuffer[i].isEmpty=1;
                }
            }
        }
    return retorno;
}

int con_listarImportePorContratacion(Contratacion* pBufferCon,Pantalla* pBufferPan,int limiteCon,char* cuit,int limitePan){
    int i,j;
    int retorno=-1;
    float aux;
    if(pBufferCon!=NULL&&pBufferPan!=NULL&&limiteCon>0&&cuit!=NULL&&limitePan>0){
        for(i=0;i<limiteCon;i++){
            if(strcmp(pBufferCon[i].cuit,cuit)==0&&pBufferCon[i].isEmpty==0){
                for(j=0;j<limitePan;j++){
                    if(pBufferPan[j].ID==pBufferCon[i].idPantalla&& pBufferPan[j].isEmpty==0){
                        aux=pBufferPan[j].precio * pBufferCon[i].dias;
                        printf("\nID: %d",pBufferCon[i].ID);
                        printf("\tCuit: %s",pBufferCon[i].cuit);
                        printf("\tID Pantalla: %d",pBufferCon[i].idPantalla);
                        printf("\tVideo %s",pBufferCon[i].video);
                        printf("\tDias: %d",pBufferCon[i].dias);
                        printf("\tPrecio/dia: %.2f",pBufferPan[j].precio);
                        printf("\tTotal: %.2f",aux);
                        retorno=0;
                    }
                }
            }
        }
    }
    return retorno;
}

int con_imprimirContrataciones(Contratacion* pBuffer,int limite){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==0){
                retorno=0;
                printf("\nID: %d",pBuffer[i].ID);
                printf("\tID Pantalla: %d",pBuffer[i].idPantalla);
                printf("\tCuit: %s",pBuffer[i].cuit);
                printf("\tVideo %s",pBuffer[i].video);
                printf("\tDias: %d",pBuffer[i].dias);
            }
        }
    }
    return retorno;
}
int con_ordenarByCuit(Contratacion* pBuffer,int limite,int upOrDonw){
    int i=0;
    int retorno=-1;
    int flag=1;
    int limiteOrdenado;
    if(pBuffer!=NULL&&limite>0&&(upOrDonw==0||upOrDonw==1)){
        retorno=0;
        limiteOrdenado=con_agruparPosiciones(pBuffer,limite);
        while(flag==1){
            flag=0;
            for(i=0;i<(limiteOrdenado-1);i++){
                if((upOrDonw==0 && strcmp(pBuffer[i].cuit,pBuffer[i+1].cuit)<0)||
                    (upOrDonw==1 && strcmp(pBuffer[i].cuit,pBuffer[i+1].cuit)>0)){
                        flag=1;
                        con_intercambiarPocionEstructura(pBuffer,i,i+1);
                }
            }
        }
    }
    return retorno;
}
int con_intercambiarPocionEstructura(Contratacion* pBuffer,int indiceDestino,int indiceOrigen){
    Contratacion aux[1];
    if(pBuffer!=NULL && indiceDestino!=indiceOrigen){
        strcpy(aux[0].cuit,pBuffer[indiceDestino].cuit);
        strcpy(aux[0].video,pBuffer[indiceDestino].video);
        aux[0].dias=pBuffer[indiceDestino].dias;
        aux[0].ID=pBuffer[indiceDestino].ID;
        aux[0].idPantalla=pBuffer[indiceDestino].idPantalla;
        aux[0].isEmpty=pBuffer[indiceDestino].isEmpty;

        strcpy(pBuffer[indiceDestino].cuit,pBuffer[indiceOrigen].cuit);
        strcpy(pBuffer[indiceDestino].video,pBuffer[indiceOrigen].video);
        pBuffer[indiceDestino].dias=pBuffer[indiceOrigen].dias;
        pBuffer[indiceDestino].ID=pBuffer[indiceOrigen].ID;
        pBuffer[indiceDestino].idPantalla=pBuffer[indiceOrigen].idPantalla;
        pBuffer[indiceDestino].isEmpty=pBuffer[indiceOrigen].isEmpty;

        strcpy(pBuffer[indiceOrigen].cuit,aux[0].cuit);
        strcpy(pBuffer[indiceOrigen].video,aux[0].video);
        pBuffer[indiceOrigen].dias=aux[0].dias;
        pBuffer[indiceOrigen].ID=aux[0].ID;
        pBuffer[indiceOrigen].idPantalla=aux[0].idPantalla;
        pBuffer[indiceOrigen].isEmpty=aux[0].isEmpty;
    }
    return 0;
}
int con_agruparPosiciones(Contratacion* pBuffer,int limite){
    int i;
    int j=0;
    if (pBuffer!=NULL && limite>0){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==0){
                con_intercambiarPocionEstructura(pBuffer,j,i);
                j++;
            }
        }
    }
    return j;
}
int con_ingresoForzado(Contratacion* pBuffer,int limite,char* video,char* cuit,int dias,int idPantalla){
    int aux;
    con_buscarIndiceVacio(pBuffer,limite,&aux);
    strcpy(pBuffer[aux].video,video);
    strcpy(pBuffer[aux].cuit,cuit);
    pBuffer[aux].dias=dias;
    pBuffer[aux].idPantalla=idPantalla;
    pBuffer[aux].isEmpty=0;
    pBuffer[aux].ID=con_obtenerID();
    return 0;
}
int con_listarClientesEImportes(Contratacion * pBufferCon,Pantalla* pbufferPan,int limiteCon,int limitePan){
    int i,j;
    int retorno=-1;
    int auxCantidadContratada=0;
    float contador=0;
    float max;
    float auxPrecio;
    char auxcuit[10];
    char clienteMax[10];
    if(pBufferCon!=NULL && limiteCon>0&& pbufferPan!=NULL&& limitePan>0){
        retorno=0;
        for(i=0;i<limiteCon;i++){
            if(pBufferCon[i].isEmpty==1){
                break;
            }
            for(j=0;j<limitePan;j++){
                if(pBufferCon[i].isEmpty==0 &&pBufferCon[i].idPantalla==pbufferPan[j].ID){
                    auxPrecio=pBufferCon[i].dias*pbufferPan[j].precio;
                    if(i==0){
                        max=auxPrecio;
                        strcpy(clienteMax,pBufferCon[i].cuit);
                        contador=auxPrecio;
                        strcpy(auxcuit,pBufferCon[i].cuit);
                        auxCantidadContratada++;
                        printf("\nID: %d",pBufferCon[i].ID);
                        printf("\tCuit: %s",pBufferCon[i].cuit);
                        printf("\tID Pantalla: %d",pBufferCon[i].idPantalla);
                        printf("\tVideo %s",pBufferCon[i].video);
                        printf("\tDias: %d",pBufferCon[i].dias);
                        printf("\tPrecio/dia: %.2f",pbufferPan[j].precio);
                        printf("\tTotal: %.2f",auxPrecio);
                    }else if(strcmp(auxcuit,pBufferCon[i].cuit)==0){
                        contador+=auxPrecio;
                         if(contador>max){
                            max=contador;
                            strcpy(clienteMax,pBufferCon[i].cuit);
                        }
                        auxCantidadContratada++;
                        printf("\nID: %d",pBufferCon[i].ID);
                        printf("\tCuit: %s",pBufferCon[i].cuit);
                        printf("\tID Pantalla: %d",pBufferCon[i].idPantalla);
                        printf("\tVideo %s",pBufferCon[i].video);
                        printf("\tDias: %d",pBufferCon[i].dias);
                        printf("\tPrecio/dia: %.2f",pbufferPan[j].precio);
                        printf("\tTotal: %.2f",auxPrecio);
                    }else{
                        printf("\nCantidad contrada: %d \t total: %.2f",auxCantidadContratada,contador);
                        if(contador>max){
                            max=contador;
                            strcpy(clienteMax,pBufferCon[i].cuit);
                        }
                        auxCantidadContratada=1;
                        strcpy(auxcuit,pBufferCon[i].cuit);
                        printf("\nID: %d",pBufferCon[i].ID);
                        printf("\tCuit: %s",pBufferCon[i].cuit);
                        printf("\tID Pantalla: %d",pBufferCon[i].idPantalla);
                        printf("\tVideo %s",pBufferCon[i].video);
                        printf("\tDias: %d",pBufferCon[i].dias);
                        printf("\tPrecio/dia: %.2f",pbufferPan[j].precio);
                        printf("\tTotal: %.2f",auxPrecio);
                        contador=+auxPrecio;
                    }
                    break;
                }
            }
        }
        printf("\nCantidad contrada: %d \t total: %.2f",auxCantidadContratada,contador);
        printf("\nEl valor maximo a facturar es: %.2f con el cuit: %s",max,clienteMax);
    }
    return retorno;
}

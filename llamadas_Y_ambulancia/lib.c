#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "lib.h"
static int lla_IdNew();
static int aso_IdNew();

int lla_inicializarArray(Llamada* pBuffer,int limite){
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i].isEmpty=1;
    }
    return 0;
}
int aso_inicializarArray(Asociado* pBuffer,int limite){
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i].isEmpty=1;
    }
    return 0;
}
int aso_altaAsociado(Asociado* pBuffer,int limite){
    int indice;
    if(aso_buscarIndiceVacio(pBuffer,limite,&indice)==0){
        pBuffer[indice].id=aso_IdNew();
        pBuffer[indice].isEmpty=0;
        utn_getLetras(pBuffer[indice].nombre,15,3,"\nIngrese el nombre : ","\nError..Vuelva a intentar");
        utn_getLetras(pBuffer[indice].apellido,15,3,"\nIngrese el apellido : ","\nError..Vuelva a intentar");
        utn_getEntero(&pBuffer[indice].dni,10,"\nIngrese el dni: ","\nError..Ingrese un dni valido",90000,99999999);
    }
    return 0;
}
int aso_buscarIndiceVacio(Asociado* pBuffer,int limite,int*indice){
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
int aso_modificarbyId(Asociado* pBuffer,int limite,int id){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for (i=0;i<limite;i++){
            if(pBuffer[i].id==id&& pBuffer[i].isEmpty==0){
                retorno=0;
                utn_getLetras(pBuffer[i].nombre,15,3,"\nIngrese el nombre : ","\nError..Vuelva a intentar");
                utn_getLetras(pBuffer[i].apellido,15,3,"\nIngrese el apellido : ","\nError..Vuelva a intentar");
            }
        }
    }
    return retorno;
}
int aso_bajaById(Asociado* pBuffer,int limite,int id){
    int i;
    int retorno=-1;
        if(pBuffer!=NULL&&limite>0){
            for(i=0;i<limite;i++){
                if(pBuffer[i].id==id&& pBuffer[i].isEmpty==0){
                    retorno=0;
                    pBuffer[i].isEmpty=1;
                }
            }
        }
    return retorno;
}
static int aso_IdNew(){
    static int i=0;
    return i++;
}
static int lla_IdNew(){
    static int j=0;
    return j++;
}
int lla_nuevaLlamada(Llamada* pBuffer,int limite){
    int indice;
    if(lla_buscarIndiceVacio(pBuffer,limite,&indice)==0){
        pBuffer[indice].id=lla_IdNew();
        pBuffer[indice].isEmpty=0;
        utn_getEntero(&pBuffer[indice].idAsociado,10,"\nIngrese el Id Asociado: ","\nError..Ingrese un id valido",0,100);
        printf("\nMotivos:\n1-INFARTO\t2-ACV\t3-GRIPE");
        utn_getEntero(&pBuffer[indice].motivo,3,"\nIngrese una opcion: ","\nError...Opcion invalida",1,3);
        pBuffer[indice].estado=PENDIENTE;
    }
    return 0;
}
int lla_buscarIndiceVacio(Llamada* pBuffer,int limite,int*indice){
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
int lla_asignarAmbulancia(Llamada* pbuffer,int limite,int id){
    int retorno=-1;
    int i;
    if(pbuffer!=NULL && limite>0){
        for(i=0;i<limite;i++){
            if(pbuffer[i].id==id){
                utn_getEntero(&pbuffer[i].idAmbulancia,3,"\nIngrese el Id de la ambulancia: ","\nError..Ingrese un id valido",0,999);
                utn_getEntero(&pbuffer[i].tiempoInsumido,3,"\nIngrese el tiempo Insumido(minutos) : ","\nEror..Ingrese un tiempo valido",0,99);
                pbuffer[i].estado=CUMPLIDO;
                retorno=0;
            }
        }
    }
    return retorno;
}
int lla_ordenarById(Llamada* pBuffer,int limite,int upOrDonw){
    int i=0;
    int retorno=-1;
    int flag=1;
    int limiteOrdenado;
    if(pBuffer!=NULL&&limite>0&&(upOrDonw==0||upOrDonw==1)){
        retorno=0;
        limiteOrdenado=lla_agruparPosiciones(pBuffer,limite);
        while(flag==1){
            flag=0;
            for(i=0;i<(limiteOrdenado-1);i++){
                if((upOrDonw==0 && pBuffer[i].id<pBuffer[i+1].id)||
                    (upOrDonw==1 && pBuffer[i].id>pBuffer[i+1].id)){
                        flag=1;
                        lla_intercambiarPocionEstructura(pBuffer,i,i+1);
                }
            }
        }
    }
    return retorno;
}
int mayorLlamadasRealizadas(Asociado* pbufferAso,Llamada* pbufferLla, int limiteAso,int limiteLla){
    int i;
    int cantidadLlamadas=0;
    int maximasLlamadas=0;
    int idMaximo;

    if( pbufferAso!=NULL&&pbufferLla!=NULL &&limiteAso>0&&limiteLla>0){
        for(i=0;i<limiteLla;i++){
            if(i==0){
                cantidadLlamadas++;
                maximasLlamadas++;
                idMaximo=pbufferLla[i].idAsociado;
            }else if(pbufferLla[i].idAsociado==pbufferLla[i-1].idAsociado){
                cantidadLlamadas++;
                if(cantidadLlamadas>maximasLlamadas){
                    maximasLlamadas=cantidadLlamadas;
                    idMaximo=pbufferLla[i].idAsociado;
                }
            }else{
                if(cantidadLlamadas>maximasLlamadas){
                    maximasLlamadas=cantidadLlamadas;
                    idMaximo=pbufferLla[i].idAsociado;
                }
                cantidadLlamadas=1;
            }
        }
    }
    for(i=0;i<limiteAso;i++){
        if(pbufferAso[i].id==idMaximo){
            printf("Mas llamadas realizadas por: %s %s",pbufferAso[i].nombre,pbufferAso[i].apellido);
            break;
        }
    }
    return 0;
}
int lla_agruparPosiciones(Llamada* pBuffer,int limite){
    int i;
    int j=0;
    if (pBuffer!=NULL && limite>0){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==0){
                lla_intercambiarPocionEstructura(pBuffer,j,i);
                j++;
            }
        }
    }
    return j;
}
int lla_intercambiarPocionEstructura(Llamada* pBuffer,int indiceDestino,int indiceOrigen){
    Llamada aux[1];
    if(pBuffer!=NULL && indiceDestino!=indiceOrigen){
        aux[0].estado=pBuffer[indiceDestino].estado;
        aux[0].id=pBuffer[indiceDestino].id;
        aux[0].idAmbulancia=pBuffer[indiceDestino].idAmbulancia;
        aux[0].idAsociado=pBuffer[indiceDestino].idAsociado;
        aux[0].tiempoInsumido=pBuffer[indiceDestino].tiempoInsumido;
        aux[0].motivo=pBuffer[indiceDestino].motivo;
        aux[0].isEmpty=pBuffer[indiceDestino].isEmpty;

        pBuffer[indiceDestino].estado=pBuffer[indiceOrigen].estado;
        pBuffer[indiceDestino].id=pBuffer[indiceOrigen].id;
        pBuffer[indiceDestino].idAmbulancia=pBuffer[indiceOrigen].idAmbulancia;
        pBuffer[indiceDestino].isEmpty=pBuffer[indiceOrigen].isEmpty;
        pBuffer[indiceDestino].idAsociado=pBuffer[indiceOrigen].idAsociado;
        pBuffer[indiceDestino].tiempoInsumido=pBuffer[indiceOrigen].tiempoInsumido;
        pBuffer[indiceDestino].motivo=pBuffer[indiceOrigen].motivo;

        pBuffer[indiceOrigen].estado=aux[0].estado;
        pBuffer[indiceOrigen].id=aux[0].id;
        pBuffer[indiceOrigen].idAmbulancia=aux[0].idAmbulancia;
        pBuffer[indiceOrigen].isEmpty=aux[0].isEmpty;
        pBuffer[indiceOrigen].idAsociado=aux[0].idAsociado;
        pBuffer[indiceOrigen].tiempoInsumido=aux[0].tiempoInsumido;
        pBuffer[indiceOrigen].motivo=aux[0].motivo;
    }
    return 0;
}

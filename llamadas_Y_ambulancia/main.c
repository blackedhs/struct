#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "utn.h"
#define CANTIDADLLAMADAS 100
#define CANTIDADASOCIADOS 100
int menu(int* opcion);
int main()
{
    Llamada llamadas[CANTIDADLLAMADAS];
    Asociado asociados[CANTIDADASOCIADOS];
    int opcion;
    int auxId;
    lla_inicializarArray(llamadas,CANTIDADLLAMADAS);
    aso_inicializarArray(asociados,CANTIDADASOCIADOS);
    do{
        system("clear");
        menu(&opcion);
        switch (opcion){
            case 1:
                aso_altaAsociado(asociados,CANTIDADASOCIADOS);
                break;
            case 2:
                utn_getEntero(&auxId,3,"\nIngrese el Id del Asociado a modificar:","\nError...Ingrese un numero valido",-1,900);
                 if(aso_modificarbyId(asociados,CANTIDADASOCIADOS,auxId)!=0){
                    printf("\nEl id ingresado no se encuentra en el sistema....");
                    getchar();
                 }
                 break;
            case 3:
                utn_getEntero(&auxId,3,"\nIngrese el Id del Asociado a modificar:","\nError...Ingrese un numero valido",-1,900);
                if(aso_bajaById(asociados,CANTIDADASOCIADOS,auxId)!=0){
                    printf("\nEl id ingresado no se encuentra en el sistema....");
                    getchar();
                }
                break;
            case 4:
                lla_nuevaLlamada(llamadas,CANTIDADLLAMADAS);
                break;
            case 5:
                utn_getEntero(&auxId,3,"\nIngrese el Id de llamada: ","\nError...Ingrese un numero valido",-1,900);
                if(lla_asignarAmbulancia(llamadas,CANTIDADASOCIADOS,auxId)!=0){
                    printf("\nEl id ingresado no se encuentra en el sistema....");
                    getchar();
                }
                break;
            case 6:
                lla_ordenarById(llamadas,CANTIDADLLAMADAS,1);
                mayorLlamadasRealizadas(asociados,llamadas,CANTIDADASOCIADOS,CANTIDADLLAMADAS);
                break;

        }

    }while(opcion!=7);

    return 0;
}
int menu(int* opcion){
    printf("\n1-ALTA DEL ASOCIADO\n2-MODIFICAR DATOS DEL ASOCIADO\
\n3-BAJA DE ASOCIADO\n4-NUEVA LLAMADA\n5-ASIGNAR AMBULANCIA\n6-INFORMAR\n7-SALIR");
    utn_getEntero(opcion,3,"\nIngrese una opcion","\nErro...Intente nuevamente",1,7);
    return 0;
}

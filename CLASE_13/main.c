#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "Contratacion.h"
#include "informar.h"

#define QTY 10
#define LEN_CONT    1000

/*

A. Realizar un solo listado de las pantallas ordenadas por los siguientes criterios:
   o Precio (descendentemente)
   o Nombre (ascendentemente)

B.  Todas las pantallas que su valor es menor o igual a 10.

C.  Todas las pantallas que su valor es mayor a 10.

D.  Todas las pantallas que superan el promedio de los precios.

E.  Todas las pantallas que no superan el promedio de los precios.

F.  Todas las contrataciones cuya cantidad de dias es menor o igual a 10,
    indicando nombre de la pantalla contratada, precio unitario, dias y precio total de la contratacion

G.  Listado de clientes en el cual se indique la cantidad de contrataciones que ha realizado
    y por que importe. Ordenado por los siguientes criterios:
        o Importe (descendentemente)
        o Cuit (ascendentemente)

H. La o las pantallas con mas contrataciones.

I. La o las pantallas con mas clientes.

J. La o las pantallas que mas ha facturado.

K. La o las pantallas que han facturado mas que el promedio.

*/



int main()
{
    Pantalla array[QTY];
    Contratacion contrataciones[LEN_CONT];
    int menu;
    int auxiliarId;

    pantalla_init(array,QTY);
    cont_init(contrataciones,LEN_CONT);

    pantalla_altaForzada(array,QTY,"Wilde","Las Flores 50",5000,0);
    pantalla_altaForzada(array,QTY,"Avellaneda","Belgrano 250",2000,0);
    pantalla_altaForzada(array,QTY,"Bernal","Cerrito 300",3000,0);
    pantalla_altaForzada(array,QTY,"Quilmes","Lavalle 450",1000,1);
    pantalla_altaForzada(array,QTY,"Berazategui","Mitre 150",5000,1);

    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video.avi","20911911915",100);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video1.avi","20911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,0,"video2.avi","30911911915",300);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video3.avi","30911911915",400);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video4.avi","40911911915",500);
    cont_altaForzada(contrataciones,LEN_CONT,array,QTY,2,"video5.avi","40911911915",600);

    informar_ConsultaFacturacion(contrataciones,LEN_CONT,array,QTY,"20911911915");
    informar_ListarContrataciones(contrataciones,LEN_CONT,array,QTY);
    informar_ListarCantidadContratacionesImporte(contrataciones,LEN_CONT,array,QTY);


    do
    {
        getValidInt("\n\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n7.Contratar\\\
n8.Listado de pantallas ordenadas\n9.Pantallas menor a 1000\n10.Pantallas mayores a 1000\\\
\n11.Pantallas mayores al promedio\n12.Pantallas menores al promedio\n13.punto f\n14.punto G\n15.Salir\n","\nNo valida\n",&menu,1,15,1);
        switch(menu)
        {
            case 1:
                pantalla_alta(array,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_baja(array,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_modificacion(array,QTY,auxiliarId);
                break;
            case 4:
                pantalla_mostrar(array,QTY);
                cont_mostrar(contrataciones,LEN_CONT);
                break;
            case 5:
                cont_ordenarCuit(contrataciones,LEN_CONT,0);
                pantalla_ordenar(array,QTY,0);
                break;
            case 6:
                pantalla_mostrarDebug(array,QTY);

                break;
            case 7:
                cont_alta(contrataciones,LEN_CONT,array,QTY);
                break;
            case 8:
                informar_ordenarbyPrecioOrName(array,QTY);
                pantalla_mostrar(array,QTY);
                break;
            case 9:
                informar_panMayorOrMenorPrecioTo(array,QTY,1000,1);
                break;
            case 10:
                informar_panMayorOrMenorPrecioTo(array,QTY,1000,0);
                break;
            case 11:
                informar_panMayorOrMenorPrecioTo(array,QTY,informar_panPromedio(array,QTY),1);
                break;
            case 12:
                informar_panMayorOrMenorPrecioTo(array,QTY,informar_panPromedio(array,QTY),0);
                break;
            case 13:
                informar_conMayorMenorTo(contrataciones,LEN_CONT,array,QTY,10,1);
                break;
        }

    }while(menu != 15);

    return 0;
}

#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#define PENDIENTE 1
#define CUMPLIDO 0
#define INFARTO 1
#define ACV 2
#define GRIPE 3
typedef struct{
    int id;
    int dni;
    char nombre[15];
    char apellido[15];
    int edad;
    int isEmpty;
}Asociado;
typedef struct{
    int id;
    int motivo;
    int estado;
    int idAsociado;
    int idAmbulancia;
    int tiempoInsumido;
    int isEmpty;
}Llamada;
int aso_inicializarArray(Asociado* pBuffer,int limite);
int lla_inicializarArray(Llamada* pBuffer,int limite);
int aso_buscarIndiceVacio(Asociado* pBuffer,int limite,int*indice);
int aso_altaAsociado(Asociado* pBuffer,int limite);
int aso_modificarbyId(Asociado* pBuffer,int limite,int id);
int aso_bajaById(Asociado* pBuffer,int limite,int id);
int lla_buscarIndiceVacio(Llamada* pBuffer,int limite,int*indice);
int lla_nuevaLlamada(Llamada* pBuffer,int limite);
int lla_asignarAmbulancia(Llamada* pbuffer,int limite,int id);
int lla_agruparPosiciones(Llamada* pBuffer,int limite);
int lla_ordenarById(Llamada* pBuffer,int limite,int upOrDonw);
int lla_intercambiarPocionEstructura(Llamada* pBuffer,int indiceDestino,int indiceOrigen);
int mayorLlamadasRealizadas(Asociado* pbufferAso,Llamada* pbufferLla, int limiteAso,int limiteLla);
#endif // LIB_H_INCLUDED

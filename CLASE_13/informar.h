int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);
int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);
int informar_ordenarbyPrecioOrName(Pantalla* pBuffer,int limite);
int pan_swap(Pantalla* pBuffer,int indiceDestino,int indiceOrigen);
int informar_panMayorOrMenorPrecioTo(Pantalla* pBuffer,int limite,int valorAcomparar,int flag);
int informar_panPromedio(Pantalla* pBuffer,int limite);
int informar_conMayorMenorTo(Contratacion* pBufferCon,int limiteCon,Pantalla* pBufferPan,int limitePan,int valorComparar,int flag);

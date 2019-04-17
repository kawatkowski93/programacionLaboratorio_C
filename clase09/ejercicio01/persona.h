typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    char descripcion[31];
}eNacion;

typedef struct{
    char apellido[31];
    char nombre[31];
    int edad;
    int isEmpty;
    int idUnico;
    eFecha fechaNac;
    int idNacionalidad;
}ePersona;

void altaPersona(ePersona persona[],int cantidad);//UN ARRAY DE STRUCT
void mostrarTodoPersona(ePersona persona[],int cantidad);
void mostrarPersona(ePersona persona);
void inicializarEstado(ePersona persona[],int cantidad);
void ordenar(ePersona persona[],int cantidad);
//FUNCION MODIFICAR submenu y DAR DE BAJA//BUSCAR POR DNI
void darBaja(ePersona persona[],int idBuscador,int cantidad);
int buscarPorDni(ePersona persona[],int dniAux,int cantidad);

typedef struct{
    char apellido[31];
    char nombre[31];
    int edad;
    int isEmpty;
}ePersona;

void altaPersona(ePersona persona[],int cantidad);//UN ARRAY DE STRUCT
void mostrarTodoPersona(ePersona persona[],int cantidad);
void mostrarPersona(ePersona persona);

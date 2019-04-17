typedef struct{
    char apellido[31];
    char nombre[31];
    int edad;
    int isEmpty;
}ePersona;

ePersona altaPersona(ePersona persona);
void mostrarPersona(ePersona persona);

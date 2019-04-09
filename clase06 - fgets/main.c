#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[64];
    int cantidad;

    printf("Nombre: ");
    //fgets(buffer, 62, stdin);
    fgets(buffer,sizeof(buffer)-2,stdin);//sizeof es un operador que recibe como parametro tipo de dato o una variable y nos va a decir la cantidad de byte que ocupa tal parametro.. asegura que no exceda la cantidad de memoria
    //1er parametro donde ira
    //3er parametro. standar de ingreso de teclado, "trabaja desde el teclado"
    //-2 porque no se trabaja con archivo. sirve para imprimir hasta el \0... lo uso para no pasarme
    cantidad = strlen(buffer);//cuenta los caracteres de buffer,devuelve un entero que es la cantidad omitiendo el \0

    buffer[cantidad-1] = '\0';//le asigna \0 al operador que no se utiliza

    printf("%s", buffer);

    return 0;
}

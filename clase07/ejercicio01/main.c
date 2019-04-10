#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELEMENTOS 5

//REALIZAR UN PROGRAMA QUE ORDENE UN VECTOR CON NOMBRE Y APELLIDO POR ABECEDARIO

int main()
{
    int i,j;
    char nombre[ELEMENTOS][50] = {"pedro","carlos","juan","ernesto","mario"};
    char apellido[ELEMENTOS][50]= {"gomez","fernandez","paz","perez","lopez"};
    char auxiliar[50];

    for(i=0; i< ELEMENTOS-1; i++)
    {
        for(j=i+1; j<ELEMENTOS; j++)
        {
            if(strcmp(apellido[i],apellido[j])>0)
            {
                strcpy(auxiliar,apellido[i]);
                strcpy(apellido[i],apellido[j]);
                strcpy(apellido[j], auxiliar);
                //siempre llevar (copiar) todos los datos del mismo vector. sino se desordenarian los datos
                //En este caso serian los nombres. si tuviera otros datos como nota o dni, tambien se tienen que mover o copiar
                strcpy(auxiliar,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j], auxiliar);
            }
        }
    }
    printf("\n\nLista ordenada por nombres");
    for(i=0; i<ELEMENTOS; i++)
    {
        printf("\nNombre: %s - Apellido: %s",nombre[i],apellido[i]);
    }
    return 0;
}

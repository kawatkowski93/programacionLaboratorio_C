#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

//CREAR UN PROGRAMA QUE ORDENE POR DOS CRITERIOS, 1RO POR SUELDO Y 2DO POR NOMBRE

int main(void)
{
    int legajo[MAX]= {0,1,2,3,4};
    int legajoAux, i, j;
    float salario[MAX]= {20000, 20000,30000,400,5000};
    float salarioAux;
    char nombre[MAX][31]= {"juan","maria","luis","marcos","luisa"};
    char nombreAux[31];

    for(i=0; i<MAX-1; i++)
    {
        for(j=i+1; j<MAX; j++)
        {
            if(salario[i] < salario[j])
            {
                strcpy(nombreAux, nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], nombreAux);

                legajoAux = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = legajoAux;

                salarioAux = salario[i];
                salario[i] = salario[j];
                salario[j] = salarioAux;
            }

            if(salario[i] == salario[j])
            {
                if(strcmp(nombre[i],nombre[j])>0)
                {
                    strcpy(nombreAux, nombre[i]);
                    strcpy(nombre[i], nombre[j]);
                    strcpy(nombre[j], nombreAux);

                    legajoAux = legajo[i];
                    legajo[i] = legajo[j];
                    legajo[j] = legajoAux;

                    //LO DEJO COMENTADO PORQUE YA ESTA ASUMIDO QUE SON IGUALES, Y COPIARLOS NUEVAMENTE PERDERIA EFICIENCIA

                    /*salarioAux = salario[i];
                    salario[i] = salario[j];
                    salario[j] = salarioAux;*/
                }
            }
        }
    }
    system("cls");
    printf("\nLegajo\t\tNombre\t\t\tSalario ");
    for(i=0; i<MAX; i++)
    {
        printf("\n%d\t\t%s\t\t\t%.2f", legajo[i], nombre[i], salario[i]);
    }
    return 0;
}

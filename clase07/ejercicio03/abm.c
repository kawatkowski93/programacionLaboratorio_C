

int inicializarEstado(int* lista, int estado,int CANTIDAD)
{
    int i, retorno=0;

    if(lista>=0)
    {
        for(i=0;i<CANTIDAD;i++)
        {
            lista[i]= estado;
            retorno= 1;
            return retorno;
        }
    }
    return retorno;
}

int encontrarId(int* lista, int id,int CANTIDAD)
{
    int i, retorno=0;

    if(lista>=0)
    {
        for(i=0;i<CANTIDAD;i++)
        {
            if(lista[i]== id)
            {
                retorno= i;
                break;
            }
        }
    }
    return retorno;
}



//EJEMPLO alta(int legajo[],apellido,char* nombre[],...)
//opcion=menu()                         int menu(){printf---}
//otro ejemplo
//opcion= menu("1-ALTA   2_baha ...)        int menu(char opcion[]){int opcion; scanf; printf("%s",opciones) retorno opcion;}

int baja(int* legajo,int estado[],int CANTIDAD)
{
    char respuesta;
    int legajoAux,i,retorno=0;

    printf("Ingrese legajo a buscar:\n");
    scanf("%d",&legajoAux);

    for(i=0; i<CANTIDAD; i++)
    {
        if(legajo[i]==legajoAux)
        {
            printf("Legajo: %d\n",legajo[i]);

            do
            {
                printf("Desea dar de baja S/N");
                fflush(stdin);
                scanf("%c",&respuesta);
                respuesta= toupper(respuesta);

            }
            while(respuesta!='s' && respuesta != 'n');

            if(respuesta=='s')
            {
                estado[i]= 0;//ESTADO BORRADO
                retorno=1;//LOGRO SER DADO DE BAJA
                break;//rompo el for
            }
            else
            {
                printf("No se elimino legajo\n");
            }
        }
    }
    if(retorno==0)
    {
        printf("No se encontro legajo");
    }
    return retorno;
}


int modificar(int* legajo,int CANTIDAD)
{
    char respuesta;
    int legajoAux,i,retorno=0,opcionMenuAuxiliar;

    printf("Ingrese legajo para ser modificado:\n");
    scanf("%d",&legajoAux);

    for(i=0;i<CANTIDAD;i++)
    {
        if(legajo[i]==legajoAux)
        {
            printf("Legajo: %d",legajo[i]);

        }
        do{
            printf("Desea modificar S/N\n");
            fflush(stdin);
            scanf("%c",&respuesta);
            respuesta= toupper(respuesta);

            }while(respuesta!='s' && respuesta != 'n');

            if(respuesta=='s')
            {
                do
                {
                    printf("Ingrese opcion que desee modificar:\n");
                    scanf("%d",&opcionMenuAuxiliar);

                    switch(opcionMenuAuxiliar)
                    {
                    case 1:
                        //modifica nombre

                        break;

                    case 2:
                        //modifica apellido
                        break;
                    }

                }while(opcionMenuAuxiliar!=5);

                retorno=1;
            }
    }
    return retorno;
}

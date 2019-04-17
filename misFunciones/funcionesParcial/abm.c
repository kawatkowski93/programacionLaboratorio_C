#include <stdio.h>
#include <stdlib.h>
#define ESTADO_LIBRE 0
#define ESTADO_OCUPADO 1

static int idAutoincrementable= -1;

/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}

/**
 * \brief inicializa en un estado un array
 * \param int, arrayLista lista de array a inicializar
 * \param int, estado que se cargada
 * \param int, lenght largo de array
 * \return int, 0 si no es un array valido, 1 si cargo el estado correctamente
 *
 */
int inicializarEstadoArray(int* arrayLista,int estado, int length)
{
    int i, retorno=0;

    if(length>=0 && arrayLista!=NULL)
    {
        for(i=0;i<length;i++)
        {
            arrayLista[i]= estado;
        }
        retorno=1;
    }
    return retorno;
}

/**
 * \brief Encuentra un id unico en una lista de array
 * \param int, arrayLista lista de array a buscar
 * \param int, idAux id que se busca encontrar
 * \param int, lenght largo de array
 * \return int, 0 si no encontro id, nº de id encontrado
 *
 */
int encontrarPorId(int* arrayLista, int idAux, int length)
{
    int i, retorno=0;

    if(length>=0 && arrayLista!=NULL)
    {
        for(i=0;i<length;i++)
        {
            if(arrayLista[i]== idAux)
            {
                retorno= idAux;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Encuentra un lugar disponible en el array
 * \param int, arrayLista lista de array a buscar
 * \param int, lenght largo de array
 * \return int, -1 si no encontro lugar, nº de lugar disponible
 *
 */
int array_encontrarLugarDisponible(int* arrayLista, int length)
{
    int i, retorno=-1;

    if(length>=0 && arrayLista!=NULL)
    {
        for(i=0;i<length;i++)
        {
            if(arrayLista[i]==ESTADO_LIBRE)
            {
                retorno= i;
                break;
            }
        }
    }
    return retorno;
}


int array_alta(int* arrayLista,int lenght)
{
    char apellido[lenght][50], nombre[lenght][50];
    int legajo[lenght], id[lenght],estado[lenght],edad[lenght],LugarDisponible,retorno=0;

    if(arrayLista!= NULL && lenght>=0)
    {
        LugarDisponible=array_encontrarLugarDisponible(arrayLista,lenght);

        if(LugarDisponible==-1)
            retorno= -2;

        else
        {
            id[LugarDisponible]= array_generarProximoId();
            if(id>=0)
            {
                getValidString("Ingrese Nombre:\n","Error\n",nombre[LugarDisponible]);
                getValidString("Ingrese Apellido:\n","Error\n",apellido[LugarDisponible]);
                edad[LugarDisponible]= getValidIntOpcion("Ingrese edad:\n","Error la edad no puede ser menor a 1 ni mayor a 100",0,100);
                retorno=1;
            }
        }
    }
    return retorno;
}

#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0
#include "menues.h"
#include "employee.h"

typedef struct{
        int idAlmuerzo;//AutoIncrementable
        int idMenu;//LISTAR.CODIGO MENU-DAR DE ALTA MOSTRANDO CODIGO DESCRIPCION. CARGO CON CODIGO
        int idEmpleado;//LISTAR TODOS LOS EMPLEADOS CON SU ID Y CARGO EL LEJADO DE EMPLEADO
        eFecha fechaAlmuerzo;//CUANDO COMIO
        int isEmpty;
}eAlmuerzo;

int initAlmuerzos(eAlmuerzo* almuerzos,int cantidadAlmuerzos);
int almuerzo_findIsEmpty(eAlmuerzo* almuerzos,int cantidadAlmuerzos);
void altaAlmuerzos(eAlmuerzo* almuerzos,int cantidadAlmuerzos,eMenu* menues,eEmployee* empleados);


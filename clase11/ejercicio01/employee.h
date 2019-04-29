#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0

typedef struct{
            int idNacionalidad;
            char descripcion[31];
}eNacionalidad;

typedef struct{
            int id;
            char name[51];
            char lastName[51];
            float salary;
            int nacionalidad;
            int isEmpty;
}eEmployee;

int array_generarProximoId(void);
int initEmployees(eEmployee* empleados,int cantidad);
int addEmployee(eEmployee* empleados,int cantidad);
int findEmployeeById(eEmployee* empleados,int cantidad,int id);
int findIsEmpty(eEmployee* empleados,int cantidad);
int removeEmployee(eEmployee* empleados,int cantidad,int id);
void printEmployee(eEmployee empleado,eNacionalidad* nacionalidad,int cantidad);
void printListEmployee(eEmployee* empleados,int cantidadEmpleados,eNacionalidad* nacionalidades,int cantidadNacionalidades);
int modificarEmployee(eEmployee* empleados, int cantidad,int id);
void hardcodearDatosEmpleados(eEmployee* empleado, int cantidad);

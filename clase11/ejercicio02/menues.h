#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0


typedef struct{
            int idMenu;
            char descripcion[31];
            float importe;
            int isEmpty;
}eMenu;


int array_generarProximoIdMenues(void);
int initMenues(eMenu* menues,int cantidadMenues);
int findMenuById(eMenu* menues,int cantidadMenues,int id);
int menu_findIsEmpty(eMenu* menues,int cantidad);
int removeMenu(eMenu* menues,int cantidadMenues,int id);
int modificarMenu(eMenu* menues, int cantidadMenues,int idAux);
void ordenarMenues(eMenu* menues,int cantidadMenues);
void administrarMenues(eMenu* menues, int cantidadMenues);


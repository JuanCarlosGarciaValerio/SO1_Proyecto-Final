//Las estructuras que se declaracian en el main sería solamente para semáforos y recursos totales
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Estructura de la región crítica de un proceso
typedef struct regioncritica{
	int tiempoEntrada;
	int duracion;
	char recursoUsado[20];
	struct regioncritica *siguiente;
}*REGIONCRITICA;

//Estructura de un proceso
typedef struct proceso{
	int pid;
	int uid;
	int gid;
	int tiempo;
	struct regioncritica *rc;
	struct proceso *siguiente;
}*PROCESO;

//Estructura de la lista de recursos de un semáforo
typedef struct recursosdisponibles{
	char nombre[20];
	int disponibles;
	struct recursosdisponibles *siguiente;
}*RECURSOSDISPONIBLES;

//Estructura de un semáforo
typedef struct semaforo{
	int semid;
	struct recursosdisponibles *recursos;
	struct proceso *procesos;
	struct semaforo *siguiente;
}*SEMAFORO;

//Estructura de lista de todos los recursos
typedef struct recursostotales{
	int num;    //Variable para seleccion a la hora de agregar recursos a una región crítica
	char nombre[20];
	int numerosDeRecursosTotales;
	struct recursostotales *siguiente;
}*RECURSOSTOTALES;



//Declaración de métodos

/*
Puesto que la tabla de cotrol de procesos include todos los procesos creados, entonces pasamos la lista de semaforos
para poder recorrer la lista de procesos que contiene cada semaforo.
*/
void mostrarTablaDeContol(SEMAFORO listaSemaforos);


/*
Este método sirve para mostrar la informacion de cada semáforo (# de semáforo, total de recursos que controla, recursos
disponibles, procesos que maneja, Creo que también las listas de estado y los estados de los procesos en forma gráfica).
*/
void informacionDeSemaforos(SEMAFORO listaSemaforos);


/*
Esté metodo es para agregar un recurso a la lista general.
*/
RECURSOSTOTALES agregarRecursos(RECURSOSTOTALES listaRecursos); //LISTO



/*
Este metodo es para crear semaforos
*/
SEMAFORO agregarSemaforo(SEMAFORO listaSemaforos, RECURSOSTOTALES listaRecursos); //LISTO



/*
Método que sirve para añadir las regiones criticas de un proceso.
*/
REGIONCRITICA agregarRegionCritica(SEMAFORO actual, PROCESO creado); //LISTO


/*
Esté metodo es para crear y añadir el proceso creado, contiene el método agregarRegionCritica.
*/
PROCESO agregarALaLista(SEMAFORO cabeza, SEMAFORO actual); //LISTO

/*
Esté metodo es para agregar procesos a los semáforos, contiene el método agregarALaLista.
*/
SEMAFORO agregarProceso(SEMAFORO listaSemaforos);
/*
Este metodo es para agregar los recursos con los cuales dispondrá
*/
RECURSOSDISPONIBLES agregarRecursosDisponibles(SEMAFORO actual, RECURSOSTOTALES listaRecursos); //LISTO

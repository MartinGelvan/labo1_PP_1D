/*
 ============================================================================
 Name        : PP_Labo1_GelvanMartin.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define  TAMPERROS 50
#define  TAMESTADIAS 50
#define  TAMFECHAS 50
#include "nexo.h"


int main(void) {
	setbuf(stdout, NULL);

	int opcion;

	int ultimoIdEstadia= 100002;
	ePerro arrayPerros[TAMPERROS];
	eEstadiaDiaria arrayEstadias[TAMESTADIAS];
	eFecha arrayFechas[TAMFECHAS];
	int cantidadEstadias=0;

	int cantidadPerros=0;


	perros_inicializarArray(arrayPerros, TAMPERROS);
	estadia_inicializarArray(arrayEstadias, TAMESTADIAS);
	fecha_inicializarArray(arrayFechas,TAMFECHAS);

	//estadia_hardCodearEstadia(arrayEstadias, TAMFECHAS);
	//perro_hardCodearPerros(arrayPerros, TAMPERROS);
	fecha_hardCodearFecha(arrayFechas, TAMFECHAS);


	do
	{
		pedirEntero(&opcion, "บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n"
				"1. Reservar estadia\n"
				"2. Modificar estadia\n"
				"3. Cancelar estadia\n"
				"4. Listar estadias\n"
				"5. Listar perros\n"
				"6. Promedio edad perros\n"
				"7. SALIR\n"
				"บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n"
				"Ingrese una opcion: ",
				"บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n"
				"1. Reservar estadia\n"
				"2. Modificar estadia\n"
				"3. Cancelar estadia\n"
				"4. Listar estadias\n"
				"5. Listar perros\n"
				"6. Promedio edad perros\n"
				"7. SALIR\n"
				"บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n"
				"Opcion invalida, reingrese: ", 1, 7);

		switch(opcion)
		{
			case 1:
			if(perro_Estadia_Fecha_agregarEstadiaPerro(arrayPerros,TAMPERROS,arrayEstadias,TAMESTADIAS,arrayFechas, TAMFECHAS,ultimoIdEstadia)==0)
			{
				cantidadEstadias++;
				ultimoIdEstadia++;
				cantidadPerros++;
			}
			system("pause");
			break;
			case 2:
				if(cantidadEstadias>0)
				{
					perro_Estadia_Fecha_mostrarTodos(arrayPerros, TAMPERROS, arrayEstadias,TAMESTADIAS, TAMFECHAS,arrayFechas);
					perro_Estadia_ModificarUno( arrayPerros,arrayEstadias,arrayFechas,TAMESTADIAS, TAMPERROS);
				}else
				{
					printf("\nNO HAY ESTADIAS PARA MODIFICAR\n");
				}

			system("pause");
			break;
			case 3:
				if(cantidadEstadias>0)
				{
					estadia_mostrarTodos(arrayEstadias, TAMESTADIAS);
					if(estadia_cancelarEstadia(arrayEstadias, TAMESTADIAS, arrayPerros, TAMPERROS)==0)
					{
						cantidadEstadias--;

					}
				}else
				{
					printf("\nNO HAY ESTADIAS PARA CANCELAR\n");
				}

			system("pause");
			break;
			case 4:

				if(cantidadEstadias>0)
				{
					estadia_ordenarEstadiasPorFechas(arrayEstadias,TAMESTADIAS, arrayFechas);
					perro_Estadia_Fecha_mostrarTodos(arrayPerros, TAMPERROS, arrayEstadias,TAMESTADIAS, TAMFECHAS,arrayFechas);
				}else
				{
					printf("\nNO HAY NADA PARA ORDENAR\n");
				}

			system("pause");
			break;
		case 5:
			if(cantidadPerros>0)
			{
				perro_mostrarTodos(arrayPerros, TAMPERROS);
			}else
			{
				printf("\nNO HAY NADA PARA MOSTRAR\n");
			}

			system("pause");
			break;
		case 6:

			if(cantidadPerros>0)
			{
				perro_promedioPorEdadDePerros(arrayPerros,TAMPERROS);
			}

			system("pause");
			break;
			case 7:
			printf("\nFin del programa\n");
			break;
		}
	}while(opcion != 7);


return EXIT_SUCCESS;
}



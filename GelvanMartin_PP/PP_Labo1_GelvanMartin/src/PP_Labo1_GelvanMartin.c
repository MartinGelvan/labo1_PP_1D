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
#define  TAMDUENIOS 50
#include "nexo.h"


int main(void) {
	setbuf(stdout, NULL);

	int opcion;

	int ultimoIdEstadia= 99999;
	ePerro arrayPerros[TAMPERROS];
	eEstadiaDiaria arrayEstadias[TAMESTADIAS];
	eFecha arrayFechas[TAMFECHAS];
	eDuenio arrayDuenios[TAMDUENIOS];
	int cantidadEstadias=0;
	//int cantidadDuenios=3;
	int cantidadPerros=3;


	perros_inicializarArray(arrayPerros, TAMPERROS);
	estadia_inicializarArray(arrayEstadias, TAMESTADIAS);
	fecha_inicializarArray(arrayFechas,TAMFECHAS);
	duenios_inicializarArray(arrayDuenios, TAMDUENIOS);

	//estadia_hardCodearEstadia(arrayEstadias, TAMFECHAS);
	duenio_hardCodearDuenio(arrayDuenios, TAMDUENIOS);
	perro_hardCodearPerros(arrayPerros, TAMPERROS);
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
				"7. El perro que tiene mas estadias reservadas\n"
				"8. Listado de perros con sus estadํas diarias reservadas.\n"
				"9. SALIR\n"
				"บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n"
				"Ingrese una opcion: ",
				"บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n"
				"1. Reservar estadia\n"
				"2. Modificar estadia\n"
				"3. Cancelar estadia\n"
				"4. Listar estadias\n"
				"5. Listar perros\n"
				"6. Promedio edad perros\n"
				"7. El perro que tiene mas estadias reservadas\n"
				"8. Listado de perros con sus estadias diarias reservadas.\n"
				"9. SALIR\n"
				"บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n"
				"Opcion invalida, reingrese: ", 1, 9);

		switch(opcion)
		{
			case 1:
			if(perro_Estadia_Fecha_agregarEstadiaPerro(arrayPerros,TAMPERROS,arrayEstadias, TAMESTADIAS, arrayFechas,TAMFECHAS,ultimoIdEstadia, TAMDUENIOS,arrayDuenios)==0)
			{
				cantidadEstadias++;
				ultimoIdEstadia++;
				//cantidadPerros++;

			}
			system("pause");
			break;
			case 2:
				if(cantidadEstadias>0)
				{
					//perro_Estadia_Fecha_mostrarTodos(arrayPerros, TAMPERROS, arrayEstadias,TAMESTADIAS, TAMFECHAS,arrayFechas);
					estadia_mostrarTodos(arrayEstadias, TAMESTADIAS);
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
					//perro_Estadia_Fecha_mostrarTodos(arrayPerros, TAMPERROS, arrayEstadias,TAMESTADIAS, TAMFECHAS,arrayFechas);
					estadia_mostrarTodos(arrayEstadias, TAMESTADIAS);
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
			}else
			{
				printf("\nNO HAY NADA PARA MOSTRAR\n");
			}

			system("pause");
			break;

		case 7:
				if(cantidadPerros>0)
				{
					perrosConMasEstadias(arrayEstadias);
				}else
				{
					printf("\nNO HAY NADA PARA MOSTRAR\n");
				}
		break;

		case 8:
			if( cantidadPerros>0 && cantidadEstadias>0)
			{
				listadoPerrosConSusEstadias(arrayPerros,TAMPERROS, arrayEstadias,TAMESTADIAS);

			}else
			{
				printf("NO HAY NADA PARA MOSTRAR\n");
			}
			system("pause");
		break;

		case 9:
			printf("\nFin del programa\n");
			break;
		}
	}while(opcion != 9);


return EXIT_SUCCESS;
}



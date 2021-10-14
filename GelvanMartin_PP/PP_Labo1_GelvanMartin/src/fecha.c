/*
 * fecha.c
 *
 *  Created on: 8 oct. 2021
 *      Author: PCNEW
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nexo.h"
#include "Inputs.h"

void fecha_inicializarArray(eFecha fechas[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		fechas[i].estadoFecha = VACIO;
	}
}

void fecha_hardCodearFecha(eFecha fechas[], int tam)
{
	int i;

	int dia[]= {1,13,4};
	int mes[]={4,11,2};
	int anio[]={2020,2030,2021};

	for (i = 0; i < 3; i++) {
		fechas[i].dia = dia[i];
		fechas[i].mes = mes[i];
		fechas[i].anio = anio[i];
		fechas[i].estadoFecha = OCUPADO;
	}
}

int fecha_buscarEspacioLibre(eFecha fechas[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(fechas[i].estadoFecha == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}


void fecha_mostrarUno(eFecha fecha)
{
	printf("%-15d %-20d %-20d\n", fecha.dia, fecha.mes, fecha.anio);
}

void fecha_mostrarTodos(eFecha fechas[], int tam)
{
	int i;
	printf("\nMostrando lista de fechas...\n\n");
	for(i=0; i<tam; i++)
	{
		if(fechas[i].estadoFecha == OCUPADO)
		{
			fecha_mostrarUno(fechas[i]);
		}
	}
	printf("\n");
}

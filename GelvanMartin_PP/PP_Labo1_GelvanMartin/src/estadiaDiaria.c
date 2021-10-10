/*
 * estadiaDiaria.c
 *
 *  Created on: 7 oct. 2021
 *      Author: PCNEW
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nexo.h"
#include "Inputs.h"


void estadia_inicializarArray(eEstadiaDiaria estadias[], int tam)
{
	int i;
	for (i = 0; i < tam; i++) {
		estadias[i].estadoEstadia = VACIO;
	}
}

void estadia_hardCodearEstadia(eEstadiaDiaria estadias[], int tam)
{
	int i;
	int id[] = { 100000, 100001, 100002 };
	char nombreDuenio[][21] = { "Juan", "Lucas", "Marta" };
	int telefonoContacto[] = { 2, 12, 13 };
	int idPerro[] = { 7000, 7001, 7002 };
	int fecha[]= {4765112,1148745231,41426522 };


	for (i = 0; i < tam - 2; i++) {
		estadias[i].id = id[i];
		strcpy(estadias[i].nombreDuenio, nombreDuenio[i]);
		estadias[i].telefonoContacto = telefonoContacto[i];
		estadias[i].idPerro = idPerro[i];
		estadias[i].fecha = fecha[i];
		estadias[i].estadoEstadia = OCUPADO;
	}
}

int estadia_buscarEspacioLibre(eEstadiaDiaria estadias[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(estadias[i].estadoEstadia == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

int estadia_buscarPorId(eEstadiaDiaria estadias[], int tam, int id)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(estadias[i].estadoEstadia == OCUPADO && estadias[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}


void estadia_mostrarUno(eEstadiaDiaria estadia)
{
	printf("%-15d %-20s %-20d\n", estadia.id, estadia.nombreDuenio, estadia.telefonoContacto);
}

void estadia_mostrarTodos(eEstadiaDiaria estadias[], int tam)
{
	int i;
	printf("\nMostrando lista de estadias...\n\n");
	for(i=0; i<tam; i++)
	{
		if(estadias[i].estadoEstadia == OCUPADO)
		{
			estadia_mostrarUno(estadias[i]);
		}
	}
	printf("\n");
}

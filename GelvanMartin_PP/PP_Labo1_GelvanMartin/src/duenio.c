/*
 * duenio.c
 *
 *  Created on: 15 oct. 2021
 *      Author: PCNEW
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nexo.h"

void duenios_inicializarArray(eDuenio duenios[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		duenios[i].estadoDuenio = VACIO;
	}
}

void duenio_hardCodearDuenio(eDuenio duenios[], int tam)
{
	int i;
	int id[] = { 30000, 30001, 30002 };
	char nombreDuenio[][21] = { "Juan", "Lucas", "Marta" };
	int telefonoContacto[] = { 1565745216, 1587454125, 1584213768 };
	//int idPerro[] = { 7000, 7001, 7002 };


	for (i = 0; i < 3; i++) {
		duenios[i].id = id[i];
		strcpy(duenios[i].nombre, nombreDuenio[i]);
		duenios[i].telefono = telefonoContacto[i];
		//duenios[i].idPerro = idPerro[i];
		duenios[i].estadoDuenio = OCUPADO;
	}
}

void duenio_mostrarUno(eDuenio duenio)
{
	printf("%-15s %-20s %-20s\n","ID DUEัO","NOMBRE DUEัO","TELEFONO");
	printf("บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n");
	printf("%-15d %-20s %-20d\n", duenio.id, duenio.nombre, duenio.telefono);
}

int duenio_buscarPorId(eDuenio duenios[], int tam, int id)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(duenios[i].estadoDuenio == OCUPADO && duenios[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

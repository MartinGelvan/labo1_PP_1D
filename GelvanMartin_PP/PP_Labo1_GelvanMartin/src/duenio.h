/*
 * duenio.h
 *
 *  Created on: 15 oct. 2021
 *      Author: PCNEW
 */

#ifndef DUENIO_H_
#define DUENIO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	int id;
	char nombre[41];
	int telefono;
	int estadoDuenio;

} eDuenio;

void duenios_inicializarArray(eDuenio duenios[], int tam);
void duenio_hardCodearDuenio(eDuenio duenios[], int tam);
void duenio_mostrarUno(eDuenio duenio);
int duenio_buscarPorId(eDuenio duenios[], int tam, int id);

#endif /* DUENIO_H_ */

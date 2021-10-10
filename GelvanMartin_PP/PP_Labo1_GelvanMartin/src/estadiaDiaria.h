/*
 * estadiaDiaria.h
 *
 *  Created on: 7 oct. 2021
 *      Author: PCNEW
 */

#ifndef ESTADIADIARIA_H_
#define ESTADIADIARIA_H_
#include <stdio.h>
#include <stdlib.h>



typedef struct {
	int id;
	char nombreDuenio[21];
	int telefonoContacto;
	int idPerro;
	int fecha;
	int estadoEstadia;

} eEstadiaDiaria;

void estadia_inicializarArray(eEstadiaDiaria estadias[], int tam);
void estadia_hardCodearEstadia(eEstadiaDiaria estadias[], int tam);
int estadia_buscarEspacioLibre(eEstadiaDiaria estadias[], int tam);
void estadia_mostrarUno(eEstadiaDiaria estadia);
void estadia_mostrarTodos(eEstadiaDiaria estadias[], int tam);
int estadia_buscarPorId(eEstadiaDiaria estadias[], int tam, int id);

#endif /* ESTADIADIARIA_H_ */

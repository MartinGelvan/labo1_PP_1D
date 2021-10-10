/*
 * fecha.h
 *
 *  Created on: 8 oct. 2021
 *      Author: PCNEW
 */

#ifndef FECHA_H_
#define FECHA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	int dia;
	int mes;
	int anio;
	int estadoFecha;

} eFecha;

void fecha_inicializarArray(eFecha fechas[], int tam);
int fecha_buscarEspacioLibre(eFecha fechas[], int tam);
void fecha_hardCodearFecha(eFecha fechas[], int tam);
void fecha_mostrarUno(eFecha fecha);
void fecha_mostrarTodos(eFecha fechas[], int tam);

#endif /* FECHA_H_ */

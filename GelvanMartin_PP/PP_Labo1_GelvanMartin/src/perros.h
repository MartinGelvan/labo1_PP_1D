/*
 * perros.h
 *
 *  Created on: 7 oct. 2021
 *      Author: PCNEW
 */

#ifndef PERROS_H_
#define PERROS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"


typedef struct {
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	int estadoPerro;

} ePerro;

void perros_inicializarArray(ePerro perros[], int tam);
void perro_hardCodearPerros(ePerro perros[], int tam);
int perro_buscarEspacioLibre(ePerro perros[], int tam);
int perro_buscarPorId(ePerro perros[], int tam, int id);
void perro_mostrarUno(ePerro perro);
void perro_mostrarTodos(ePerro perros[], int tam);
int perro_cargarUno(ePerro perros[], int i,int ultimoId);
int perro_agregarPerro(ePerro perros[], int tam, int ultimoId);
int perro_borrarUno(ePerro perros[], int tam);

#endif /* PERROS_H_ */

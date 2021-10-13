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


/**
 * @fn void fecha_inicializarArray(eFecha[], int)
 * @brief inicializo la lista de fechas
 *
 * @param fechas lista de fechas
 * @param tam tamanio lista fechas
 */
void fecha_inicializarArray(eFecha fechas[], int tam);

/**
 * @fn int fecha_buscarEspacioLibre(eFecha[], int)
 * @brief busca si hay o no espacio libre de la fecha
 *
 * @param fechas lista fechas
 * @param tam tamanio lista fechas
 * @return devuelve el indice si hay espacio o no
 */
int fecha_buscarEspacioLibre(eFecha fechas[], int tam);

/**
 * @fn void fecha_hardCodearFecha(eFecha[], int)
 * @brief hardcodeo algunas fechas
 *
 * @param fechas lista fechas
 * @param tam tamanio lista fechas
 */
void fecha_hardCodearFecha(eFecha fechas[], int tam);

/**
 * @fn void fecha_mostrarUno(eFecha)
 * @brief muestro una sola fecha
 *
 * @param fecha una sola fecha
 */
void fecha_mostrarUno(eFecha fecha);

/**
 * @fn void fecha_mostrarTodos(eFecha[], int)
 * @brief muestro la lista de fechas
 *
 * @param fechas lista de fechas
 * @param tam tamanio lista fechas
 */
void fecha_mostrarTodos(eFecha fechas[], int tam);

#endif /* FECHA_H_ */

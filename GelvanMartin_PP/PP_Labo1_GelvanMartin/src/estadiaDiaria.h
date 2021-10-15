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
#include <string.h>
#include "fecha.h"
#include "duenio.h"

typedef struct {
	int id;
	//char nombreDuenio[21];
	//int telefonoContacto;
	int idPerro;
	eFecha fecha;
	int estadoEstadia;
	eDuenio duenio;

} eEstadiaDiaria;


/**
 * @fn void estadia_inicializarArray(eEstadiaDiaria[], int)
 * @brief inicializo la lista de estadias
 *
 * @param estadias lista de estadias
 * @param tam tamanio lista estadias
 */
void estadia_inicializarArray(eEstadiaDiaria estadias[], int tam);

/**
 * @fn void estadia_hardCodearEstadia(eEstadiaDiaria[], int)
 * @brief hardcodeo algunas estadias
 *
 * @param estadias lista de estadias
 * @param tam tamanio lista estadia
 */
void estadia_hardCodearEstadia(eEstadiaDiaria estadias[], int tam);

/**
 * @fn int estadia_buscarEspacioLibre(eEstadiaDiaria[], int)
 * @brief busco si hay un espacio libre o no
 *
 * @param estadias lista de estadias
 * @param tam tamanio lista estadias
 * @return devuelvo el indice en donde busco si hay espacio libre
 */
int estadia_buscarEspacioLibre(eEstadiaDiaria estadias[], int tam);

/**
 * @fn void estadia_mostrarUno(eEstadiaDiaria)
 * @brief muestro una sola estadia
 *
 * @param estadia una sola estadia
 */
void estadia_mostrarUno(eEstadiaDiaria estadia);

/**
 * @fn void estadia_mostrarTodos(eEstadiaDiaria[], int)
 * @brief muestro la lista de estadias
 *
 * @param estadias lista de estadias
 * @param tam tamanio lista estadias
 */
void estadia_mostrarTodos(eEstadiaDiaria estadias[], int tam);

/**
 * @fn int estadia_buscarPorId(eEstadiaDiaria[], int, int)
 * @brief busco el indice de la estadia a partir de id
 *
 * @param estadias lista de estadias
 * @param tam tamanio lista estadias
 * @param id id que va a comparar
 * @return
 */
int estadia_buscarPorId(eEstadiaDiaria estadias[], int tam, int id);





#endif /* ESTADIADIARIA_H_ */

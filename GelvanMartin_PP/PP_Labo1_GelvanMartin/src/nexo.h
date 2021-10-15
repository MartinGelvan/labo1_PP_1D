/*
 * nexo.h
 *
 *  Created on: 8 oct. 2021
 *      Author: PCNEW
 */

#ifndef NEXO_H_
#define NEXO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perros.h"
#include "estadiaDiaria.h"
#include "fecha.h"
#include "duenio.h"

#define  VACIO 0
#define  OCUPADO 1

/**
 * @fn int perro_Estadia_Fecha_cargarUno(eEstadiaDiaria[], int, ePerro[], int, eFecha[], int, int)
 * @brief  cargo una estadia
 *
 * @param estadias lista de estadias
 * @param j tamanio lista estadias
 * @param perros lista perros
 * @param i tamanio lista perros
 * @param fechas lista fechas
 * @param k tamanio lista fechas
 * @param ultimoId ultimo id de la estadia para incrementar
 * @return devuelve si hubo exito en la carga
 */
int perro_Estadia_Fecha_cargarUno(eEstadiaDiaria estadias[],int j,ePerro perros[], int i,eFecha fechas[],int k,int ultimoId, int tam, eDuenio duenios[]);

/**
 * @fn int perro_Estadia_Fecha_agregarEstadiaPerro(ePerro[], int, eEstadiaDiaria[], int, eFecha[], int, int)
 * @brief agrego una estadia
 *
 * @param perros lista perros
 * @param tam tamanio lista perros
 * @param estadias lista de estadias
 * @param tam2 tamanio lista estadias
 * @param fechas lista fechas
 * @param tam3 tamanio lista fechas
 * @param ultimoId ultimoId ultimo id de la estadia para incrementar
 * @return devuelve si hubo exito en el agregado
 */
int perro_Estadia_Fecha_agregarEstadiaPerro(ePerro perros[],int tam,eEstadiaDiaria estadias[], int tam2, eFecha fechas[], int tam3, int ultimoId, int tam4,eDuenio duenios[]);

/**
 * @fn int perro_Estadia_ModificarUno(ePerro[], eEstadiaDiaria[], eFecha[], int, int)
 * @brief modifico la estadia tanto el numero como el perro (El ID)
 *
 * @param perros lista perros
 * @param estadias lista estadias
 * @param fechas lista estadias
 * @param tam tamanio lista estadias
 * @param tamPerro tamanio lista perros
 * @return devuelve si hubo exito en la modificacion
 */
int perro_Estadia_ModificarUno(ePerro perros[],eEstadiaDiaria estadias[],eFecha fechas[], int tam, int tamPerro);

/**
 * @fn void perro_Estadia_Fecha_mostrarUno(eEstadiaDiaria, ePerro, eFecha)
 * @brief muestra un solo perro con estadia y la fecha
 *
 * @param estadia una sola estadia
 * @param perro un solo perro
 * @param fecha una sola fecha
 */
void perro_Estadia_Fecha_mostrarUno(eEstadiaDiaria estadia, ePerro perro, eFecha fecha);

/**
 * @fn void perro_Estadia_Fecha_mostrarTodos(ePerro[], int, eEstadiaDiaria[], int, int, eFecha[])
 * @brief muestra la lista de perros con las estadias y fechas
 *
 * @param perros lista de perros
 * @param tam1 tamanio lista perros
 * @param estadias lista estadias
 * @param tam2 lista tamanio estadias
 * @param tam3 tamanio lista fechas
 * @param fechas lista fechas
 */
void perro_Estadia_Fecha_mostrarTodos(ePerro perros[], int tam1, eEstadiaDiaria estadias[],int tam2, int tam3,eFecha fechas[]);

/**
 * @fn void estadia_ordenarEstadiasPorFechas(eEstadiaDiaria[], int, eFecha[])
 * @brief Ordena estadias por fechas
 *
 * @param estadias lista estadias
 * @param tam tamanio lista estadias
 * @param fechas lista fechas
 */
void estadia_ordenarEstadiasPorFechas(eEstadiaDiaria estadias[],int tam, eFecha fechas[]);

/**
 * @fn int estadia_cancelarEstadia(eEstadiaDiaria[], int, ePerro[], int)
 * @brief cancelo la estadia
 *
 * @param estadias lista estadias
 * @param tam tamanio lista estadia
 * @param perros lista perros
 * @param tamPerro tamanio lista perros
 * @return
 */
int estadia_cancelarEstadia(eEstadiaDiaria estadias[], int tam, ePerro perros[], int tamPerro);

void listadoPerrosConSusEstadias(ePerro perros[], int tam1, eEstadiaDiaria estadias[],int tam2);
void perrosConMasEstadias(eEstadiaDiaria estadias[]);


#endif /* NEXO_H_ */

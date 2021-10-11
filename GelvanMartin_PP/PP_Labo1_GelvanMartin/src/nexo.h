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

#define  VACIO 0
#define  OCUPADO 1

int perro_Estadia_Fecha_cargarUno(eEstadiaDiaria estadias[],int j,ePerro perros[], int i,eFecha fechas[],int k,int ultimoId);
int perro_Estadia_Fecha_agregarEstadiaPerro(ePerro perros[],int tam,eEstadiaDiaria estadias[], int tam2, eFecha fechas[], int tam3, int ultimoId);
int estadia_cancelarEstadia(eEstadiaDiaria estadias[], int tam, ePerro perros[], int tamPerro);



#endif /* NEXO_H_ */

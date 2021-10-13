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
#define  VACIO 0
#define  OCUPADO 1

typedef struct {
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	int estadoPerro;

} ePerro;

/**
 * @fn void perros_inicializarArray(ePerro[], int)
 * @brief Inicializa la lista de perros
 *
 * @param perros lista de perros
 * @param tam tamanio lista
 */
void perros_inicializarArray(ePerro perros[], int tam);

/**
 * @fn void perro_hardCodearPerros(ePerro[], int)
 * @brief hardcodea algunos perros
 *
 * @param perros lista de perros
 * @param tam tamanio lista
 */
void perro_hardCodearPerros(ePerro perros[], int tam);

/**
 * @fn int perro_buscarEspacioLibre(ePerro[], int)
 * @brief revisa si hay un espacio libre, si esta ocupado o vacio
 *
 * @param perros lista de perros
 * @param tam tamanio lista
 * @return devuelve el indice del espacio
 */
int perro_buscarEspacioLibre(ePerro perros[], int tam);

/**
 * @fn int perro_buscarPorId(ePerro[], int, int)
 * @brief busca el id por un id que pasa el usuario, las compara y te devuelve en la posicion que se encuentra ese id
 *
 * @param perros lista perros
 * @param tam tamanio lista
 * @param id el id a comparar
 * @return devuelve el indice del id
 */
int perro_buscarPorId(ePerro perros[], int tam, int id);

/**
 * @fn void perro_mostrarUno(ePerro)
 * @brief te muestra un solo perro
 *
 * @param perro un solo perro
 */
void perro_mostrarUno(ePerro perro);

/**
 * @fn void perro_mostrarTodos(ePerro[], int)
 * @brief te muestra todos los perros
 *
 * @param perros lista de perros
 * @param tam tamanio lista
 */
void perro_mostrarTodos(ePerro perros[], int tam);

/**
 * @fn int perro_cargarUno(ePerro[], int, int)
 * @brief carga un perro
 *
 * @param perros lista de perros
 * @param i la posicion del guardado del perro
 * @param ultimoId el ultimo id del perro
 * @return devuelve si hubo exito en la carga
 */
int perro_cargarUno(ePerro perros[], int i,int ultimoId);

/**
 * @fn int perro_agregarPerro(ePerro[], int, int)
 * @brief agrega al perro cargado
 *
 * @param perros lista de perros
 * @param tam tamanio lista
 * @param ultimoId el ultimo id del perro
 * @return devuelve si hubo exito en el agregado
 */
int perro_agregarPerro(ePerro perros[], int tam, int ultimoId);

/**
 * @fn int perro_borrarUno(ePerro[], int)
 * @brief borra logicamente un perro a partir del id ingresado
 *
 * @param perros lista de perros
 * @param tam tamanio lista
 * @return devuelve si hubo exito en el borrado
 */
int perro_borrarUno(ePerro perros[], int tam);

/**
 * @fn int perro_ModificarUno(ePerro[], int, int)
 * @brief modifica el perro a partir del id ingresado
 *
 * @param perros lista de perros
 * @param tam tamanio lista
 * @param idIngresado id ingresado para modificar el perro que el usuario desee
 * @return
 */
int perro_ModificarUno(ePerro perros[], int tam,int idIngresado);

/**
 * @fn int perro_promedioPorEdadDePerros(ePerro[], int)
 * @brief realiza el promedio por las edades de los perros
 *
 * @param perros lista perros
 * @param tam tamanio lista
 * @return devuelve si hubo exito en la modificacion
 */
int perro_promedioPorEdadDePerros(ePerro perros[], int tam);
//int perro_ModificarUno(ePerro perros[], int tam);

#endif /* PERROS_H_ */

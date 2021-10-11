/*
 * perros.c
 *
 *  Created on: 7 oct. 2021
 *      Author: PCNEW
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nexo.h"
#include "Inputs.h"


void perros_inicializarArray(ePerro perros[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		perros[i].estadoPerro = VACIO;
	}
}

void perro_hardCodearPerros(ePerro perros[], int tam) {
	int i;
	int id[] = { 7000, 7001, 7002 };
	char nombre[][21] = { "Lobo", "Sheila", "Reina" };
	char raza[][21] = { "Sharpei", "Golden", "Galgo" };
	int edad[] = { 2, 12, 13 };

	for (i = 0; i < tam - 2; i++) {
		perros[i].id = id[i];
		strcpy(perros[i].nombre, nombre[i]);
		strcpy(perros[i].raza, raza[i]);
		perros[i].edad = edad[i];
		perros[i].estadoPerro = OCUPADO;
	}
}

int perro_buscarEspacioLibre(ePerro perros[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(perros[i].estadoPerro == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

int perro_buscarPorId(ePerro perros[], int tam, int id)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(perros[i].estadoPerro == OCUPADO && perros[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}


void perro_mostrarUno(ePerro perro)
{
	printf("%-15d %-20s %-20s %-20d\n", perro.id, perro.nombre, perro.raza, perro.edad);
}

void perro_mostrarTodos(ePerro perros[], int tam)
{
	int i;
	printf("\nMostrando lista de perros...\n\n");
	for(i=0; i<tam; i++)
	{
		if(perros[i].estadoPerro == OCUPADO)
		{
			perro_mostrarUno(perros[i]);
		}
	}
	printf("\n");
}


int perro_cargarUno(ePerro perros[], int i,int ultimoId)
{
	int retorno = -1;

	perros[i].id=ultimoId+1;


	pedirCadena(perros[i].nombre, "Ingrese el nombre del perro: ", "Nombre invalido, hasta 21 caracteres, reingrese: ", 21);
	pedirCadena(perros[i].raza, "Ingrese la raza del perro: ", "Raza invalida, hasta 21 caracteres, reingrese: ", 21);
	pedirEntero(&perros[i].edad, "Ingrese la edad:  ", "Ingrese una edad valida (1-21): ", 1, 21);

	printf("\nPerro a agregar:\n\n%-15s %-20s %-20s %-20s\n", "ID", "NOMBRE", "RAZA", "EDAD");
	perro_mostrarUno(perros[i]);

	if(pedirConfirmacion("\nIngrese 's' para confirmar el alta del producto: ")==0)
	{
		perros[i].estadoPerro = OCUPADO;
		retorno = 0;
	}

	return retorno;
}


int perro_agregarPerro(ePerro perros[], int tam, int ultimoId)
{
	int retorno = -1;
	int index = perro_buscarEspacioLibre(perros, tam);

	if (index != -1)
	{
		printf("\n\n\n");
		if (perro_cargarUno(perros, index, ultimoId)==0) {
			printf("\nSe cargo el perro\n\n");
			retorno = 0;
		} else
		{
			printf("\nSe cancelo el alta del producto.\n\n");
		}
	} else
	{
		printf("\nError. No hay espacio disponible.\n\n");
	}

	return retorno;

}

int perro_borrarUno(ePerro perros[], int tam)
{
	int idIngresado;
	int index;
	int retorno = -1;


	pedirEntero(&idIngresado, "Ingrese el ID del perro que quiera darle de baja (7000-8000): ",
				"Reingrese el ID del perro que quiera darle de baja (7000-8000): ", 7000, 8000);
	index = perro_buscarPorId(perros, tam, idIngresado);

	if(index != -1)
	{
		printf("\nPerro a darle de baja:\n\n%-15s %-20s %-20s %-20s\n", "ID", "NOMBRE", "RAZA", "EDAD");
		perro_mostrarUno(perros[index]);

		if(pedirConfirmacion("\nIngrese 's' para confirmar la baja del producto: ")==0)
		{
			perros[index].estadoPerro = VACIO;
			printf("\nPerro %s dado de baja exitosamente\n\n", perros[index].nombre);
			retorno = 0;
		}
		else
		{
			printf("\nSe cancelo la baja del producto.\n\n");
		}
	}
	else
	{
		printf("\nError. Producto no encontrado...\n\n");
	}

	return retorno;
}

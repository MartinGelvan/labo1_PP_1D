/*
 * nexo.c
 *
 *  Created on: 8 oct. 2021
 *      Author: PCNEW
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "nexo.h"


void perro_Estadia__Fecha_mostrarUno(eEstadiaDiaria estadia, ePerro perro, eFecha fecha)
{
	printf("\n%-15d %-20s %-20d %-20d %-20d %-20d %-15d %-20s %-20s %-15d\n", estadia.id, estadia.nombreDuenio, estadia.telefonoContacto,fecha.dia,fecha.mes, fecha.anio, perro.id, perro.nombre, perro.raza, perro.edad);
}

void perro_Estadia_Fecha_mostrarTodos(ePerro perros[], int tam1, eEstadiaDiaria estadias[],int tam2, int tam3,eFecha fechas[])
{
	int i;

	printf("\nMostrando lista de las estadias...\n");
	printf("บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n");
	printf("%-15s %-20s %-20s %-20s %-20s %-20s %-15s %-20s %-20s %-15s\n", "ID", "NOMBRE DUENIO", "TELEFONO","DIA","MES","ANIO","ID PERRO","NOMBRE PERRO","RAZA PERRO","EDAD PERRO");
	printf("บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n");
	for(i=0; i<tam1; i++)
	{

		if(perros[i].estadoPerro == OCUPADO && estadias[i].estadoEstadia == OCUPADO && fechas[i].estadoFecha == OCUPADO )
		{

			perro_Estadia__Fecha_mostrarUno(estadias[i],perros[i], fechas[i]);

		}

	}
	printf("\n");
}

int perro_Estadia_Fecha_cargarUno(eEstadiaDiaria estadias[],int j,ePerro perros[], int i,eFecha fechas[],int k,int ultimoId)
{
	int retorno = -1;

	estadias[i].id=ultimoId+1;

	pedirCadena(estadias[j].nombreDuenio, "Ingrese nombre del duenio: ", "Nombre invalido, hasta 21 caracteres, reingrese: ", 21);
	pedirEntero(&estadias[j].telefonoContacto, "Ingrese su telefono de contacto:  ", "Ingrese un numero valido (1000000000-9999999999): ", 1500000000, 1599999999);
	pedirEntero(&perros[i].id, "Ingrese el id de su perro:  ", "Ingrese un numero valido (7003-8000): ", 7003, 8000);
	pedirEntero(&fechas[k].dia, "Ingrese el dia de su estadia:  ", "Ingrese un numero valido (1-30): ", 1, 30);
	pedirEntero(&fechas[k].mes, "Ingrese el mes de su estadia:  ", "Ingrese un numero valido (1-12): ", 1, 12);
	pedirEntero(&fechas[k].anio, "Ingrese el a๑o de su estadia:  ", "Ingrese un numero valido (2020-2030): ", 2020, 2030);
	pedirCadena(perros[i].nombre, "Ingrese el nombre del perro: ", "Nombre invalido, hasta 21 caracteres, reingrese: ", 21);
	pedirCadena(perros[i].raza, "Ingrese la raza del perro: ", "Raza invalida, hasta 21 caracteres, reingrese: ", 21);
	pedirEntero(&perros[i].edad, "Ingrese la edad:  ", "Ingrese una edad valida (1-21): ", 1, 21);
	estadias[j].idPerro=perros[i].id;
	printf("\nEstadia a agregar:\n\n%-15s %-20s %-20s %-20s %-15s %-15s %-20s %-20s %-15s %-15s\n", "ID DUENIO", "NOMBRE DUENIO", "TELEFONO CONTACTO", "DIA","MES", "ANIO","ID MASCOTA","NOMBRE PERRO","RAZA","EDAD PERRO");

	perro_Estadia__Fecha_mostrarUno(estadias[j], perros[k],fechas[k]);
	//perro_Estadia_Fecha_mostrarUno(estadias[j], perros[i], fechas[k]);

	if(pedirConfirmacion("\nIngrese 's' para confirmar el alta del producto: ")==0)
	{
		perros[i].estadoPerro = OCUPADO;
		estadias[j].estadoEstadia = OCUPADO;
		fechas[k].estadoFecha = OCUPADO;
		retorno = 0;
	}

	return retorno;
}


int perro_Estadia_Fecha_agregarEstadiaPerro(ePerro perros[],int tam,eEstadiaDiaria estadias[], int tam2, eFecha fechas[], int tam3, int ultimoId)
{
	int retorno = -1;
	int indexPerro = perro_buscarEspacioLibre(perros, tam);
	int indexEstadia = estadia_buscarEspacioLibre(estadias, tam2);
	int indexFecha = fecha_buscarEspacioLibre(fechas, tam3);

	if (indexPerro != -1 && indexEstadia!=-1 && indexFecha!=-1)
	{

		printf("\n\n\n");
		if (perro_Estadia_Fecha_cargarUno(estadias,indexEstadia,perros,indexPerro,fechas,indexFecha,ultimoId)==0) {
			printf("\nSe cargo la estadia\n\n");
			retorno = 0;
		} else
		{
			printf("\nSe cancelo el alta de la estadia.\n\n");
		}

	}else
	{
		printf("\nError. No hay espacio disponible.\n\n");
	}

	return retorno;

}


int perro_Estadia_ModificarUno(ePerro perros[],eEstadiaDiaria estadias[],eFecha fechas[], int tam, int tamPerro)
{
	int opcion;
	int idIngresado;

	int idPerroEncontrado;
	int index;
	int retorno = -1;

	eEstadiaDiaria auxEstadiaAmodificar;
	pedirEntero(&idIngresado, "Ingrese el ID de la estadia a modificar (100000-100020): ", "Reingrese el ID de la estadia a modificar (100000-100020): ", 100000,100020);
	index = estadia_buscarPorId(estadias, tam,idIngresado);


	if(index != -1)
	{
		printf("\nEstadia a modificar:\n\n%-15s %-20s %-20s\n", "ID", "NOMBRE DUENIO", "TELEFONO");
		printf("\nบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n");
		estadia_mostrarUno(estadias[index]);
		printf("\nบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n");

		do
		{
			auxEstadiaAmodificar = estadias[index];
			pedirEntero(&opcion, "บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n"
								 "1. MODIFICAR Telefono de contacto\n"
								 "2. MODIFICAR Perro\n"
								 "3. ATRAS\n"
								 "บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n"
								 "Ingrese una opcion: ",
								 "บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n"
								 "1. MODIFICAR Telefono de contacto\n"
								 "2. MODIFICAR Perro\n"
								 "3. ATRAS\n"
								 "บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n"
								 "Opcion invalida, reingrese la opcion (1-3): ", 1, 3);

			switch(opcion)
			{
				case 1:
					printf("\nEstadia a modificar:\n\n%-15s %-20s %-20s\n", "ID", "NOMBRE DUENIO", "TELEFONO");
					estadia_mostrarUno(estadias[index]);

					pedirEntero(&auxEstadiaAmodificar.telefonoContacto, "Ingrese su nuevo telefono de contacto: ",
								"Error, Reingrese de nuevo su telefono de contacto (Edad 0-8 anios): ",0,8);
					printf("\nEstadia modificada:\n\n%-15s %-20s %-20s\n", "ID", "NOMBRE DUENIO", "TELEFONO");
					estadia_mostrarUno(auxEstadiaAmodificar);

					if(pedirConfirmacion("\nIngrese 's' para confirmar la modificacion de la estadia: ")==0)
					{
						estadias[index].telefonoContacto=auxEstadiaAmodificar.telefonoContacto;
						printf("\nEstadia %d modificada exitosamente\n\n", estadias[index].id);
						retorno = 0;
					}
					else
					{
						printf("\nFue cancelada la modificacion de la estadia\n\n");
					}

					system("pause");
					break;
				case 2:

					idPerroEncontrado=perro_buscarPorId(perros,tamPerro, estadias[index].idPerro);
					printf("%d\n", estadias[index].idPerro);
					printf("%d\n", idPerroEncontrado);
					if(idPerroEncontrado!=-1)
					{
						printf("Hola");
						perro_ModificarUno(perros,tamPerro,idPerroEncontrado);
						printf("\nPerro %d modificado exitosamente\n\n", estadias[idPerroEncontrado].idPerro);
						retorno = 0;

					}else
					{
						printf("Ese perro no existe");
					}



					system("pause");
					break;
				case 3:
					break;

			}
		}while(opcion != 3);
	}
	else
	{
		printf("\nError, no se encuentra ese perro\n\n");
	}

	return retorno;
}

void estadia_ordenarEstadiasPorFechas(eEstadiaDiaria estadias[],int tam, eFecha fechas[])
{
	int i;
	int j;
	eEstadiaDiaria auxEstadia;

	for(i=0; i<tam-1; i++)
	{
		if(estadias[i].estadoEstadia == OCUPADO)
		{
			for(j=i+1; j<tam; j++)
			{
				if(fechas[i].estadoFecha == OCUPADO)
				{
					if((estadias[i].fecha.dia > estadias[j].fecha.dia) && (estadias[i].fecha.mes > estadias[j].fecha.mes) && (estadias[i].fecha.anio > estadias[j].fecha.anio))
					{
						auxEstadia= estadias[i];
						estadias[i] = estadias[j];
						estadias[j] = auxEstadia;
					}else
					{
						if((estadias[i].fecha.dia == estadias[j].fecha.dia) && (estadias[i].fecha.mes == estadias[j].fecha.mes) && (estadias[i].fecha.anio == estadias[j].fecha.anio) && strcmp(estadias[i].nombreDuenio , estadias[j].nombreDuenio)==1)
						{
							auxEstadia= estadias[i];
							estadias[i] = estadias[j];
							estadias[j] = auxEstadia;
						}
					}

				}

			}
		}

	}

	printf("\nLista de estadias ordenada correctamente\n\n");
}

int estadia_cancelarEstadia(eEstadiaDiaria estadias[], int tam, ePerro perros[], int tamPerro)
{
	int retorno = -1;
	int index;
	int idIngresado;
	int idPerroEncontrado;

	pedirEntero(&idIngresado, "Ingrese el ID de la estadia a cancelar (100000-170000): ",
				"Reingrese el ID de la estadia a cancelar (100000-170000): ", 100000, 170000);
	index = estadia_buscarPorId(estadias, tam, idIngresado);

	if(index != -1)
	{
		printf("\nEstadia a cancelar:\n\n%-5s %-20s %-20s\n", "ID", "NOMBRE DUENIO", "TELEFONO CONTACTO");
		printf("\nบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n");
		estadia_mostrarUno(estadias[index]);
		printf("\nบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ\n");

		idPerroEncontrado=perro_buscarPorId(perros,tamPerro, estadias[index].idPerro);




		if(pedirConfirmacion("\nIngrese 's' para confirmar la baja del producto: ")==0)
		{
			estadias[index].estadoEstadia = VACIO;
			perros[idPerroEncontrado].estadoPerro=VACIO;
			printf("\nEstadia %d cancelada exitosamente\n\n", estadias[index].id);
			retorno = 0;
		}
		else
		{
			printf("\nSe cancelo la cancelacion de la estadia.\n\n");
		}
	}
	else
	{
		printf("\nError, estadia no encontrada...\n\n");
	}

	return retorno;
}

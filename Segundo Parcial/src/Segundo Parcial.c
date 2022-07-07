/*****************************************************************************************************
*	Programa: Segundo Parcial
*
*	Objetivo:
*		se deberá realizar un programa que permita el análisis de dicho archivo y sea capaz de generar
*		nuevos archivos de salida de formato similar filtrados por varios criterios:
*			El programa contará con el siguiente menú:
*				1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos
*				del mismo.
*				2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de los servicios.
*				3) Asignar totales: Se deberá hacer uso de la función map la cual recibirá el linkedlist y una
*				función que asignará a cada servicio el total calculado de la siguiente forma: cantidad x
*				totalServicio.
*				4) Filtrar por tipo: Se deberá generar un archivo igual al original, pero donde solo aparezcan
*				servicios del tipo seleccionado.
*				5) Mostrar servicios: Se deberá mostrar por pantalla un listado de los servicios ordenados por
*				descripción de manera ascendente.
*				6) Guardar servicios: Se deberá guardar el listado del punto anterior en un archivo de texto.
*				7) Salir.
*
*	Version: 1.0 del 23 de Junio de 2022
*	Autor: Agustin Sbernini
*
******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Funciones_Extras.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Servicios.h"

int main(void) {

	int menuOpciones;
	int tipoAFiltrar;
	int ordenarYGuardar = 0;
	char path[TAM_DESCRIPCION];

	LinkedList* listaServicios = ll_newLinkedList();
	LinkedList* listaServiciosMinoristas = ll_newLinkedList();
	LinkedList* listaServiciosMayoristas = ll_newLinkedList();
	LinkedList* listaServiciosExportar = ll_newLinkedList();

	setbuf(stdout, NULL);

	do{
		utn_getInt(&menuOpciones, "\nMenu Principal: \n"
				"  1- Cargar archivo.\n"
				"  2- Imprimir lista.\n"
				"  3- Asignar totales.\n"
				"  4- Filtrar por tipo.\n"
				"  5- Mostrar servicios.\n"
				"  6- Guardar servicios.\n"
				"  7- Salir.\n"
				"Elija una opción: ", "\nError. Elija una opción valida.\n", 1, 7);

		switch(menuOpciones)
		{
		case 1:
			if(utn_getName(path, "\nIngrese el nombre del archivo que desea cargar: ", "\nError. Ingrese un nombre valido.\n") == 0)
			{
				if(controller_cargarServicios(path, listaServicios) == 0)
				{
					printf("\nLos datos han sido cargados exitosamente desde el archivo.\n");
				}
				else
				{
					printf("\nLos datos no se han podido cargar. Indique el nombre de una lista valida.\n");
				}
			}
			break;
		case 2:
			if(controller_ListServicios(listaServicios) != 0)
			{
				printf("\nError. No se pudo mostrar la lista, se encuentra vacía o es invalida.\n");
			}
			break;
		case 3:
			if(controller_asignarTotal(listaServicios) == 0)
			{
				printf("\nSe han asignado los totales de los servicios correctamente.\n");
			}
			else
			{
				printf("\nError. La lista se encuentra vacia.\n");
			}
			break;
		case 4:
			utn_getInt(&tipoAFiltrar, "\nOpciones a filtrar:\n"
					"  1- Minorista.\n"
					"  2- Mayorista.\n"
					"  3- Exportar.\n"
					"Elija una opcion: ", "\nError. Elija una opción valida.\n", 1, 3);
			switch(tipoAFiltrar)
			{
			case 1:
				listaServiciosMinoristas = controller_FiltrarTipo(listaServicios, tipoAFiltrar);

				if(listaServiciosMinoristas != NULL)
				{
					printf("\nSe ha filtrado por Minorista correctamente.\n");

					if(controller_guardarArchivos("minoristas.csv", listaServiciosMinoristas) == 0)
					{
						printf("\nSe ha guardado con exito la lista filtrada por Minoristas correctamente.\n");
					}
					else
					{
						printf("\nError. No se pudo guardar la lista filtrada.\n");
					}
				}
				else
				{
					printf("\nError. La lista se encuentra vacia o no hay servicios de este tipo.\n");
				}
				break;
			case 2:
				listaServiciosMayoristas = controller_FiltrarTipo(listaServicios, tipoAFiltrar);

				if(listaServiciosMayoristas != NULL)
				{
					printf("\nSe ha filtrado por Mayoristas correctamente.\n");

					if(controller_guardarArchivos("mayoristas.csv", listaServiciosMayoristas) == 0)
					{
						printf("\nSe ha guardado con exito la lista filtrada por Mayoristas correctamente.\n");
					}
					else
					{
						printf("\nError. No se pudo guardar la lista filtrada.\n");
					}
				}
				else
				{
					printf("\nError. La lista se encuentra vacia o no hay servicios de este tipo.\n");
				}
				break;
			case 3:
				listaServiciosExportar = controller_FiltrarTipo(listaServicios, tipoAFiltrar);

				if(listaServiciosExportar != NULL)
				{
					printf("\nSe ha filtrado por Exportar correctamente.\n");

					if(controller_guardarArchivos("exportar.csv", listaServiciosExportar) == 0)
					{
						printf("\nSe ha guardado con exito la lista filtrada por Exportar correctamente.\n");
					}
					else
					{
						printf("\nError. No se pudo guardar la lista filtrada.\n");
					}
				}
				else
				{
					printf("\nError. La lista se encuentra vacia o no hay servicios de este tipo.\n");
				}
				break;
			}
			break;
		case 5:
			if(controller_mostrarServiciosOrdenadosPorDescripcion(listaServicios) == 0)
			{
				ordenarYGuardar = 1;
			}
			else
			{
				printf("\nError. La lista se encuentra vacia.\n");
			}
			break;
		case 6:
			if(ordenarYGuardar == 1)
			{
				if(controller_guardarArchivos("data.txt", listaServicios) == 0)
				{
					printf("\nEl archivo fue guardado con exito en Modo Texto.\n");
				}
			}
			else
			{
				printf("\nError. Primero debe ordenar la lista antes de guardarla.\n");
			}
			break;
		default:
			printf("\nCerrando Sistema.\n");
		}

	}while(menuOpciones != 7);

	return 0;
}

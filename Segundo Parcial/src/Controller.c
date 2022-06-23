#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Servicios.h"
#include "Parser.h"

int controller_cargarServicios(char* ruta , LinkedList* pArrayServicios)
{
	int retorno = -1;

	if(pArrayServicios != NULL)
	{
		if (ruta != NULL)
		{
			if(ll_len(pArrayServicios) > 0)
			{
				ll_clear(pArrayServicios);
			}

			FILE* pArchivo;
			pArchivo = fopen (ruta,"r");

			if(pArchivo != NULL)
			{
				if(parser_Servicios(pArchivo, pArrayServicios) == 0)
				{
					retorno = 0;
				}
			}

			fclose(pArchivo);
		}
	}

    return retorno;
}

int controller_ListServicios(LinkedList* pArrayServicios)
{
	int retorno = -1;
	if(pArrayServicios != NULL)
	{
		int lenServicios;
		eServicios* servicioAux;

		lenServicios = ll_len(pArrayServicios);

		if(ll_isEmpty(pArrayServicios) == 0)
		{
			for(int i = 0; i < lenServicios; i++)
			{
				servicioAux = ll_get(pArrayServicios, i);
				Servicios_printOne(servicioAux);
			}
			retorno = 0;
		}
	}

    return retorno;
}

int controller_asignarTotal(LinkedList* pArrayServicios)
{
	int retorno = -1;
	int len;

	len = ll_len(pArrayServicios);

	if(pArrayServicios != NULL)
	{
		if(len > 0)
		{
			pArrayServicios = ll_map(pArrayServicios, Servicios_calcularTotales);

			retorno = 0;
		}
	}

	return retorno;
}

LinkedList* controller_FiltrarTipo(LinkedList* pArrayServicios, int tipoAFiltrar)
{
	LinkedList* pServicioFiltrado = NULL;
	int len;

	len = ll_len(pArrayServicios);

	if(pArrayServicios != NULL)
	{
		if(len > 0)
		{
			switch(tipoAFiltrar)
			{
			case 1:
				pServicioFiltrado = ll_filter(pArrayServicios, Servicios_filtrarMinorista);
				break;
			case 2:
				pServicioFiltrado = ll_filter(pArrayServicios, Servicios_filtrarMayorista);
				break;
			case 3:
				pServicioFiltrado = ll_filter(pArrayServicios, Servicios_filtrarExportar);
				break;
			}

			if(ll_len(pServicioFiltrado) == 0)
			{
				pServicioFiltrado = NULL;
			}
		}
	}

	return pServicioFiltrado;
}

int controller_guardarArchivos(char* ruta, LinkedList* pArrayServicios)
{
	int retorno = -1;

	if(ruta != NULL)
	{
		if(pArrayServicios != NULL)
		{
			FILE* pArchivo;
			eServicios* servicioAux;
			int id_servicio;
			char descripcion[TAM_DESCRIPCION];
			int tipo;
			float precioUnitario;
			int cantidad;
			float precioTotal;
			int len;

			len = ll_len(pArrayServicios);

			pArchivo = fopen(ruta, "w");

			if(len > 0)
			{
				if(pArchivo != NULL)
				{
					fprintf(pArchivo, "id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio\n");

					for(int i = 0; i < len; i++)
					{
						servicioAux = ll_get(pArrayServicios, i);

						if(servicioAux != NULL)
						{
							if(Servicios_getId(servicioAux, &id_servicio) == 0)
							{
								if(Servicios_getDescripcion(servicioAux, descripcion) == 0)
								{
									if(Servicios_getTipo(servicioAux, &tipo) == 0)
									{
										if(Servicios_getPrecioUnitario(servicioAux, &precioUnitario) == 0)
										{
											if(Servicios_getCantidad(servicioAux, &cantidad) == 0)
											{
												if(Servicios_getPrecioTotal(servicioAux, &precioTotal) == 0)
												{
													fprintf(pArchivo,"%d,%s,%d,%.2f,%d,%.2f\n",id_servicio,descripcion,tipo,precioUnitario,cantidad,precioTotal);

													retorno = 0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}

			fclose(pArchivo);
		}
	}

	return retorno;
}

int controller_mostrarServiciosOrdenadosPorDescripcion(LinkedList* pArrayServicios)
{
	int retorno = -1;
	int len;

	len = ll_len(pArrayServicios);

	if(pArrayServicios != NULL)
	{
		if(len > 0)
		{
			if(ll_sort(pArrayServicios, Servicios_ordenarPorDescripcion, 1) == 0)
			{
				if(controller_ListServicios(pArrayServicios) == 0)
				{
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

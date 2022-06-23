#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Servicios.h"
#include "Funciones_Extras.h"
#include "LinkedList.h"


eServicios* Servicios_new()
{
	eServicios* servicioAux;

	servicioAux = (eServicios*) malloc (sizeof(eServicios));

	return servicioAux;
}

eServicios* Servicios_newParametros(char* idStr,char* descripcionStr,char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* precioTotalStr)
{
	eServicios* servicioAux;
	servicioAux = Servicios_new();
	int error = 0;

	if(servicioAux != NULL)
	{
		if(Servicios_setId(servicioAux, atoi(idStr)) == 0)
		{
			if(Servicios_setDescripcion(servicioAux, descripcionStr) == 0)
			{
				if(Servicios_setTipo(servicioAux, atoi(tipoStr)) == 0)
				{
					if(Servicios_setPrecioUnitario(servicioAux, atof(precioUnitarioStr)) == 0)
					{
						if(Servicios_setCantidad(servicioAux, atoi(cantidadStr)) == 0)
						{
							if(Servicios_setPrecioTotal(servicioAux, atof(precioTotalStr)) == 0)
							{
								error = 1;
							}
						}
					}
				}
			}
		}
	}

	if(error != 1)
	{
		servicioAux = NULL;
	}

	return servicioAux;
}

int Servicios_setId(eServicios* Servicio,int idServicio)
{
	int retorno = -1;

	if(Servicio != NULL && idServicio > 0)
	{
		Servicio->id_servicio = idServicio;
		retorno = 0;
	}

	return retorno;
}
int Servicios_getId(eServicios* Servicio,int* idServicio)
{
	int retorno = -1;

	if(Servicio != NULL && idServicio != NULL)
	{
		*idServicio = Servicio->id_servicio;
		retorno = 0;
	}

	return retorno;
}

int Servicios_setDescripcion(eServicios* Servicio,char* descripcionServicio)
{
	int retorno = -1;

	if(Servicio != NULL && descripcionServicio != NULL)
	{
		strcpy(Servicio->descripcion, descripcionServicio);
		retorno = 0;
	}

	return retorno;
}
int Servicios_getDescripcion(eServicios* Servicio,char* descripcionServicio)
{
	int retorno = -1;

	if(Servicio != NULL && descripcionServicio != NULL)
	{
		strcpy(descripcionServicio, Servicio->descripcion);
		retorno = 0;
	}

	return retorno;
}

int Servicios_setTipo(eServicios* Servicio,int tipoServicio)
{
	int retorno = -1;

	if(Servicio != NULL && tipoServicio >= 1 && tipoServicio <= 3)
	{
		Servicio->tipo = tipoServicio;
		retorno = 0;
	}

	return retorno;
}
int Servicios_getTipo(eServicios* Servicio,int* tipoServicio)
{
	int retorno = -1;

	if(Servicio != NULL && tipoServicio != NULL)
	{
		*tipoServicio = Servicio->tipo;
		retorno = 0;
	}

	return retorno;
}

int Servicios_setPrecioUnitario(eServicios* Servicio,float precioUnitarioServicio)
{
	int retorno = -1;

	if(Servicio != NULL && precioUnitarioServicio > 0)
	{
		Servicio->precioUnitario = precioUnitarioServicio;
		retorno = 0;
	}

	return retorno;
}
int Servicios_getPrecioUnitario(eServicios* Servicio,float* precioUnitarioServicio)
{
	int retorno = -1;

	if(Servicio != NULL && precioUnitarioServicio != NULL)
	{
		*precioUnitarioServicio = Servicio->precioUnitario;
		retorno = 0;
	}

	return retorno;
}

int Servicios_setCantidad(eServicios* Servicio,int cantidadServicio)
{
	int retorno = -1;

	if(Servicio != NULL && cantidadServicio > 0)
	{
		Servicio->cantidad = cantidadServicio;
		retorno = 0;
	}

	return retorno;
}
int Servicios_getCantidad(eServicios* Servicio,int* cantidadServicio)
{
	int retorno = -1;

	if(Servicio != NULL && cantidadServicio != NULL)
	{
		*cantidadServicio = Servicio->cantidad;
		retorno = 0;
	}

	return retorno;
}

int Servicios_setPrecioTotal(eServicios* Servicio,float precioTotalServicio)
{
	int retorno = -1;

	if(Servicio != NULL && precioTotalServicio >= 0)
	{
		Servicio->precioTotal = precioTotalServicio;
		retorno = 0;
	}

	return retorno;
}
int Servicios_getPrecioTotal(eServicios* Servicio,float* precioTotalServicio)
{
	int retorno = -1;

	if(Servicio != NULL && precioTotalServicio != NULL)
	{
		*precioTotalServicio = Servicio->precioTotal;
		retorno = 0;
	}

	return retorno;
}

void Servicios_printOne(eServicios* Servicio)
{
	if(Servicio != NULL)
	{
		int id_servicio;
		char descripcion[TAM_DESCRIPCION];
		int tipo;
		char tipoStr[TAM_RESTODATOS];
		float precioUnitario;
		int cantidad;
		float precioTotal;

		if(Servicio != NULL)
		{
			if(Servicios_getId(Servicio, &id_servicio) == 0)
			{
				if(Servicios_getDescripcion(Servicio, descripcion) == 0)
				{
					if(Servicios_getTipo(Servicio, &tipo) == 0)
					{
						if(Servicios_getPrecioUnitario(Servicio, &precioUnitario) == 0)
						{
							if(Servicios_getCantidad(Servicio, &cantidad) == 0)
							{
								if(Servicios_getPrecioTotal(Servicio, &precioTotal) == 0)
								{
									switch(tipo)
									{
									case 1:
										strcpy(tipoStr, "MINORISTA");
										break;
									case 2:
										strcpy(tipoStr,"MAYORISTA");
										break;
									case 3:
										strcpy(tipoStr,"EXPORTAR");
										break;
									}
									printf("%-6d %-23s %-15s %-9.2f %5d %10.2f\n", id_servicio, descripcion, tipoStr, precioUnitario, cantidad, precioTotal);
								}
							}
						}
					}
				}
			}
		}
	}
}

void Servicios_calcularTotales(void* pServicio)
{
	float precioUnitario;
	int cantidad;
	float precioTotal;

	if(pServicio != NULL)
	{
		if(Servicios_getPrecioUnitario(pServicio, &precioUnitario) == 0)
		{
			if(Servicios_getCantidad(pServicio, &cantidad) == 0)
			{
				precioTotal = precioUnitario * cantidad;

				Servicios_setPrecioTotal(pServicio, precioTotal);
			}
		}
	}
}

int Servicios_filtrarMinorista (void* pServicio)
{
	int retorno;
	int tipo;

	if(pServicio != NULL)
	{
		if(Servicios_getTipo(pServicio, &tipo) == 0)
		{
			if(tipo == 1)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

int Servicios_filtrarMayorista (void* pServicio)
{
	int retorno;
	int tipo;

	if(pServicio != NULL)
	{
		if(Servicios_getTipo(pServicio, &tipo) == 0)
		{
			if(tipo == 2)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

int Servicios_filtrarExportar (void* pServicio)
{
	int retorno;
	int tipo;

	if(pServicio != NULL)
	{
		if(Servicios_getTipo(pServicio, &tipo) == 0)
		{
			if(tipo == 3)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

int Servicios_ordenarPorDescripcion(void* servicio1, void* servicio2)
{
	int retorno = -1;
	char descripcionUno[TAM_DESCRIPCION];
	char descripcionDos[TAM_DESCRIPCION];

	if(servicio1 != NULL && servicio2 != NULL)
	{
		Servicios_getDescripcion(servicio1, descripcionUno);
		Servicios_getDescripcion(servicio2, descripcionDos);

		retorno = strcmp(descripcionUno, descripcionDos);
	}

	return retorno;
}

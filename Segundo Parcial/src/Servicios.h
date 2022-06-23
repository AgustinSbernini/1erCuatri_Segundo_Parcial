#ifndef SERVICIOS_H_
#define SERVICIOS_H_

#define TAM_DESCRIPCION 50
#define TAM_RESTODATOS 20

typedef struct
{
	int id_servicio;
	char descripcion[TAM_DESCRIPCION];
	int tipo;
	float precioUnitario;
	int cantidad;
	float precioTotal;
}eServicios;

#endif

/**
 * @brief crea un dato de tipo eServicios en memoria dinamica con todos sus campos vacios
 *
 * @return retorna NULL si hubo un error - el servicio creado si funciona
 */
eServicios* Servicios_new();

/**
 * @brief crea un dato de tipo eServicios en memoria dinamica con todos sus campos asignados correspondientemente
 *
 * @param idStr id del servicio en tipo string
 * @param descripcionStr descripcion del servicio en tipo string
 * @param tipoStr tipo del servicio en tipo string
 * @param precioUnitarioStr precio unitario del servicio en tipo string
 * @param cantidadStr cantidad del servicio en tipo string
 * @param precioTotalStr precio total del servicio en tipo string
 * @return retorna NULL si hubo un error -  el servicio creado con todos los parametros convertidos a sus tipos correspondientes y asignados si funciona
 */
eServicios* Servicios_newParametros(char* idStr,char* descripcionStr,char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* precioTotalStr);

/**
 * @brief se le asigna el id recibido por parametro al Servicio
 *
 * @param Servicio puntero al array de los servicios
 * @param idServicio int id a asignar
 * @return retorna -1 si hubo un error - 0 si funciona
 */
int Servicios_setId(eServicios* Servicio,int idServicio);
/**
 * @brief consigue el id del Servicio y lo devuelve por parametro
 *
 * @param Servicio puntero al array de los servicios
 * @param idServicio puntero int id a devolver
 * @return retorna -1 si hubo un error - 0 si funciona
 */
int Servicios_getId(eServicios* Servicio,int* idServicio);

/**
 * @brief se le asigna la descripcion recibida por parametro al Servicio
 *
 * @param Servicio puntero al array de los servicios
 * @param descripcionServicio string de la descripcion a asignar
 * @return retorna -1 si hubo un error - 0 si funciona
 */
int Servicios_setDescripcion(eServicios* Servicio,char* descripcionServicio);
/**
 * @brief consigue la descripcion del Servicio y lo devuelve por parametro
 *
 * @param Servicio puntero al array de los servicios
 * @param descripcionServicio string por donde se retorna la descripcion
 * @return retorna -1 si hubo un error - 0 si funciona
 */
int Servicios_getDescripcion(eServicios* Servicio,char* descripcionServicio);

/**
 * @brief se le asigna el tipo recibido por parametro al Servicio
 *
 * @param Servicio puntero al array de los servicios
 * @param tipoServicio int tipo de servicio a asignar
 * @return -1 si hubo un error - 0 si funciona
 */
int Servicios_setTipo(eServicios* Servicio,int tipoServicio);
/**
 * @brief consigue el tipo del Servicio y lo devuelve por parametro
 *
 * @param Servicio puntero al array de los servicios
 * @param tipoServicio puntero int tipo a devolver
 * @return -1 si hubo un error - 0 si funciona
 */
int Servicios_getTipo(eServicios* Servicio,int* tipoServicio);

/**
 * @brief se le asigna el precio unitario recibido por parametro al Servicio
 *
 * @param Servicio puntero al array de los servicios
 * @param precioUnitarioServicio float precio unitario del servicio a asignar
 * @return -1 si hubo un error - 0 si funciona
 */
int Servicios_setPrecioUnitario(eServicios* Servicio,float precioUnitarioServicio);
/**
 * @brief consigue el precio unitario del Servicio y lo devuelve por parametro
 *
 * @param Servicio puntero al array de los servicios
 * @param precioUnitarioServicio puntero float precio unitario a devolver
 * @return -1 si hubo un error - 0 si funciona
 */
int Servicios_getPrecioUnitario(eServicios* Servicio,float* precioUnitarioServicio);

/**
 * @brief se le asigna la cantidad recibida por parametro al Servicio
 *
 * @param Servicio puntero al array de los servicios
 * @param cantidadServicio int cantidad del servicio a asignar
 * @return -1 si hubo un error - 0 si funciona
 */
int Servicios_setCantidad(eServicios* Servicio,int cantidadServicio);
/**
 * @brief consigue la cantidad del Servicio y lo devuelve por parametro
 *
 * @param Servicio puntero al array de los servicios
 * @param cantidadServicio puntero int cantidad a devolver
 * @return -1 si hubo un error - 0 si funciona
 */
int Servicios_getCantidad(eServicios* Servicio,int* cantidadServicio);

/**
 * @brief se le asigna el precio total recibido por parametro al Servicio
 *
 * @param Servicio puntero al array de los servicios
 * @param precioTotalServicio puntero float precio total del servicio a asignar
 * @return -1 si hubo un error - 0 si funciona
 */
int Servicios_setPrecioTotal(eServicios* Servicio,float precioTotalServicio);
/**
 * @brief consigue el precio total del Servicio y lo devuelve por parametro
 *
 * @param Servicio puntero al array de los servicios
 * @param precioTotalServicio puntero float total unitario a devolver
 * @return -1 si hubo un error - 0 si funciona
 */
int Servicios_getPrecioTotal(eServicios* Servicio,float* precioTotalServicio);

/**
 * @brief Verifica que los datos ingresados sean correctos e imprime en forma de tabla un Servicio
 *
 * @param Servicio puntero a la lista de servicios
 */
void Servicios_printOne(eServicios* Servicio);

/**
 * @brief Recibe el Servicio, consigue el precio unitario y la cantidad y le asigna el precio total
 *
 * @param pServicio Servicio al cual se le calcula el total
 */
void Servicios_calcularTotales(void* pServicio);

/**
 * @brief recibe el servicio y obtiene su tipo para comparar
 *
 * @param pServicio Servicio del cual se obtiene el tipo
 * @return devuele 1 si el servicio es Minorista - 0 si no es Minorista
 */
int Servicios_filtrarMinorista (void* pServicio);

/**
 * @brief recibe el servicio y obtiene su tipo para comparar
 *
 * @param pServicio Servicio del cual se obtiene el tipo
 * @return devuele 1 si el servicio es Mayorista - 0 si no es Mayorista
 */
int Servicios_filtrarMayorista (void* pServicio);

/**
 * @brief recibe el servicio y obtiene su tipo para comparar
 *
 * @param pServicio Servicio del cual se obtiene el tipo
 * @return devuele 1 si el servicio es Exportar - 0 si no es Exportar
 */
int Servicios_filtrarExportar (void* pServicio);

/**
 * @brief obtiene la descripcion de dos servicios y las compara para saber cual va primero alfabeticamente
 *
 * @param servicio1 Servicio del cual se obtiene la descripcion a comparar
 * @param servicio2 Servicio del cual se obtiene la descripcion a comparar
 * @return retorna un valor mayor a 0 si servicio1 va primero, menor a 0 si servicio1 va despues o 0 si son iguales
 */
int Servicios_ordenarPorDescripcion(void* servicio1, void* servicio2);

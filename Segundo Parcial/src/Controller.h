#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Carga los datos de los servicios desde el archivo
 *
 * \param ruta char* ruta del archivo desde el cual se cargan los servicios
 * \param pServicio LinkedList* puntero a la lista de Servicios
 * \return int retorna -1 si hubo un error - 0 si funciona
 *
 */
int controller_cargarServicios(char* ruta , LinkedList* pServicio);

/**
 * @brief Carga un elemento de la LinkedList en un auxiliar y lo imprime por consola
 *
 * @param pArrayServicios LinkedList* puntero a la lista de Servicios
 * @return int retorna -1 si hubo un error - 0 si funciona
 */
int controller_ListServicios(LinkedList* pArrayServicios);

/**
 * @brief Utiliza la funcion ll_map y Servicios_calcularTotales para calcular y asignar el precio total
 *
 * @param pArrayServicios LinkedList* puntero a la lista de Servicios
 * @return int retorna -1 si hubo un error - 0 si funciona
 */
int controller_asignarTotal(LinkedList* pArrayServicios);

/**
 * @brief Recorre el LinkedList hasta encontrar la coincidencia en el tipo seleccionado y agrega
 * 		  dicho elemento a una nueva lista
 *
 * @param pArrayServicios LinkedList* puntero a la lista de Servicios
 * @param tipoAFiltrar int selecciona cual tipo va a ser filtrado
 * @return LinkedList* puntero a la nueva lista creada
 */
LinkedList* controller_FiltrarTipo(LinkedList* pArrayServicios, int tipoAFiltrar);

/**
 * @brief Guarda la lista en un archivo en modo csv o txt dependiendo de la opcion
 *
 * @param ruta char* ruta del archivo al cual se le van a guardar los servicios
 * @param pArrayServicios LinkedList* puntero a la lista de Servicios
 * @return int retorna -1 si hubo un error - 0 si funciona
 */
int controller_guardarArchivos(char* ruta, LinkedList* pArrayServicios);

/**
 * @brief Ordena la lista por descripcion en orden ascendente y los imprime por consola
 *
 * @param pArrayServicios LinkedList* puntero a la lista de Servicios
 * @return int retorna -1 si hubo un error - 0 si funciona
 */
int controller_mostrarServiciosOrdenadosPorDescripcion(LinkedList* pArrayServicios);

#endif

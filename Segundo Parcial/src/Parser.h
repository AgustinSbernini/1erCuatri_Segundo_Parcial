#ifndef PARSER_H_
#define PARSER_H_

/**
 * @brief Parsea los datos de los servicios
 *
 * @param pArchivo char* puntero al archivo guardado
 * @param pArrayServicios puntero al array de los servicios
 * @return int retorna -1 en caso de error - 0 si funciona
 */

int parser_Servicios(FILE* pArchivo, LinkedList* pArrayServicios);

#endif

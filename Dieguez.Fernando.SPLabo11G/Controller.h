#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "Pais.h"

//Paises
//paises
//Paises
//paises
//Paises
//paises

/** \brief Busca un empleado especifico por su id
 *
 * \param pArrayListPais LinkedList*
 * \param id int
 * \return int
 *
 */
int findPais(LinkedList* pArrayListPais, int id);

/** \brief Busca el proximo id
 *
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int getNextId(LinkedList* pArrayListPais);
/** \brief buscar un indice en la lista
 *
 * \param pArrayListPais LinkedList*
 * \param int* pIndice
 * \return int
 *
 */
int findPlace(LinkedList* pArrayListPais, int* pIndice);
/** \brief Busca el mayor id de los paises que estan cargados
 *
 * \param pArrayListPais LinkedList*
 * \param id int*
 * \return int
 *
 */
int getBiggestId(LinkedList* pArrayListPais, int* id);


/** \brief Carga los datos de los paises desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPais);

/** \brief Carga los datos de los paises desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListPais);

/** \brief Alta de paises
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_addPais(LinkedList* pArrayListPais, int* id);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_editPais(LinkedList* pArrayListPais);
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_removePais(LinkedList* pArrayListPais);
/** \brief Listar paises
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_ListPais(LinkedList* pArrayListPais);
/** \brief Ordenar paises
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_sortPais(LinkedList* pArrayListPais);


/** \brief filtrar paises
 *
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_filterPais(LinkedList* pArrayListPais);

/** \brief Guarda los datos de los paises en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_saveAsText(LinkedList* pArrayListPais);
/** \brief Guarda los datos de los paises en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(LinkedList* pArrayListPais);

/** \brief limpia el linkedlist para que no muestre basura en el sexo y edad de los paises
 *
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int controller_cleanAge(LinkedList* pArrayListPais);

/** \brief carga automaticamente valores aleatorios para las vacunas
 *
 * \param pArrayListPais LinkedList*
 * \return ePais pais cargado
 *
 */
void* controller_hardcodeVacunas(void* pPais);

/** \brief carga una lista nueva con los valores de la anterior y con la funcion carga valores aleatorios
 *
 * \param void* (pFunc)(void funcion que se va a utilizar para la carga aleatoria
 * \return LinkedList* nueva linked list de retorno
 *
 */
LinkedList* ll_map(LinkedList* this, void* (pFunc)(void*));

/** \brief devuelve el pais mas castigado
 *
 * \param LinkedList* this lista
 * \param
 * \return ePais* pais resultante
 *
 */
int mayorCantidadSinVacunas(LinkedList* lista);
#endif // CONTROLLER_H_INCLUDED

#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

//Paises
//paises
//Paises
//paises
//Pais
//pais

/** \brief Muestra las opciones para el sistema de gestion
 *
 * \return int devuelve la opcion escogida por el usuario
 *
 */
int menu();


/** \brief imprime un texto calculando el ancho del texto y el ancho del contenedor y lo centra
 *
 * \return void
 * \param char* text texto a centrar e imprimir
 * \param int totalWidth ancho total del contenedor
 *
 */
void centerText(char* text, int totalWidth);

/** \brief Imprime el titulo para mostrar el listado de paises
 *
 * \return void
 *
 */
void printPaisTitle();

/** \brief Imprime una linea a lo largo de la pantalla para actuar de divisor
 *
 *
 */
void printDivisor();

/** \brief Imprime una linea a lo largo de la pantalla para actuar de divisor (menos densidad que la linea comun)
 *
 * \return void
 *
 */
void printTableDivisor();
/** \brief Muestra las opciones de edicion
 *
 * \return int devuelve la opcion escogida por el usuario
 *
 */
int editUI();

/** \brief Muestra las opciones de ordenacion
 *
 * \return int devuelve la opcion escogida por el usuario
 *
 */
int sortUI();

/** \brief Muestra las opciones de filtrado
 *
 * \return int devuelve la opcion escogida por el usuario
 *
 */
int filterUI();

#endif // UI_H_INCLUDED

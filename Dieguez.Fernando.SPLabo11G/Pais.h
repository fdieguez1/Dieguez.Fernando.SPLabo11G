#ifndef pais_H_INCLUDED
#define pais_H_INCLUDED

//Paises
//paises
//Paises
//paises
//Pais
//pais

typedef struct
{
    int id;
    char nombre[128];
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;
} ePais;


/** \brief Genera un nuevo empleado vacio inicializado en 0
 *
 * \return ePais*
 *
 */
ePais* pais_new();
/** \brief Genera un nuevo empleado con parametros string
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param vac1DosisStr char*
 * \param vac2DosisStr char*
 * \return ePais*
 *
 */
ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1DosisStr, char* vac2DosisStr);
/** \brief Genera un nuevo empleado
 *
 * \param id int
 * \param nombre char*
 * \param horas int
 * \param vac2Dosis int
 * \return ePais*
 *
 */
ePais* newePaisParam(int id, char* nombre, int horas, int vac2Dosis);
/** \brief Elimina un empleado
 *
 * \param this ePais*
 * \return int
 *
 */
int pais_delete(ePais* this);

//getters
/** \brief Get by id
 *
 * \param this ePais*
 * \param id int*
 * \return int
 *
 */
int pais_getId(ePais* this,int* id);
/** \brief Get by nombre
 *
 * \param this ePais*
 * \param nombre char*
 * \return int
 *
 */
int pais_getNombre(ePais* this,char* nombre);
/** \brief  get horas trabajadas
 *
 * \param this ePais*
 * \param vac1Dosis int*
 * \return int
 *
 */
int pais_getVac1Dosis(ePais* this,int* vac1Dosis);
/** \brief Get by vac2Dosis
 *
 * \param this ePais*
 * \param vac2Dosis int*
 * \return int
 *
 */
int pais_getVac2Dosis(ePais* this,int* vac2Dosis);

//setters
/** \brief Set id
 *
 * \param this ePais*
 * \param id int
 * \return int
 *
 */
int pais_setId(ePais* this,int id);

/** \brief Set nombre
 *
 * \param this ePais*
 * \param nombre char*
 * \return int
 *
 */
int pais_setNombre(ePais* this,char* nombre);

/** \brief set horas trabajadas
 *
 * \param this ePais*
 * \param vac1Dosis int
 * \return int
 *
 */
int pais_setVac1Dosis(ePais* this,int vac1Dosis);


/** \brief setea el vac2Dosis de un empleado
 *
 * \param this ePais*
 * \param vac2Dosis int
 * \return int
 *
 */
int pais_setVac2Dosis(ePais* this,int vac2Dosis);

/** \brief Muestra un solo empleado
 *
 * \param this ePais*
 * \return int
 *
 */
int mostrarPais(ePais* this);

/** \brief Ordena comparando id
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int pais_cmpId(void* a, void* b);

/** \brief Ordena comparando horas
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int pais_cmpHours(void* a, void* b);

/** \brief Ordena comparando vac2Dosiss
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int pais_cmpSalary(void* a, void* b);

/** \brief Ordena comparando nombres
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int pais_cmpName(void* a, void* b);


/** \brief  devuelve si un pais es mayor de sinVacunar
 *
 * \param pais void*
 * \return int devuelve 1 si lo es 0 si no
 *
 */
int mayorDeSinVacunar(void* pais);

/** \brief  devuelve si un pais es mayor de sinVacunar
 *
 * \param pais void*
 * \return int devuelve 1 si lo es 0 si no
 *
 */
int esExitoso(void* pais);

/** \brief  devuelve si un pais es mayor de sinVacunar
 *
 * \param pais void*
 * \return int devuelve 1 si lo es 0 si no
 *
 */
int masCastigado(void* pais);

/** \brief  devuelve si un pais es mayor de sinVacunar
 *
 * \param pais void*
 * \return int devuelve 1 si lo es 0 si no
 *
 */
int alHorno(void* pais);

/** \brief  devuelve si un pais se llama Fernando
 *
 * \param pais void*
 * \return int devuelve 1 si lo es, 0 si no
 *
 */
int esFernando(void* pais);

/** \brief get horas para empleado
 *
 * \param this ePais*
 * \param vac2Dosis int*
 * \return int
 *
 */
int pais_getSinVacunar(ePais* this,int* vac2Dosis);
/** \brief setea la sinVacunar de un empleado
 *
 * \param this ePais*
 * \param vac2Dosis int
 * \return int
 *
 */
int pais_setSinVacunar(ePais* this,int sinVacunar);
/** \brief setea el sexo de un empleado
 *
 * \param this ePais*
 * \param vac2Dosis int
 * \return int
 *
 */
int pais_setSexo(ePais* this,char sexo);

/** \brief compara la vacunacion total entre dos paises
 *
 * \param a void* pais a
 * \param b void* pais b
 * \return int devuelve si a tiene mas vacunas que b
 *
 */
int pais_cmpVacTotal(void* a, void* b);
#endif // pais_H_INCLUDED

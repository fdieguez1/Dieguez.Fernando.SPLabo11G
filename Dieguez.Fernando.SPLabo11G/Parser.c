#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Pais.h"
#include "Controller.h"

//Paises
//paises
//Paises
//paises
//Pais
//pais

/** \brief Parsea los datos los datos de los paises desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int parser_PaisFromText(FILE* pFile, LinkedList* pArrayListePais)
{
    ePais* auxEmp = NULL;
    int cant;
    char buffer[5][128];
    int todoOk = 0;
    int id;
    char nombre[128];
    int vac2Dosis;
    int horas;
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);//lectura fantasma del encabezado
    do
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
        if(cant < 4)
        {
            break;
        }
        id = atoi(buffer[0]);
        strcpy( nombre, buffer[1]);
        horas = atoi(buffer[2]);
        vac2Dosis = atoi(buffer[3]);
        auxEmp = newePaisParam(id, nombre, horas, vac2Dosis);
        if(auxEmp != NULL)
        {
            ll_add(pArrayListePais, (ePais*)auxEmp);
            todoOk = 1;
        }
    }
    while(!feof(pFile));
    return todoOk;
}

/** \brief Parsea los datos los datos de los paises desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int parser_PaisFromBinary(FILE* pFile, LinkedList* pArrayListePais)
{
    int todoOk = 0;
    ePais auxEmp;
    ePais* auxiliar = NULL;

    if(pFile != NULL && pArrayListePais != NULL)
    {
        while(!feof(pFile))
        {
            if(fread((ePais*)&auxEmp, sizeof(ePais), 1, pFile) == 1)
            {
                auxiliar = newePaisParam(auxEmp.id, auxEmp.nombre, auxEmp.vac1Dosis, auxEmp.vac2Dosis);
                if(auxiliar != NULL && ll_add(pArrayListePais, (ePais*)auxiliar) == 0)
                {
                    todoOk = 1;
                }
            }
        }
    }

    return todoOk;
}

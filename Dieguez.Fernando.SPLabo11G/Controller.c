#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Pais.h"
#include "ui.h"
#include "inputs.h"
#include "parser.h"
#include "Randomizer.h"


int findPais(LinkedList* pArrayListPais, int id)
{
    int indice = -1;
    ePais* auxPais;
    if(pArrayListPais != NULL)
    {
        if(ll_len(pArrayListPais) > 0)
        {
            for(int i=0; i< ll_len(pArrayListPais); i++)
            {
                auxPais =  (ePais*)ll_get(pArrayListPais, i);
                if(auxPais != NULL && auxPais->id == id)
                {
                    indice = i;
                    break;
                }
            }
        }
    }
    return indice;
}

int getNextId(LinkedList* pArrayListPais)
{
    int maxVal = -1;
    int tam = 0;
    int i;
    int cant = 0;
    ePais* paisAux;
    if(pArrayListPais != NULL)
    {
        tam = ll_len(pArrayListPais);

        if(tam > 0)
        {
            for(i = 0; i < tam; i++)
            {
                paisAux = (ePais*)ll_get(pArrayListPais, i);

                if(paisAux != NULL)
                {
                    if(cant == 0)
                    {
                        maxVal= paisAux->id;
                    }
                    else
                    {
                        if(paisAux->id > maxVal
                                && paisAux->id < 1000)
                        {
                            maxVal= paisAux->id;
                        }
                    }

                    cant++;
                }
            }
        }
        if(cant > 0)
        {
            maxVal++;
        }
        else
        {
            maxVal= 1;
        }
    }

    return maxVal;
}

int findPlace(LinkedList* pArrayListPais, int* pIndice)
{
    int todoOk = 0;
    *pIndice = -1;
    ePais* paisAux = NULL;
    if(pArrayListPais != NULL && ll_len(pArrayListPais) > 0 && pIndice != NULL)
    {
        for(int i=0; i<ll_len(pArrayListPais); i++)
        {
            paisAux = (ePais*)ll_get(pArrayListPais, i);
            if(paisAux == NULL)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
int getBiggestId(LinkedList* pArrayListPais, int* id)
{
    int todoOk = 0;
    ePais* auxPais = NULL;
    int mayorId;
    if(pArrayListPais != NULL)
    {
        for(int i=0; i<ll_len(pArrayListPais); i++)
        {
            auxPais = (ePais*)ll_get(pArrayListPais, i);
            if(i==0 || auxPais->id > mayorId)
            {
                mayorId = auxPais->id;
            }
        }
        *id = mayorId + 1;
        todoOk =1;
    }
    return todoOk;
}

int controller_loadFromText(char* path, LinkedList* pArrayListPais)
{
    int todoOk = 0;
    FILE* f = NULL;
    if(pArrayListPais != NULL && path != NULL)
    {
        f = fopen(path, "r");
        if(f != NULL)
        {
            parser_PaisFromText(f, pArrayListPais);
            todoOk = 1;
        }
        else
        {
            printf("Error al abrir el archivo\n");
        }
    }
    fclose(f);
    return todoOk;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListPais)
{
    int todoOk = 0;
    FILE* f = NULL;
    if(pArrayListPais != NULL)
    {
        f = fopen(path, "rb");
        if(f != NULL)
        {
            parser_PaisFromBinary(f, pArrayListPais);
            todoOk = 1;
        }
        else
        {
            printf("No se pudo abrir el archivo\n");
        }
    }
    return todoOk;
}

int controller_addPais(LinkedList* pArrayListPais, int* pId)
{
    int todoOk = 0;
    char nombre[128];
    int vac1Dosis;
    int vac2Dosis;
    ePais* nuevoEmpleado = NULL;
    if(pArrayListPais != NULL)
    {
        system("cls");
        printf("Alta de empleado\n\n");
        if(*pId == -1)
        {
            printf("\nNo se encontro lugar en el sistema\n");
        }
        else
        {
            printf("Ingrese Nombre: ");
            getString(nombre);
            utn_getNumero(&vac1Dosis, "Ingrese las horas trabajadas: ", "Error!!! --> Ingrese un numero valido", 0, 9999999, 100);
            utn_getNumero(&vac2Dosis, "Ingrese el vac2Dosis: ", "Error!!! --> Ingrese un numero valido", 0, 9999999, 100);

            nuevoEmpleado = newePaisParam(*pId, nombre, vac1Dosis, vac2Dosis);

            if(nuevoEmpleado != NULL)
            {
                ll_add(pArrayListPais, (ePais*)nuevoEmpleado);
                (*pId)++;
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

int controller_editPais(LinkedList* pArrayListPais)
{
    ePais* auxPais = pais_new();
    ePais* auxNuevoEmpParam;
    int todoOk = 0;
    int indice;
    int id;
    system("cls");
    if(ll_len(pArrayListPais)== 0)
    {
        todoOk = -1;
    }
    else
    {
        system("cls");
        printf("Modificar empleado\n\n");
        controller_ListPais(pArrayListPais);
        utn_getNumero(&id, "Ingrese un Id:", "Error!!! --> Ingrese un numero correcto", 0,999999,100);
        if(pArrayListPais != NULL)
        {
            indice = findPais(pArrayListPais, id);
            if(indice == -1)
            {
                printf("Error!!! --> No se encontro el empleado ingresado");
            }
            else
            {
                printf("\n\nId                  Nombre Horas    Sueldo\n");
                mostrarPais((ePais*) ll_get(pArrayListPais, indice));
                auxPais = (ePais*) ll_get(pArrayListPais, indice);
                if(auxPais != NULL)
                {
                    auxNuevoEmpParam = newePaisParam(auxPais->id, auxPais->nombre,auxPais->vac1Dosis, auxPais->vac2Dosis);

                    switch(editUI())
                    {
                    case 1:
                        printf("Ingrese Nombre: ");
                        getString(auxNuevoEmpParam->nombre);
                        pais_setNombre(auxNuevoEmpParam, auxNuevoEmpParam->nombre);
                        ll_set(pArrayListPais, indice, (ePais*)auxNuevoEmpParam);
                        printf("\n\nId                  Nombre Horas    Sueldo\n");
                        mostrarPais((ePais*) ll_get(pArrayListPais, indice));
                        todoOk = 1;
                        break;
                    case 2:
                        utn_getNumero(&auxNuevoEmpParam->vac1Dosis, "\nIngrese las horas trabajadas: ","Error ingrese un numero valido", 0, 100000, 10);
                        pais_setVac1Dosis(auxNuevoEmpParam, auxNuevoEmpParam->vac1Dosis);
                        ll_set(pArrayListPais, indice, (ePais*)auxNuevoEmpParam);
                        printf("\n\nId                  Nombre Horas    Sueldo\n");
                        mostrarPais((ePais*) ll_get(pArrayListPais, indice));
                        todoOk = 1;
                        break;
                    case 3:
                        utn_getNumero(&auxNuevoEmpParam->vac2Dosis, "\nIngrese el vac2Dosis: ", "Error ingrese un numero valido", 0, 2000000, 10);
                        pais_setVac2Dosis(auxNuevoEmpParam, auxNuevoEmpParam->vac2Dosis);
                        ll_set(pArrayListPais, indice, (ePais*)auxNuevoEmpParam);
                        printf("\n\nId                  Nombre Horas    Sueldo\n");
                        mostrarPais((ePais*) ll_get(pArrayListPais, indice));
                        todoOk = 1;
                        break;
                    }
                }
            }

        }
    }
    return todoOk;
}

int controller_removePais(LinkedList* pArrayListPais)
{
    int todoOk=0;
    int indice;
    int id;
    char confirma;
    ePais* auxPais = pais_new();
    system("cls");
    if(ll_len(pArrayListPais)== 0)
    {
        todoOk = -1;
    }
    else
    {
        printf("Baja paises\n\n");
        controller_ListPais(pArrayListPais);
        utn_getNumero(&id, "Ingrese Id: ", "Error --> Ingrese un id valido", 1, 99999999,100);
        indice = findPais(pArrayListPais, id);
        if(indice == -1)
        {
            printf("\tNo existe un empleado con el legajo %d\n\n", id);
        }
        else
        {
            auxPais =  (ePais*)ll_get(pArrayListPais, indice);
            if(auxPais != NULL)
            {
                printf("\n\nId                  Nombre Horas    Sueldo\n");
                mostrarPais(auxPais);
                askForChar(&confirma, "Confirma baja? s/n :", "Error --> Ingrese una opcion valida", 100);
                if(confirma == 'S' || confirma == 's')
                {
                    if(ll_remove(pArrayListPais, indice) == 0)
                    {
                        todoOk = 1;
                        pais_delete(auxPais);
                        auxPais = NULL;
                    }
                }
                else
                {
                    printf("\nBaja cancelada por el usuario\n");
                }
            }
        }
    }
    return todoOk;
}
int controller_ListPais(LinkedList* pArrayListPais)
{
    int todoOk = 0;
    ePais* auxPais = NULL;
    if(pArrayListPais != NULL)
    {
        printPaisTitle();
        for(int i=0; i < ll_len(pArrayListPais); i++)
        {
            auxPais = (ePais*)ll_get(pArrayListPais, i);
            mostrarPais(auxPais);
            todoOk = 1;
        }
        if (ll_len(pArrayListPais) > 20)
        {
            printPaisTitle();
        }
    }
    return todoOk;
}

int controller_sortPais(LinkedList* pArrayListPais)
{
    int todoOk = 0;
    char salir = 's';

    do
    {
        switch(sortUI())
        {
        case 1:
            printf("Iniciando ordenamiento\n");
            ll_sort(pArrayListPais, pais_cmpVacTotal, 0);
            controller_ListPais(pArrayListPais);
            break;
        case 2:
            askForChar(&salir, "Realmente desea salir? s/n: ", "Error!!! --> Ingrese una opcion valida", 10);
            break;
        default:
            printf("Error!!! --> ingrese una opcion valida.");
            break;
        }
    }
    while(salir == 'n');
    return todoOk;
}

int controller_filterPais(LinkedList* pArrayListPais)
{
    int todoOk = 0;
    char salir = 's';
    LinkedList* filteredList = NULL;
    do
    {
        switch(filterUI())
        {
        case 1:
            printf("Iniciando filtrado\n");
            filteredList = ll_filter(pArrayListPais, esExitoso);
            controller_ListPais(filteredList);
            break;
        case 2:
            printf("Iniciando filtrado\n");
            filteredList = ll_filter(pArrayListPais, alHorno);
            controller_ListPais(filteredList);
            break;
        case 3:
            printf("Iniciando filtrado\n");
            filteredList = ll_filter(pArrayListPais, masCastigado);
            controller_ListPais(filteredList);
            break;
        case 4:
            askForChar(&salir, "Realmente desea salir? s/n: ", "Error!!! --> Ingrese una opcion valida", 10);
            break;
        default:
            printf("Error!!! --> ingrese una opcion valida.");
            break;
        }
    }
    while(salir == 'n');
    return todoOk;
}

int controller_saveAsText(LinkedList* pArrayListPais)
{
    int todoOk = 0;
    char confirma = 's';
    char path[128];
    int cant;
    int flagError = 0;
    ePais* auxPais = pais_new();
    FILE* f = NULL;
    printf("\nPath por defecto 'data.csv'\n");
    askForString(path,"Ingrese un path para el archivo de texto: ", 128);
    f = fopen(path, "r");
    if(f != NULL)
    {
        askForChar(&confirma, "ATENCION!!! --> El archivo existe y se va a sobrescribir. Confirma? s/n: ", "Error!!! --> Ingrese un caracter valido", 10);
    }
    fclose(f);
    if(confirma == 's')
    {
        f = fopen(path, "w");
        if(f == NULL)
        {
            printf("Error!!! --> No se pudo abrir el archivo\n");
        }
        else
        {
            fprintf(f, "id,nombre,sexo,vac2Dosis\n");

            for(int i=0; i<ll_len(pArrayListPais); i++)
            {
                auxPais = (ePais*)ll_get(pArrayListPais, i);
                if(auxPais != NULL)
                {
                    cant = fprintf(f, "%d,%s,%d,%d\n", auxPais->id,auxPais->nombre,auxPais->vac1Dosis,auxPais->vac2Dosis);//ree
                    if(cant < 4)
                    {
                        flagError = 1;
                        break;
                    }
                }
            }

        }
        fclose(f);
    }
    if(flagError)
    {
        printf("Error!!! --> Ocurrio un problema al guardar los paises en el archivo\n");
    }
    else
    {
        todoOk = 1;
    }
    return todoOk;
}

int controller_saveAsBinary(LinkedList* pArrayListPais)
{
    int todoOk= 0;
    int cant;
    char path[128];
    ePais * auxPais = NULL;
    int flag = 0;
    FILE* f = NULL;
    char confirma = 's';
    printf("\nPath por defecto 'data.bin'\n");
    askForString(path,"Ingrese un path para el archivo binario: ", 128);
    f = fopen(path, "rb");
    if(f != NULL)
    {
        askForChar(&confirma, "ATENCION!!! --> el archivo existe y se va a sobrescribir. Confirma? s/n: ", "Error!!! -> Ingrese un caracter valido", 10);
        todoOk = -1;
    }
    fclose(f);
    if(confirma == 's')
    {
        f = fopen(path,"wb");
        if(f == NULL)
        {
            printf("Error!!! --> No se pudo abrir el archivo\n");
        }
        else
        {
            for(int i=0; i<ll_len(pArrayListPais); i++)
            {
                auxPais = (ePais*)ll_get(pArrayListPais, i);
                if( auxPais != NULL)
                {
                    cant = fwrite(auxPais, sizeof(ePais), 1, f);
                    if(cant < 1)
                    {
                        flag = 1;
                    }
                }
            }

        }
        fclose(f);
    }

    if(flag)
    {
        printf("Error!!! --> Ocurrio un problema al guardar los paises en el archivo\n");
    }
    else
    {
        todoOk= 1;
    }

    return todoOk;
}

int controller_cleanSinVacunar(LinkedList* pArrayListPais)
{
    int todoOk = 0;
    ePais* auxPais = NULL;
    int auxSinVacunar = 0;
    if(pArrayListPais != NULL)
    {
        for(int i=0; i < ll_len(pArrayListPais); i++)
        {
            auxPais = (ePais*)ll_get(pArrayListPais, i);
            pais_setSinVacunar(auxPais, auxSinVacunar);
            todoOk = 1;
        }
    }
    return todoOk;
}

LinkedList* ll_map(LinkedList* this, void*(pFunc)(void*))
{
    int tam;
    void* auxPais;
    LinkedList* newList = NULL;

    if(this != NULL && pFunc != NULL)
    {
        tam = ll_len(this);
        newList = ll_newLinkedList();

        for (int i = 0; i < tam; i++)
        {
            auxPais = ll_get(this, i);
            auxPais = pFunc(auxPais);
            if( auxPais != NULL)
            {
                ll_add(newList, auxPais);
            }
        }
    }

    return newList;
}

void* controller_hardcodeVacunas(void* pPais)
{
    int auxVac1Dosis = 0;
    int auxVac2Dosis = 0;
    int auxSinVacunar = 0;
    ePais* auxPais = NULL;
    if(pPais != NULL)
    {
        auxVac1Dosis = getRandomNumber(1,60);
        auxVac2Dosis = getRandomNumber(1,40);
        auxSinVacunar = 100 - (auxVac1Dosis + auxVac2Dosis);
        auxPais = (ePais*)pPais;
        pais_setVac1Dosis(auxPais, auxVac1Dosis);
        pais_setVac2Dosis(auxPais, auxVac2Dosis);
        pais_setSinVacunar(auxPais, auxSinVacunar);
    }
    return auxPais;
}

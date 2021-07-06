#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pais.h"
//Paises
//paises
//Paises
//paises
//Pais
//pais

ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1DosisStr, char* vac2DosisStr)
{
    ePais* nuevoPais = pais_new();
    if(nuevoPais != NULL)
    {
        if(!(pais_setId(nuevoPais, atoi(idStr))
                && pais_setNombre(nuevoPais, nombreStr)
                && pais_setVac1Dosis(nuevoPais, atoi(vac1DosisStr))
                && pais_setVac2Dosis(nuevoPais, atoi(vac2DosisStr))))
        {
            pais_delete(nuevoPais);
            nuevoPais = NULL;
        }
    }
    return nuevoPais;
}

ePais* pais_new()
{
    ePais* nuevoPais = (ePais*)malloc(sizeof(ePais));
    if(nuevoPais != NULL)
    {
        nuevoPais->id = 0;
        strcpy(nuevoPais->nombre, " ");
        nuevoPais->vac1Dosis = 0;
        nuevoPais->vac2Dosis = 0;
    }
    return nuevoPais;
}


ePais* newePaisParam(int id, char* nombre, int horas, int vac2Dosis)
{
    ePais* nuevoPais = pais_new();
    if(nuevoPais != NULL)
    {
        if(!(pais_setId(nuevoPais, id)
                && pais_setNombre(nuevoPais, nombre)
                && pais_setVac1Dosis(nuevoPais, horas)
                && pais_setVac2Dosis(nuevoPais, vac2Dosis)))
        {
            pais_delete(nuevoPais);
            nuevoPais = NULL;
        }
    }
    return nuevoPais;
}


int mostrarPais(ePais* this)
{
    int todoOk = 0;
    int id;
    char nombre[128];
    int vac1Dosis;
    int vac2Dosis;
    int sinVacunar;
    if(this != NULL && pais_getId(this, &id)
            && pais_getNombre(this, nombre) && pais_getVac1Dosis(this, &vac1Dosis)
            && pais_getVac2Dosis(this, &vac2Dosis) && pais_getSinVacunar(this, &sinVacunar))
    {

        printf("| %5d   |     %15s      | %10d   |     %2d      |     %2d     |\n", id, nombre, vac1Dosis, vac2Dosis, sinVacunar);
        todoOk = 1;
    }
    return todoOk;
}


int pais_setId(ePais* this, int id)
{
    int todoOk=0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}


int pais_getId(ePais* this,int* id)
{
    int todoOk=0;
    if(this != NULL && id != NULL)
    {
        (*id) = this->id;
        todoOk = 1;
    }
    return todoOk;
}
//getters
int pais_getNombre(ePais* this,char* nombre)
{
    int todoOk=0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;

}

int pais_getVac1Dosis(ePais* this,int* vac1Dosis)
{
    int todoOk=0;
    if(this != NULL && vac1Dosis != NULL)
    {
        (*vac1Dosis) = this->vac1Dosis;
        todoOk = 1;
    }
    return todoOk;
}


int pais_getVac2Dosis(ePais* this,int* vac2Dosis)
{
    int todoOk=0;
    if(this != NULL && vac2Dosis != NULL)
    {
        (*vac2Dosis) = this->vac2Dosis;
        todoOk = 1;
    }
    return todoOk;
}
int pais_getSinVacunar(ePais* this,int* sinVacunar)
{
    int todoOk=0;
    if(this != NULL && sinVacunar != NULL)
    {
        (*sinVacunar) = this->sinVacunar;
        todoOk = 1;
    }
    return todoOk;
}




//Setters
int pais_setNombre(ePais* this,char* nombre)
{
    int todoOk=0;
    if(this != NULL && nombre != NULL && strlen(nombre) > 2 && strlen(nombre) < 129)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int pais_setVac1Dosis(ePais* this,int vac1Dosis)
{
    int todoOk=0;
    if(this != NULL && vac1Dosis >= 0 && vac1Dosis <= 100)
    {
        this->vac1Dosis = vac1Dosis;
        todoOk = 1;
    }
    return todoOk;
}

int pais_setVac2Dosis(ePais* this,int vac2Dosis)
{
    int todoOk=0;
    if(this != NULL && vac2Dosis >= 0 && vac2Dosis <= 100)
    {
        this->vac2Dosis = vac2Dosis;
        todoOk = 1;
    }
    return todoOk;
}


int pais_delete(ePais* this)
{
    int todoOk=0;
    if(this != NULL)
    {
        free(this);
        todoOk = 1;
    }
    return todoOk;
}

int pais_cmpId(void* a, void* b)
{
    int ret= 0;
    ePais* aux = NULL;
    ePais* aux2 = NULL;
    if(a != NULL && b != NULL)
    {
        aux = (ePais*) a;
        aux2 = (ePais*)b;
        if(aux->id < aux2->id)
        {
            ret = 1;
        }
        else if(aux->id > aux2->id)
        {
            ret = -1;
        }
    }
    return ret;
}


int pais_cmpName(void* a, void* b)
{
    int ret= 0;
    ePais* aux = NULL;
    ePais* aux2 = NULL;
    if(a != NULL && b != NULL)
    {
        aux = (ePais*) a;
        aux2 = (ePais*)b;
        ret = strcmp(aux2->nombre, aux->nombre);
    }
    return ret;
}
int pais_cmpHours(void* a, void* b)
{
    int ret= 0;
    ePais* aux = NULL;
    ePais* aux2 = NULL;
    if(a != NULL && b != NULL)
    {
        aux = (ePais*) a;
        aux2 = (ePais*)b;
        if(aux->vac1Dosis < aux2->vac1Dosis)
        {
            ret = 1;
        }
        else if(aux->vac1Dosis > aux2->vac1Dosis)
        {
            ret = -1;
        }
    }
    return ret;
}

int pais_cmpSalary(void* a, void* b)
{
    int ret= 0;
    ePais* aux = NULL;
    ePais* aux2 = NULL;
    if(a != NULL && b != NULL)
    {
        aux = (ePais*) a;
        aux2 = (ePais*)b;
        if(aux->vac2Dosis < aux2->vac2Dosis)
        {
            ret = 1;
        }
        else if(aux->vac2Dosis > aux2->vac2Dosis)
        {
            ret = -1;
        }
    }
    return ret;
}

int mayorDeSinVacunar(void* persona)
{
    int ok = 0;
    ePais* auxPais = NULL;
    if (persona != NULL)
    {
        auxPais = (ePais*) persona;
        if (auxPais->sinVacunar > 17)
        {
            ok = 1;
        }
    }
    return ok;
}

int esExitoso(void* persona)
{
    int ok = 0;
    ePais* auxPais = NULL;
    if (persona != NULL)
    {
        auxPais = (ePais*) persona;
        if (auxPais->vac1Dosis > 30 && auxPais->vac2Dosis > 30)
        {
            ok = 1;
        }
    }
    return ok;
}
int alHorno(void* persona)
{
    int ok = 0;
    ePais* auxPais = NULL;
    if (persona != NULL)
    {
        auxPais = (ePais*) persona;
        if (auxPais->sinVacunar > (auxPais->vac1Dosis + auxPais->vac2Dosis))
        {
            ok = 1;
        }
    }
    return ok;
}
int esFernando(void* persona)
{
    int ok = 0;
    ePais* auxPais = NULL;
    if (persona != NULL)
    {
        auxPais = (ePais*) persona;
        if (strcmp(auxPais->nombre, "Fernando") == 0)
        {
            ok = 1;
        }
    }
    return ok;
}
int pais_setSinVacunar(ePais* this,int sinVacunar)
{
    int todoOk=0;
    if(this != NULL && sinVacunar >= 0 && sinVacunar <= 100)
    {
        this->sinVacunar = sinVacunar;
        todoOk = 1;
    }
    return todoOk;
}

int pais_cmpVacTotal(void* a, void* b)
{
    int ret= 0;
    ePais* aux = NULL;
    ePais* aux2 = NULL;
    if(a != NULL && b != NULL)
    {
        aux = (ePais*) a;
        aux2 = (ePais*)b;
        if(aux->vac1Dosis + aux->vac2Dosis >  aux2->vac1Dosis + aux2->vac2Dosis)
        {
            ret = 1;
        }
        else if(aux->vac1Dosis + aux->vac2Dosis < aux2->vac1Dosis + aux2->vac2Dosis)
        {
            ret = -1;
        }
    }
    return ret;
}





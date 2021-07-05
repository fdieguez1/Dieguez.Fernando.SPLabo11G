#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Pais.h"
#include "inputs.h"
#include "Randomizer.h"


/****************************************************

TP3 -->
    Menu:
     1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos
del mismo.

    2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de los países.

    3) Asignar estadísticas: Se deberá hacer uso de la función map. la cual recibirá el linkedlist y
una función que asignará a cada país un valor de vacunados con una dosis (entre 1% y 60%),
vacunados con dos dosis (entre 1% y 40%), ambos asignados de manera aleatoria y porcentaje
sin vacunar que será lo que falte para el 100%.

    4) Filtrar por países exitosos: Se deberá generar un archivo igual al original, pero donde solo
aparezcan países cuya población este vacunada con dos dosis en un porcentaje mayor al 30%.

    5) Filtrar por países en el horno: Se deberá generar un archivo igual al original, pero donde
solo aparezcan países donde la cantidad de no vacunados sea mayor a la de vacunados.

    6) Ordenar por nivel de vacunación: Se deberá mostrar por pantalla un listado de los países
ordenados por cantidad de vacunados con 1 dosis.

    7) Mostrar más castigado: Informar el nombre del país o países con el mayor porcentaje de no
vacunados. Y cuál es ese número.

    8) Salir.


*****************************************************/

int main()
{
    //Paises
    //paises
    //Paises
    //paises
    //Pais
    //pais

    startRandomizer();

    int idPais = 1;
    int paisCount = 0;
    char salir = 'n';
    char path[20] = "";
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaMapeada = NULL;
    int banderaMapeadas = 0;

    if(lista == NULL)
    {
        printf("No se pudo crear el linkedlist");
        exit(1);
    }

    while (salir == 'n')
    {
        paisCount = ll_len(lista);
        switch(menu())
        {
        case 1:
            if (askForString(path, "Ingrese un nombre para cargar el archivo ej: vacunas.csv:\n", 20))
            {
                printf("PATH: %s",path);
                if(controller_loadFromText(path,lista))
                {
                    getBiggestId(lista, &idPais);
                    printf("\nCarga de paises exitosa\n");
                }
                else
                {
                    printf("Error!!! --> Problemas en la carga del archivo .csv\n");
                }
            }
            break;
        case 2:
            if(paisCount == 0)
            {
                printf("Error!!! --> No hay paises cargados\n");
            }
            else if (!banderaMapeadas)
            {
                printf("Error!!! --> Hay paises pero no se cargaron las estadisticas\n");
            }
            else
            {
                controller_ListPais(lista);
            }
            break;
        case 3:
            if(paisCount == 0)
            {
                printf("Error!!! --> No hay paises cargados\n");
            }
            else
            {
                listaMapeada = ll_map(lista, (void*)controller_hardcodeVacunas);
                if(listaMapeada != NULL)
                {
                    banderaMapeadas = 1;
                    ll_deleteLinkedList(listaMapeada);
                    printf("\n--> estadisticas cargadas exitosamente\n");
                }
                else
                {
                    printf("Error!!! --> Problemas en la carga de estadisticas\n");
                }
            }
            break;
        case 4:
            if(paisCount == 0)
            {
                printf("Error!!! --> No hay paises cargados\n");
            }
            else if (!banderaMapeadas)
            {
                printf("Error!!! --> No se cargaron las estadisticas\n");
            }
            else
            {
                controller_filterPais(lista);
            }
            break;
        case 5:
            if(paisCount == 0)
            {
                printf("Error!!! --> No hay paises cargados\n");
            }
            else if (!banderaMapeadas)
            {
                printf("Error!!! --> No se cargaron las estadisticas\n");
            }
            else
            {
                controller_sortPais(lista);
            }
            break;
        case 6:
            if(paisCount == 0)
            {
                printf("Error!!! --> No hay paises cargados\n");
            }
            else if (!banderaMapeadas)
            {
                printf("Error!!! --> No se cargaron las estadisticas\n");
            }
            else
            {
                if(!controller_saveAsText(lista))
                {
                    printf("Error!!! --> No se logro guardar los paises\n");
                }
                else
                {
                    printf("\n--> Operacion terminada\n");
                }
            }
            break;

        case 7:
            askForChar(&salir,"\nSaliendo del programa.\nOprima 'n' para cancelar,\nOprima cualquier otra tecla para continuar","Error ingrese un caracter", 10 );
            break;
        default:
            printf("Error!!! --> Opcion incorrecta, reintente\n");
            break;
        }
        system("pause");
    }
    return 0;
}




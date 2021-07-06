#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "inputs.h"
#define UI_WIDTH 81
#define LIST_THUMBNAIL 175

int menu()
{
    int opcion;
    system("cls");
    printDivisor();
    centerText("Sistema de gestion de paises", UI_WIDTH);
    printf("\n");
    printDivisor();
    printTableDivisor();
    printf("\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("1-Cargar los datos de los paises desde archivo .csv\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("2-Listar paises\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("3-Asignar estadisticas:\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("4-Filtrar paises\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("5-Ordenar paises\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("6-Guardar como csv\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("7-Pais mas castigado\n");
    printf("%c ", LIST_THUMBNAIL);
    printf("8-Salir\n");
    printDivisor();
    printf("\n");

    utn_getNumero(&opcion, "Elija una opcion: ", "Error!!! --> Ingrese un numero valido\n", 1, 8, 10);
    return opcion;
}

void printDivisor()
{
    //Imprimo una division en pantalla (ASCII)
    for(int i = 0; i < UI_WIDTH; i++)
    {
        printf("%c", 254);
    }
    printf("\n");
}
void printTableDivisor()
{
    //Imprimo una division en pantalla (ASCII)
    for(int i = 0; i < UI_WIDTH; i++)
    {
        printf("%c", 176);
    }
    printf("\n");
}
void centerText(char* text, int totalWidth)
{
    int size = strlen(text);
    int spaces = totalWidth - size;
    int leftMargin = spaces / 2;
    for(int i = 0; i < leftMargin; i ++)
    {
        printf(" ");
    }
    printf("%s", text);
}

void printPaisTitle()
{
    printTableDivisor();
    printf("|   Id    |          Nombre          |   Vac1Dosis  |    Vac2Dosis|  SinVacunas|\n");
    printTableDivisor();
}

int editUI()
{
    int opcion;
    system("cls");
    printDivisor();
    printf("Edicion de pais\n");
    printDivisor();
    printTableDivisor();
    printf("\n\n");
    printf("1-Editar el nombre\n");
    printf("2-Editar las horas trabajadas\n");
    printf("3-Editar el salario\n");
    printDivisor();
    utn_getNumero(&opcion, "Ingrese la opcion: ", "Error!!! --> Reingrese una opcion valida: ", 1, 3, 100);
    return opcion;
}

int sortUI()
{
    int opcion;
    system("cls");
    printDivisor();
    printf("Ordenamiento de paises\n");
    printDivisor();
    printTableDivisor();
    printf("\n\n");
    printf("1-Por vacunacion total descendente\n");
    printf("2-Cancelar\n");
    printDivisor();
    utn_getNumero(&opcion, "Ingrese la opcion: ", "Error!!! --> Reingrese una opcion valida: ", 1, 2, 10);
    return opcion;
}
int filterUI()
{
    int opcion;
    system("cls");
    printDivisor();
    printf("Filtrado de paises\n");
    printDivisor();
    printTableDivisor();
    printf("\n\n");
    printf("1-Por exitosos\n");
    printf("2-Por al horno\n");
    printf("3-Cancelar\n");
    printDivisor();
    utn_getNumero(&opcion, "Ingrese la opcion: ", "Error!!! --> Reingrese una opcion valida: ", 1, 3, 10);
    return opcion;
}

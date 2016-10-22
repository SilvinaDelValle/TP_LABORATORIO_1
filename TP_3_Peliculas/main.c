#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "funciones.h"

int main()
{
    EMovie movie;
    char seguir='s';
    int opcion=0;
    char movieTitulo[20];

    while(seguir=='s')
    {
        system("cls");
        printf("***** MENU DE OPCIONES *****\n");
        printf("[1] Agregar pelicula\n");
        printf("[2] Borrar pelicula\n");
        printf("[3] Modificar pelicula\n");
        printf("[4] Generar pagina web\n");
        printf("[5] Visualizar peliculas\n");
        printf("[6] Salir\n");

        printf("\nSeleccionar opcion: ");

        scanf("%d",&opcion);

        system("cls");
        switch(opcion)
        {
            case 1:
                printf("***** AGREGAR PELICULA *****\n");

                if(agregarPelicula(&movie) == 1)
                    printf("\nPelicula agregada exitosamente.\n\n");
                break;
            case 2:
                printf("***** ELIMINAR PELICULA *****\n");

                printf("\nIngrese titulo de la pelicula a eliminar: ");
                fflush(stdin);
                gets(movieTitulo);

                if(eliminarPelicula(movieTitulo) == 1)
                    printf("\nPelicula eliminada exitosamente.\n\n");
                break;
            case 3:
                printf("***** MODIFICAR PELICULA *****\n");

                printf("\nIngrese titulo de la pelicula a modificar: ");
                fflush(stdin);
                gets(movieTitulo);

                if(modificarPelicula(movieTitulo) == 1)
                    printf("\nPelicula modificada exitosamente.\n\n");
                break;
            case 4:
                printf("***** GENERAR WEB *****\n");
                if(generarPagina())
                    printf("\nPagina generada exitosamente.\n\n");
                break;
            case 5:
                printf("***** VISUALIZACION PELICULAS *****\n");
                mostrarPeliculas();
                break;
            case 6:
                seguir = 'n';
                break;
        }

        system("pause");
    }

    return 0;
}

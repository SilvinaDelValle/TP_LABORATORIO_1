#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"

int agregarPelicula(EMovie* movie)
{
    printf("\nIngrese titulo: ");
	fflush(stdin);
	gets(movie->titulo);

    printf("\nIngrese genero: ");
	fflush(stdin);
	gets(movie->genero);

    movie->duracion=getInt("\nIngrese duracion:");

    printf("\nIngrese la descripcion: ");
	fflush(stdin);
	gets(movie->descripcion);

    movie->puntaje=getInt("\nIngrese puntaje: ");

    getString("\nIngrese url imagen: ", movie->linkImagen);
    fflush(stdin);

    return guardarPelicula(movie);
}

int guardarPelicula(EMovie* movie)
{
    FILE* fp;
    fp=fopen("movies.dat","ab+");
    if(fp==NULL)
    {
        printf("Error opening file");
        return 0;
    }

    fwrite(movie,sizeof(EMovie),1,fp);

    fclose(fp);
    return 1;
}

int eliminarPelicula(char* movieTitulo)
{
    FILE *file, *fileAux;
    EMovie* movieFind = buscarPelicula(movieTitulo);

    if(movieFind!=NULL)
    {
        fileAux=fopen("moviesAux.dat","wb+");
        file=fopen("movies.dat","rb");
        EMovie movie;

        while(fread(&movie, sizeof(EMovie),1, file) != 0)
        {
            if (strcmp(movieTitulo, movie.titulo))
            {
                fwrite(&movie, sizeof(EMovie),1, fileAux);
            }
        }

        fclose(file);
        fclose(fileAux);

        fileAux=fopen("moviesAux.dat","rb");
        file=fopen("movies.dat","wb");

        while(fread(&movie, sizeof(EMovie),1, fileAux)){
            fwrite(&movie, sizeof(EMovie),1, file);
        }

        fclose(file);
        fclose(fileAux);
    }
    else
    {
        printf("El titulo de la pelicula no fue encontrado\n\n");
    }

    return 1;
}

int modificarPelicula(char* movieTitulo)
{
    int modificacion = 0;
    EMovie* movieFind = buscarPelicula(movieTitulo);

    if(movieFind!=NULL)
    {
        char seguir='s';
        char opcion;

        while(seguir=='s')
        {
            system("cls");
            printf("****** MODIFICAR PELICULA ******\n");
            printf("A) Titulo: %s\n", movieFind->titulo);
            printf("B) Genero: %s\n", movieFind->genero);
            printf("C) Duracion: %d minutos\n", movieFind->duracion);
            printf("D) Descripcion: %s\n", movieFind->descripcion);
            printf("E) Puntaje: %d\n", movieFind->puntaje);
            printf("F) Imagen URL: %s\n\n", movieFind->linkImagen);
            printf("S) Salir (Perdera las modificaciones)\n");
            printf("G) Guardar y Salir\n\n");

            //eliminar opcion
            printf("Seleccione la propiedad: ");
            scanf("%c",&opcion);

            switch(opcion)
            {
                case 'A':
                    getString("Ingrese titulo:", movieFind->titulo);
                    break;
                case 'B':
                    getString("Ingrese genero:", movieFind->genero);
                    break;
                case 'C':
                    movieFind->duracion=getInt("Ingrese duracion (minutos):");
                    break;
                case 'D':
                    getString("Ingrese descripcion:", movieFind->descripcion);
                    break;
                case 'E':
                    movieFind->puntaje=getInt("Ingrese puntaje:");
                    break;
                case 'F':
                    getString("Ingrese URL imagen:", movieFind->linkImagen);
                    break;
                case 'S':
                    seguir = 'n';
                    break;
                case 'G':
                    seguir = 'n';
                    eliminarPelicula(movieTitulo);
                    guardarPelicula(movieFind);
                    modificacion = 1;
                    break;
            }
        }
    }
    else
    {
        printf("El titulo de la pelicula no fue encontrado\n\n");
    }

    return modificacion;
}

int generarPagina()
{
    FILE *file, *fileWeb;
    file = fopen("movies.dat","rb");
    fileWeb = fopen("index.html","w+");

    if(file==NULL || fileWeb == NULL){
        printf("Error abriendo o creando los archivos.");
        return 0;
    }

    fprintf(fileWeb, "%s", WEB_ENCABEZADO);

    EMovie movie;
    while(fread(&movie, sizeof(EMovie),1, file) != 0)
    {
        char* article = WEB_REPETIR;

        char pts[5], time[5];
        sprintf(pts, "%d", movie.puntaje);
        sprintf(time, "%d", movie.duracion);

        article = str_replace(article, "[[URL_IMG]]", movie.linkImagen);
        article = str_replace(article, "[[TITULO]]", movie.titulo);
        article = str_replace(article, "[[GENERO]]", movie.genero);
        article = str_replace(article, "[[PUNTAJE]]", pts);
        article = str_replace(article, "[[DURACION]]", time);
        article = str_replace(article, "[[DESCRIPCION]]", movie.descripcion);

        fprintf(fileWeb, "%s", article);
    }

    fprintf(fileWeb, "%s", WEB_PIE);

    fclose(fileWeb);
    fclose(file);

    return 1;
}

EMovie* buscarPelicula(char* movieTitulo)
{
    FILE* file;
    file=fopen("movies.dat","rb");
    int encontrado = 0;

    if(file==NULL){
        printf("Error opening file");
        return NULL;
    }

    struct EMovie* movie = malloc(sizeof(EMovie));

    while(fread(movie, sizeof(EMovie),1, file) != 0)
    {
        if (strcmp(movieTitulo, movie->titulo) == 0)
        {
            //fwrite(&movie, sizeof(EMovie),1, fileAux);
            encontrado = 1;
            break;
        }
    }

    fclose(file);
    if(encontrado == 1)
        return movie;

    free(movie);
    return NULL;
}

void mostrarPeliculas()
{
    FILE* fp;
    fp=fopen("movies.dat","rb");
    if(fp==NULL)
    {
        printf("Error opening file");
    }

    EMovie* movieRet = malloc(sizeof(EMovie));

    while(fread(movieRet,sizeof(EMovie),1,fp)!=0)
    {

        printf("%s %s %d\r\n",movieRet->titulo,movieRet->genero,movieRet->duracion);

        //strcpy(movieRet->genero, "fruta");

        //fwrite(&movieRet, sizeof(EMovie), 1, fp);

        // printf("%s %s %d\r\n",movieRet->titulo,movieRet->genero,movieRet->duracion);
    }

    fclose(fp);
    free(movieRet);
};

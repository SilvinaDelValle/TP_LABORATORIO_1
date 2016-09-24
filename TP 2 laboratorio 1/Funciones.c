#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

 /** Obtiene el primer indice libre del array.
 *
 * \param lista el array se pasa como parametro.
 * \return Retorna el primer indice disponible
 *
 */

int buscarLibre(ePersona personas[], int tam)
{
    int indice = -1;
    int i;

    for(i=0; i<tam ; i++)
    {
        if(personas[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** Obtiene el indice que coincide con el dni pasado por parametro.
 *
 * \param lista el array se pasa como parametro.
 * \param  el dni es buscado en el array.
 * \return Retorna el indice en donde se encuentra el elemento con el parametro dni.
 *
 */


int buscarDni(ePersona personas[], int tam, int dni)
{
    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(personas[i].dni == dni)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** Despliega el menu de opciones.
 *
 * \param no recibe ningun valor.
 * \return Retorna el valor de la opcion ingresada por el usuario.
 *
 */


int menu()
{
        int opcion;
        system("cls");

        printf("\n1- Ingresar datos de una persona.v\n");

        printf("2- Borrar datos de una persona.\n\n");

        printf("3- Imprimir lista ordenada por  nombre.\n\n");

        printf("4- Imprimir grafico de edades.\n\n");

        printf("5- Salir\n");

        printf("\nElija una de las opciones: ");

        scanf("%d", &opcion);

        while(opcion>5 || opcion<1)
        {
            printf("\nError, opcion no valida. Reingrese opcion: ");
            scanf("%d", &opcion);
        }

        return opcion;

}

/** Carga los datos de las personas al sistema.
 *
 * \param personas el array se pasa como parametro.
 *
 */

void alta(ePersona persona[], int tam)
{
    int indice;
    int dni;
    int esta;

    indice = buscarLibre(persona, tam);

    if(indice == -1)
    {
        printf("\nNo hay lugar disponible\n");
    }
    else
    {
        printf("\nIngrese dni de la persona: ");
        scanf("%d", &dni);

        esta = buscarDni(persona, tam, dni);

        if(esta != -1)
        {
            printf("\nLa persona ya esta dada de alta en el sistema\n");
        }
        else
        {
            persona[indice].dni = dni;

            printf("\nIngrese el nombre de la persona: ");
            fflush(stdin);
            gets(persona[indice].nombre);

            printf("\nIngrese edad: ");
            scanf("%d", &persona[indice].edad);

            persona[indice].estado = 1;

            printf("\nDatos ingresados con exito.\n\n");

        }
    }
}

/** Inicializa el estado de todas las personas en 0.
 *
 * \param conjunto de estructuras a inicializar.
 * \param tamaño de dicho conjunto.
 *
 */


void inicializar(ePersona personas[], int tam)
{
    int i;
     for(i=0; i<tam; i++)
    {
       personas[i].estado = 0;
    }

}

/** \brief cambia el estado de una persona a 2.
 *
 * \param conjunto de estructuras usadas como parametro.
 * \param tamaño de dicho conjunto.
 *
 */

void baja(ePersona personas[], int tam)
{
     int indice;
     int dni;
     char baja;

     printf("\nIngrese dni persona: ");
     scanf("%d", &dni);

     indice = buscarDni(personas, tam, dni);

     if(indice == -1)
     {
         printf("\nLa persona de dni %d no se encuentra en el sistema\n\n", dni);
      }
     else
     {
        printf("\nDatos de la persona\n\n");
        printf("Nombre  edad  dni\n\n");
        mostrar(personas[indice]);

        printf("\n\nConfirma la baja de la persona: ");
        fflush(stdin);
        scanf("%c", &baja);

        if(baja == 's')
        {
            personas[indice].estado = 2;
            printf("\nBaja efectuada con exito\n");
        }
        else
        {
            printf("\n\nLa baja ha sido cancelada por el usuario\n\n");
        }

    }

      system("pause");
}

/** Muestra los datos de una persona.
 *
 * \param persona obtiene los datos de la persona.
 * \return no devuelve ningun valor.
 *
 */

void mostrar(ePersona unaPersona)
{
    printf("\n\nnombre  edad  dni\n\n");
    printf("%s  \t%d  %d\n", unaPersona.nombre, unaPersona.edad, unaPersona.dni);
}

/** \brief muestra los datos de un conjunto de personas.
 *
 * \param conjunto de personas a mostrar datos.
 *
 */


void mostrarTodos(ePersona otrasPersonas[])
{
    int i;
    for(i=0; i<19; i++)
    {
        if(otrasPersonas[i].estado == 1)
        {
            mostrar(otrasPersonas[i]);
        }
    }
    printf("\n\n");
}

/** Ordena las personas ingresadas al sistema por orden alfabetico.
 *
 * \param x el array se pasa como parametro.
 *
 */

void ordenar (ePersona x[])
{
    int i;
    int j;
    ePersona auxPersona;

    for (i=0; i<19; i++)
        {
            for (j=i+1; j<20; j++)
            {
                if (strcmp(x[i].nombre, x[j].nombre)>0)
                {
                    auxPersona = x[i];
                    x[i] = x[j];
                    x[j] = auxPersona;
                }

            }

        }

}

/** imprime un grafico de barras indicando la cantidad de personas por rango de edad.
 *
 * \param personas el array se pasa como parametro.
 *
 */

void grafico(ePersona personas[])
{

    int i;
    int cont18 = 0;
    int cont19a35 = 0;
    int cont35 = 0;
    int flag=0;
    int mayor;

    for(i=0; i<20; i++)
    {
        if(personas[i].estado==1 && personas[i].edad < 19)
        {
            cont18++;
        }
        if(personas[i].estado==1 && personas[i].edad > 18 && personas[i].edad < 36)
        {
            cont19a35++;
        }
        if(personas[i].estado==1 && personas[i].edad > 35)
        {
            cont35++;
        }

    }


    if(cont18 >= cont19a35 && cont18 >= cont35)
    {
        mayor = cont18;
    }
    else
    {

        if(cont19a35 >= cont18 && cont19a35 >= cont35)
            {

            mayor = cont19a35;

            }

        else
            {

            mayor = cont35;

            }
    }

    printf("\n\n--+-----\n\n");

    for(i=mayor; i>0; i--)
    {
        if(i<20)
        {
            printf("%02d|",i);
        }

        else
            printf("%02d|",i);

        if(i<= cont18)
        {
            printf("*");
        }

        if(i<= cont19a35)
        {
            flag=1;
            printf("\t*");
        }

        if(i<= cont35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }

        printf("\n");
    }
    printf("--+--------");

    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n", cont18, cont19a35, cont35);

    system("pause");


}



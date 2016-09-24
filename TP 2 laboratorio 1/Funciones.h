#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[21];
    int edad;
    int dni;
    int estado;
}ePersona;

void inicializar(ePersona[],int);

int buscarLibre(ePersona[],int);

int buscarDni(ePersona personas[], int tam, int dni);

int menu();

void alta(ePersona personas[], int tam);

void baja(ePersona personas[], int tam);

void inicializar(ePersona personas[], int tam);

void mostrar(ePersona unaPersona);

void mostrarTodos(ePersona otrasPersonas[]);

void ordenar(ePersona x[]);

void grafico(ePersona personas[]);

#endif // FUNCIONES_H_INCLUDED

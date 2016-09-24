#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>


int main()
{
    ePersona personas[20];
    inicializar(personas, 20);

    char seguir = 's';

   do
    {
        switch(menu())
        {
            case 1:

                alta(personas, 20);

                system("pause");

                break;
            case 2:

                baja(personas, 20);

                break;
            case 3:

                ordenar(personas);

                mostrarTodos(personas);

                system("pause");
                break;
            case 4:

                grafico(personas);

                break;
            case 5:

                seguir = 'n';

                break;
        }
    }while(seguir=='s');

    return 0;
}

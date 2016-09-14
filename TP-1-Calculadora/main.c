#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

int ValidarDivision(float);
int ValidarFactorial(float);

int main()
{
    char seguir='s', confirma;
    int opcion=0;
    float a=0, b=0;


    while(seguir=='s')
    {
        system("cls");

        if(a==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%5.2f)\n", a);
        }

        if(b==0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%5.2f)\n", b);
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese primer operando: ");
                scanf("%f", &a);
                break;
            case 2:
                printf("Ingrese segundo operando: ");
                scanf("%f", &b);
                break;
            case 3:
                printf("El resultado de la suma es: %.2f\n", Suma(a, b));
                system("pause");
                break;
            case 4:
                printf("El resultado de la resta es: %.2f\n", Resta(a, b));
                system("pause");
                break;
            case 5:
                if(ValidarDivision(b))
                {
                    printf("El resultado de la division es: %.2f\n", Dividir(a, b));
                }
                system("pause");
                break;
            case 6:
                printf("El resultado de la multiplicacion es: %.2f\n", Multiplicar(a, b));
                system("pause");
                break;
            case 7:
                if(ValidarFactorial(a))
                {
                    printf("El resultado del factoreo es: %.2f\n", Factorial(a));
                }
                system("pause");
                break;
            case 8:
                if(ValidarDivision(b) && ValidarFactorial(a))
                {
                    printf("El resultado de la suma es: %.2f\n", Suma(a, b));
                    printf("El resultado de la resta es: %.2f\n", Resta(a, b));
                    printf("El resultado de la division es: %.2f\n", Dividir(a, b));
                    printf("El resultado de la multiplicacion es: %.2f\n", Multiplicar(a, b));
                    printf("El resultado del factoreo es: %.2f\n", Factorial(a));
                }

                system("pause");
                break;
            case 9:
                printf("Confirma cierre del programa?: \n");
                confirma = tolower(getche());
                if(confirma == 's')
                {
                    seguir = 'n';
                }

                break;
        }

    }

    return 0;
}

int ValidarDivision(float dividendo)
{
    if(dividendo==0)
    {
        printf("Error: No se puede dividir por 0. Ingrese un valor para B (Menu->Opcion 2)\n");
        return 0;
    }

    return 1;
}

int ValidarFactorial(float numero)
{
    if(numero < 0)
    {
        printf("Error: No se puede factorear un numero negativo. Re-Ingrese un valor para A (Menu->Opcion 1)\n");
        return 0;
    }

    if(fmod (numero, 1) != 0)
    {
        printf("Error: Solo puede calcularse el factorial de un numero entero. Re-Ingrese un valor para A (Menu->Opcion 1)\n");
        return 0;
    }

     return 1;
}

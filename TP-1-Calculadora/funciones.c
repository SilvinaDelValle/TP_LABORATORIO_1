float resultado;

float Suma(float a, float b)
{
    resultado = a + b;
    return resultado;
}

float Resta(float a, float b)
{
    resultado = a - b;
    return resultado;
}

float Multiplicar(float a, float b)
{
    resultado = a * b;
    return resultado;
}

float Dividir(float a, float b)
{
    resultado = a / b;
    return resultado;
}

float Factorial(float a)
{
    if(a==0)
    {
        return 1;
    }

    int i;
    resultado = a;
    for(i=a-1; i > 1; i--)
    {
        resultado = resultado * i;
    }
    return resultado;
}

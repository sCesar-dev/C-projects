#include <stdio.h>

int main()
{
    
    int denominador;
    double resultado;
    
    for(denominador = 1; denominador <= 99; denominador += 2){
        resultado += 1.0 / denominador;
        printf("\n%f", resultado);
    }
    
    return 0;
}

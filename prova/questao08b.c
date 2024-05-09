#include <stdio.h>

int main()
{
    
    int denominador, resto;
    double resultado;
    
    denominador = 1;
    
    for(int i = 0; i < 20; i++){
        resto = i % 2;
        if (resto == 0){
            resultado += 1.0 / denominador;
        }else{
            resultado -= 1.0 / denominador;
        }
        denominador += 2;
        printf("\n%f", resultado);
    }
    
    return 0;
}

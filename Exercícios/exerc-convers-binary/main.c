#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor, resto, i;
    int binario[8];
    const div = 2;
    i = 0;

    printf("\nDigite o número em decimal a ser convertido em binário: ");
    scanf("%d", &valor);

    while(valor != 0){

        resto = valor % div;
        valor = valor / div;
        if (resto > 1 || resto < 0){
            printf("Deu merda, valor: %d", resto);
        }
        binario[i] = resto;
        i++;

    }

    for ( i = i-1;i >= 0; i--){
        printf("%d", binario[i]);
    }


    return 0;


}

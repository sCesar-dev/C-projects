#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, valorFinal;
    valorFinal = 1;
    printf("Digite um número: ");
    scanf("%d", &num);

    for(int i = 1;i <= num;){
        valorFinal = valorFinal * i;
        i++;
    }
    printf("\nValor da fatorial de %d: %d", num, valorFinal);
    return 0;
}

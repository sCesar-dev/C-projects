#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, valTabuada;

    printf("Digite um numero: ");
    scanf("%d", &num1);

    for(int i = 0;i <= 9; ){
        valTabuada = num1 * i;
        printf("\n %d x %d = %d", num1, i, valTabuada);
        i++;
    }

    return 0;
}

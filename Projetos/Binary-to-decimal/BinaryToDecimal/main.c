#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, resto;
    const div = 2;
    printf("Digite o n�mero a ser convertido: ");
    scanf("%d", &num);
    while(num != 0){
        resto = num % div;
        printf("%d", resto);
        num = num / div;
    }

    return 0;
}

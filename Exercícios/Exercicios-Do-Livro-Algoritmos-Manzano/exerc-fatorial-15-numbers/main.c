#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, cont, num, fat_atual, fat_final;

    printf("Fatorial de 15 números\n");
    printf("Digite a quantidade de numeros: ");
    scanf("%d", &cont);

    for (i = 0; i < cont;){
        printf("\nDigite o %d numero: ", i+1);
        scanf("%d", &num);
        for (int i2 = num; i2 != 0;){
            i2--;
            fat_atual = num - i2;
            fat_final += fat_atual;
        }
        printf("Soma da Fatorial de %d = %d \n", num, fat_final);
        fat_final = 0;
        i++;

    }


    return 0;
}

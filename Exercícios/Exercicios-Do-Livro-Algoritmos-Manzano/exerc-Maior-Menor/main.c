#include <stdio.h>
#include <stdlib.h>

int main()
{
    //variables
    int num, cont, num_maior, num_menor;


    //start code
    printf("Leitor maior-menor inteiros positivos\n");
    while (num >= 0){

        printf("Digite o %d número: ", cont+1);
        scanf("%d", &num);
        if (num >= 0){

            //Quando o numero inserido for maior
            if (num > num_maior)
                num_maior = num;

            //Condicional inserida para o menor não ser sempre 0
            if (cont == 0)
                num_menor = num;

            //Quando o numero inserido for menor
            if (num < num_menor)
                num_menor = num;
        }
        cont++;

    }

    printf("\nMaior = %d \nMenor = %d", num_maior, num_menor);
    return 0;
}

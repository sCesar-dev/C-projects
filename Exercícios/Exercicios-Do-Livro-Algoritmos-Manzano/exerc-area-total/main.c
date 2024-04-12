#include <stdio.h>
#include <stdlib.h>

int main()
{
    //variable declaration
    char nome_com[20];
    int larg_com, compr_com, area_com, total_area_com, cont, confirmation;


    printf("Area Total\n");
    confirmation = 1;

    while(confirmation != 0){

        printf("\nDigite o nome do comodo: ");
        scanf("%s", nome_com);

        printf("\nDigite a largura do comodo: ");
        scanf("%d", &larg_com);

        printf("\nDigite o comprimento do comodo: ");
        scanf("%d", &compr_com);

        area_com = larg_com * compr_com;
        total_area_com += area_com;

        printf("\nArea do %s: %d", nome_com, area_com);

        printf("\nDeseja continuar(1 -SIM)(0 - NAO): ");
        scanf("%d", &confirmation);
        cont++;
    }

    printf("\nTotal das areas dos %d comodos = %d", cont, total_area_com);
    return 0;
}

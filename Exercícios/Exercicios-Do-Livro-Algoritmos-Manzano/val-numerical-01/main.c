#include <stdio.h>
#include <stdlib.h>

int main()
{

    int cont, value;

    value = 3;

    for(cont = 0; cont <= 15; ){

        if (cont == 0){
            value = 1;
            printf("%d * %d = %d \n", 3, cont, value);
            cont++;
        }
        value = value * 3;
        printf("%d * %d = %d \n", 3, cont, value);
        cont++;

    }


    return 0;
}

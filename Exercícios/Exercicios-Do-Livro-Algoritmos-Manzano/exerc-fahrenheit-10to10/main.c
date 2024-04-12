#include <stdio.h>
#include <stdlib.h>

int main()
{
    int celsius, fahr;

    celsius = 10;

    printf("Conversion 10 to 10 Celsius - Fahrenheit \n\n");

    while (celsius <= 100){
        fahr = ((9 * celsius) + 160) / 5;
        printf("Celsius = %d  / Fahrenheit = %d \n", celsius, fahr);
        celsius += 10;
    }

    return 0;
}

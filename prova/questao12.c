#include <stdio.h>

int main(){

    double A = 90000000;
    double B = 200000000;
    int cont = 0;

    for(cont = 1; A <= B; cont++){

        A += A * 0.03;
        B += B * 0.015;
    }

    printf("Anos necessarios: %d", cont);
}

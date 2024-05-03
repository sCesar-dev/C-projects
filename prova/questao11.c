#include <stdio.h>

int main(){
    int tot_rep, i, algarismo[10], cont;

    printf("Digite a quantidade de algarismos(max: 10): ");
    scanf("%d", &tot_rep);
    
    for(i = 0; i < tot_rep; i++){
        printf("\nDigite o %d algarismo: ", i);
        scanf("%d", &algarismo[i]);
    }
    
    cont = tot_rep;
    for(i = 0; i < tot_rep; i++){
        if(algarismo[i] != algarismo[tot_rep-i-1]){
            printf("\nNão é um palíndromo. \n%d \n%d", tot_rep, i);
            break;
        }

    }
    printf("é um palindromo.")

}
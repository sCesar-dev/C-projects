#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int num, resto, num_soma;

    num_soma = 0; //inicializar pois estava gerando um erro com a soma do contador i

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);

    while(num < 1){
        printf("\nIncorreto, digite novamente: ");
        scanf("%d", &num);
    }

    for(int i = 1; i < num; i++){
        resto =  num % i;               //insere o resto na var resto
        if ( resto == 0){               //se for 0, soma o valor do 
            num_soma += i;              //divisor i no num_soma
        }
    }

    printf("\nSoma de %d: %d", num, num_soma);
}
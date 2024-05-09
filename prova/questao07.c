#include <stdio.h>

int main()
{
    
    int numero, resto, soma_num;
    
    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    
    for(int i = 1; i < numero; i++){
        
        resto = numero % i;
        if(resto == 0){
            soma_num += i;
            printf("\n%d", soma_num);
        }
    }
    
    if(soma_num == numero){
        printf("\nO %d e perfeito.", numero);
    }else{
        printf("\nO %d nao e perfeito.", numero);
    }
    
    
    return 0;
}

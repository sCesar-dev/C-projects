#include <stdio.h>

//1- Dada uma variável inteira cont = 5, use um ponteiro para incrementar seu valor em 1 e imprima o valor atualizado.
int cont = 5;
int * pCont = &cont;

//2- Dada uma variável inteira contagem = 5, use um ponteiro para incrementar seu valor em 1 e imprima o valor atualizado.
int numeros[5] = {2, 4, 6, 8, 10};
int * pArr = numeros; // numeros = numeros[0]

//3- Dado um array de caracteres char mensagem[] = "Olá";, use um ponteiro para imprimir cada caractere da string.
char mensagem[] = "Ola";
char * pMsg = mensagem;

//4-Escreva uma função void multiplicaPorDois(int *arr, int tamanho) que multiplica cada elemento de um array por 2. No main, declare um array int dados[] = {1, 3, 5, 7, 9};, chame a função e imprima o array modificado.
void multP2(int *multp2_arr, int multp2_tamanho){
    for(int i = 0; i < multp2_tamanho; i++){
        multp2_arr[i] *= 2;
        printf("\n%d", multp2_arr[i]);
    }
}
int dados[] = {1, 3, 5, 7, 9};
int multp2_tamanho = sizeof(dados) / sizeof(dados[0]);

//5- Escreva uma função void reverte(int *arr, int tamanho) que inverte um array. Use-a em int valores[] = {1, 2, 3, 4, 5}; e imprima o array invertido.
void reverte(int *reverte_arr, int reverte_tamanho){
    int arr_revertido[reverte_tamanho]; //tive que criar uma segunda array para guardar os dados invertidos
    for(int i = 0; i < reverte_tamanho;i++){
        arr_revertido[i] = reverte_arr[reverte_tamanho-i-1];
        printf("\n%d", arr_revertido[i]);
    }
}
int valores[]{1, 2, 3, 4, 5};
int reverte_tamanho = sizeof(valores) / sizeof(valores[0]);

int main(void){
    //1-
    printf("%d \n", (*pCont)++);

    //2-
    for(int i = 0; i < 5; i++){
        printf("\n%d", *pArr++);
    }

    //3-
    for(int i = 0; pMsg[i] != '\0'; i++){
        printf("\n%c", pMsg[i]);
    }

    //4-
    multP2(dados, multp2_tamanho);

    //5-
    reverte(valores, reverte_tamanho);
}
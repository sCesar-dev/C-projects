#include <iostream>
#include <string>

struct Node{
    int info;
    Node * prox;
};

class FilaEncadeada2{
private:
    Node *inicio, *atual;

public:
    FilaEncadeada2();
    void inserirElemento(int value);
    bool verificaElemento(int value);
};

FilaEncadeada2::FilaEncadeada2()
{
    atual = nullptr;
    inicio = nullptr;
}

void FilaEncadeada2::inserirElemento(int value)
{
    Node *novo = new Node();
    if(novo == nullptr){return;}
    novo->info = value;
    if(inicio == nullptr)
    {
        inicio = novo;
        atual = novo;
        return;
    }
    do{
        if(novo->info < inicio->info){
            novo->prox = inicio;
            inicio = novo;
            atual = novo;
            break;
        }
        if(novo->info > atual->info && novo->info < atual->prox->info){
            atual->prox = novo;
            novo->prox = atual->prox;
            atual = novo;
            break;
        }
        atual = atual->prox;
    }while(atual->prox != nullptr);
    if(atual->prox == nullptr)
    {
        atual->prox = novo;
        atual = novo;
    }
    while(atual->prox!=nullptr){
        std::cout<<" "<<atual->info<<std::endl;
        atual = atual->prox;
    }
    if(atual->prox == nullptr){
        std::cout<<" "<<atual->info<<std::endl;
    }
}
int main(){
    FilaEncadeada2 fila1;
    fila1.inserirElemento(3);
    fila1.inserirElemento(2);
    fila1.inserirElemento(7);
    fila1.inserirElemento(5);
    return 0;
}
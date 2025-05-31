#include "Arvore.hpp";
#include <cstdlib>     // Para exit()

Arvore::Arvore(){
    raiz = nullptr;
}

Node* Arvore::inserir(Node * r, int n){
    if(r == nullptr){
        r = new Node();
        if (r==nullptr) exit(1);
        r->info = n;
        r->esq = nullptr;
        r->dir = nullptr;
        return r;
    }
    if(n > r->info){
        r->dir = inserir(r->dir, n);
    }else{
        if(n < r->info){
            r->esq = inserir(r->esq, n);
        }else{
            std::cout << "Numero repetido" << std::endl;
            //return r;
        }
    }
    return r;
}

void Arvore::inserirPublico(int n)
{
    this->raiz = inserir(this->raiz, n);
}

void Arvore::inserirIterativo(Node * r, int n){
    Node *atual, *pai;
    if(r == nullptr) return;
    atual = r;
    while(atual != nullptr){
        pai = atual;
        if(n > atual->info) 
            atual = atual->dir;
        else if(n < atual->info) 
            atual = atual->esq;
        else{  
            std::cout << "repetido" << std::endl;
            return;
        }
    }
}

void Arvore::emOrdem(Node * r){
    if(r == nullptr) return;
    emOrdem(r->esq);
    std::cout<<r->info<<" ";
    emOrdem(r->dir);
}

void Arvore::emOrdemPublico(){
    emOrdem(this->raiz);
}


int main(){
    Arvore ar;
    ar.inserirPublico(20);
    ar.inserirPublico(60);
    ar.inserirPublico(15);
    ar.inserirPublico(25);
    ar.inserirPublico(5);
    ar.inserirPublico(30);
    ar.inserirPublico(10);
    ar.inserirPublico(15);
    ar.emOrdemPublico();
}
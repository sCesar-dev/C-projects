#include <iostream>
#include <cstdlib> 

struct Nodo{
    int info;
    struct Nodo *esq, *dir;
};

class Arvore{
    public:
    Nodo *raiz;
    Arvore();
    Nodo *inserir(Nodo *raiz, int n); // 
    void emOrdem(Nodo *raiz); // esquerda | raiz | direita
    int buscar(Nodo *raiz, int n);
    int contar(Nodo *raiz);
    int contarFolha(Nodo *raiz);
    void compararSubarvore(Nodo *raiz);
    Nodo* inserirInterativo(Nodo *raiz, int n);
    void imprimirExtremidades(Nodo *r);

};

Arvore :: Arvore (){
    raiz=nullptr;
}

Nodo* Arvore::inserir(Nodo *raiz, int n){
    if (raiz==nullptr){
        raiz=new Nodo();
        if(raiz==nullptr) exit(1); //nao conseguiu criar a area e nao ha mais nada a fazer
        raiz->info=n;
        raiz->esq=nullptr;
        raiz->dir=nullptr;
        return raiz;
    }
    if(n>raiz->info){ //recursividade!
        raiz->dir = inserir(raiz->dir, n);
    }
    else if (n<raiz->info){
        raiz->esq=inserir(raiz->esq, n);
    }
    else{
        std::cout<<"Número igual a algum que esta na lista. RETORNANDO"<<std::endl;
        return raiz;
    }
    return raiz;
}

void Arvore::emOrdem(Nodo *raiz){
    if(raiz==nullptr) return;
    emOrdem(raiz->esq); // vai ate o ultimo elemento existente na esquerda e coloca na fila
    std::cout<< raiz->info <<std::endl; // qunado nao ha mais elementos a esquerda, comeca a printar
    emOrdem(raiz->dir); //chama os valores pela ireita ate o fim, recursividade dnv
}

int Arvore::buscar(Nodo *raiz, int n){
    if(raiz==nullptr) return -1;
    if(raiz->info==n){
        return raiz->info;
    }
    if(raiz->info>n){
        return buscar(raiz->esq, n);
    }
    else{
        return buscar(raiz->dir, n);
    }
}

int Arvore::contar(Nodo *raiz){
    if(raiz==nullptr){
        return 0;
    }
    return(1+contar(raiz->esq)+contar(raiz->dir));
}

int Arvore::contarFolha(Nodo *raiz){
    if(raiz==nullptr){
        return 0;
    }
    if(raiz->esq==nullptr && raiz->dir==nullptr){
        return 1;
    }
    return(contarFolha(raiz->esq)+contarFolha(raiz->dir));
}

void Arvore::compararSubarvore(Nodo *raiz){
    int e, d;
    if(raiz==nullptr){
        return;
    }
    e=contarFolha(raiz->esq);
    d=contarFolha(raiz->dir);
    if(e>d){
        std::cout<<"Valor da esquerda é maior"<<std::endl;
    }
    else if(e<d){
        std::cout<<"Valor da direita é maior"<<std::endl;
    }
    else{
        std::cout<<"Valores iguais"<<std::endl;
    }
}

int main(){
    Arvore tree;
    tree.raiz = tree.inserir(tree.raiz, 10);
    tree.raiz = tree.inserir(tree.raiz, 5);
    tree.raiz = tree.inserir(tree.raiz, 15);

    std::cout << "Em ordem:" << std::endl;
    tree.emOrdem(tree.raiz);

    std::cout << "Buscar 15: " << tree.buscar(tree.raiz, 15) << std::endl;

    std::cout << "Número de nós: " << tree.contar(tree.raiz) << std::endl;
    std::cout << "Número de folhas: " << tree.contarFolha(tree.raiz) << std::endl;

    tree.compararSubarvore(tree.raiz);

    return 0;
}

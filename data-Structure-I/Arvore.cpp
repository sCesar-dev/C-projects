#include <iostream>
#include <cstdlib>     // Para exit()

struct Node{
    int info;
    struct Node * esq, * dir;
};

struct NoPilha{
    Node *noDaArvore;
    NoPilha *prox;
};

class Arvore{
private:
    int ac = 0;
public:
    Arvore();
    Node * raiz;
    Node * inserir(Node * r, int n);
    void inserirIterativo(Node * r, int n);
    void emOrdem(Node * r);
    void inserirPublico(int n);
    void emOrdemPublico();
    void contarNos(Node * r);
    void contarNosPublico();
    int alturaRecursiva(Node* r);
    void alturaRecursivaPublica();
    int contarFolhas(Node*r);
    void analiseSubArvoresFolhas(Node*r);
    void analiseSubArvoresFolhasPublico();
    void imprimirExtremidades(Node *r);
    bool acharAscendentes(Node *no, int val);
    void imprimirAscendentes(int val);
    NoPilha *topo;
    void push(Node *no);
    bool gerarPilAsc(Node *no, int val, NoPilha *pilha);
    NoPilha *gerarPilhaAsc(int val);
};

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

void Arvore::contarNos(Node * r){
    Node* atual;
    atual = r;
    while(atual != nullptr){
        if(atual->esq != nullptr){
            ac++;
            contarNos(atual->esq);
        }else if(atual->dir != nullptr){
            ac++;
            contarNos(atual->dir);
        }else
            return;
    }
}

void Arvore::contarNosPublico(){
    contarNos(this->raiz);
}

// Método auxiliar privado em Arvore.cpp (sem std::max)
int Arvore::alturaRecursiva(Node* r) {
    // Caso base: se a (sub)árvore é vazia, sua altura é -1.
    if (r == nullptr) {
        return -1;
    }

    // Calcula recursivamente a altura das subárvores esquerda e direita.
    int altura_esq = alturaRecursiva(r->esq);
    int altura_dir = alturaRecursiva(r->dir);

    // Usa um bloco if/else para encontrar a maior das duas alturas.
    int maior_altura_subarvore;
    if (altura_esq > altura_dir) {
        maior_altura_subarvore = altura_esq;
    } else {
        maior_altura_subarvore = altura_dir;
    }

    // A altura do nó atual é 1 (contando a si mesmo) + a maior altura de suas subárvores.
    return 1 + maior_altura_subarvore;
}

void Arvore::alturaRecursivaPublica(){
    printf("Altura recursiva: %d\n", alturaRecursiva(this->raiz));
}

int Arvore::contarFolhas(Node*r){
    if(r == nullptr) return 0;
    if(r->esq == nullptr && r->dir == nullptr) return 1;
    return contarFolhas(r->esq) + contarFolhas(r->dir);
}

void Arvore::analiseSubArvoresFolhas(Node*r){
    if(r == nullptr){
        printf("Arvore vazia! \n");
        return;
    }if (r->esq == nullptr && r->dir == nullptr){
        printf("Arvore somente com raiz!\n");
        return;
    }

    int folhasSubEsq = contarFolhas(r->esq);
    int folhasSubDir = contarFolhas(r->dir);

    if (folhasSubEsq > folhasSubDir) printf("Arvore esquerda tem mais folhas, val: %d\n", folhasSubEsq);
    else if (folhasSubDir > folhasSubEsq) printf("Arvore direita tem mais folhas, val: %d\n", folhasSubDir);
    else printf("São iguais! val:%d\n", folhasSubDir);
}

void Arvore::analiseSubArvoresFolhasPublico(){
    analiseSubArvoresFolhas(this->raiz);
}

void Arvore::imprimirExtremidades(Node *r){
    if(r == nullptr) return;
    Node *at = r;
    while(at->esq != nullptr || at->dir != nullptr){
        if(at->esq != nullptr) at = at->esq;
        else at = at->dir;
    }
    printf("Extremo esquerda: %d\n", at->info);
    at = r;
    while(at->esq != nullptr || at->dir != nullptr){
        if(at->dir != nullptr) at = at->dir;
        else at = at->esq;
    }
    printf("Extrema direita: %d\n", at->info);
}

bool Arvore::acharAscendentes(Node *no, int val){
    if(no == nullptr) return false;
    if(no->info == val) return true;

    bool encontrado = false;

    if(no->info > val) encontrado = acharAscendentes(no->esq, val);
    else encontrado = acharAscendentes(no->dir, val);
    if (encontrado) std::cout << no->info << " " << std::endl;
    return encontrado;
}

void Arvore::imprimirAscendentes(int val){
    acharAscendentes(raiz, val);
}

void Arvore::push(Node *no){
    NoPilha *novoNo = new NoPilha();
    if(novoNo == nullptr) return;
    novoNo->noDaArvore = no;
    novoNo->prox = topo;
    topo = novoNo;
}

bool Arvore::gerarPilAsc(Node *no, int val, NoPilha *pilha){
    if (no == nullptr) return false;
    if (no->info == val) return true;
    bool encontrado = false;
    if (no->info > val) encontrado = gerarPilAsc(no->esq, val, pilha);
    else encontrado = gerarPilAsc(no->dir, val, pilha);
    if (encontrado) push(no);
    return encontrado;
}


NoPilha* Arvore::gerarPilhaAsc(int val){
    NoPilha* pilhaAscendentes = new NoPilha();
    if (pilhaAscendentes == nullptr) return;
    gerarPilAsc()
}

int main(){
    Arvore ar;
    ar.inserirPublico(8);
    ar.inserirPublico(6);
    ar.inserirPublico(10);
    ar.inserirPublico(4);
    ar.inserirPublico(7);
    ar.inserirPublico(11);
    ar.inserirPublico(9);
    ar.inserirPublico(5);
    ar.alturaRecursivaPublica();
    ar.analiseSubArvoresFolhasPublico();
    ar.imprimirExtremidades(ar.raiz);
    ar.imprimirAscendentes(5);
    
    // ar.inserirPublico(30);
    // ar.inserirPublico(10);
    // ar.inserirPublico(15);
    // ar.emOrdemPublico();
    // ar.contarNosPublico();
}

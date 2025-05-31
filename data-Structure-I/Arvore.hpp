#include <iostream>

struct Node{
    int info;
    struct Node * esq, * dir;
};

class Arvore{
public:
    Arvore();
    Node * raiz;
    Node * inserir(Node * raiz, int n);
    void inserirIterativo(Node * raiz, int n);
    void emOrdem(Node * raiz);
    void inserirPublico(int n);
    void emOrdemPublico();1
};
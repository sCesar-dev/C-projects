#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node * proximo;
};

class Stack
{
private:
    Node * topo;

public:
    Stack();
    ~Stack();
    void empilhar(int value);
    void desempilhar();
    int consultarTopo();
};

Stack::Stack()
{
    topo = nullptr;
}

Stack::~Stack()
{
    while(topo != nullptr)
    {
        desempilhar();
    }
    cout << "Pilha apagada!";
}

void Stack::empilhar(int value)
{
    Node * novo = new Node;
    novo->info = value;
    novo->proximo = topo;
    topo = novo;
}

void Stack::desempilhar()
{
    if (topo != nullptr)
    {
        Node * temp = topo;
        topo = temp->proximo;
        delete temp;

    }else
    {
        cout << "Stack empty" << endl;
        return;
    }
}

int Stack::consultarTopo()
{
    if (topo == nullptr)
    {
        cout << "Stack empty" << endl;
        return -1;
    }else
    {
        return topo->info;
    }
}

int main()
{
    Stack s;

    s.empilhar(5);
    s.empilhar(10);
    s.empilhar(15);

    cout << "Topo atual : " << endl;
    s.consultarTopo();

    s.desempilhar();
    cout << "Topo atual: " << endl;
    s.consultarTopo();

    s.~Stack();
    return 0;
}
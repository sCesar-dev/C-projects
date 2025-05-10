#include "ListaCircular.hpp"

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>

char getch()
{
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

void ListaDupla::imprimeLista()
{
    atual = inicio;                                                                // Passa a ref de atual para o começo da lista
    std::cout << "Palavra atual: " << std::endl;
    do
    {
        std::cout << atual->info << std::endl;
        atual = atual->prox;
    } while (atual != inicio);

    std::cout << "A palavra atual é a inicial!" << std::endl;
}

void ListaDupla::editarPalavra(std::string palavra)
{
    std::cout << "Palavra editada: " << palavra << std::endl;
    atual->info = palavra;
    imprimeLista();
}

void ListaDupla::inserirPalavra(std::string palavra)
{
    Nodo2 *novo;
    novo = new Nodo2();
    if (novo == nullptr)
        return;

    novo->info = palavra;

    if (inicio == nullptr)
    {
        novo->prox = inicio;
        novo->ant = inicio;
        inicio = novo;
        atual = novo;
        return;
    }
    else
    {
        atual->prox = novo;
        atual->prox->ant = atual;
        novo->prox = inicio;
        inicio->ant = novo;
        atual = novo;
    }

    imprimeLista();
}

void ListaDupla::eliminarPalavra(std::string palavra)
{
    aux = inicio;

    do
    {
        if(aux->info == palavra)
        {
            delete aux;
            std::cout << "Palavra apagada, lista vazia!!" << std::endl;
            atual->prox->ant = atual->ant;
            atual->ant->prox = atual->prox;
        }
        aux = aux->prox;
        atual = aux;
        if(atual == nullptr)
        {
            std::cout << "Palavra apagada, lista vazia!!" << std::endl;
            atual = inicio;                                                     // Fix: Quando ele insere, apaga e insere novamente, nao da segmentation fault.
            break;
        }
    } while (aux != inicio);
    if(aux != nullptr)
    {
        std::cout << "A palavra não existe na lista!" << std::endl;
    }

    imprimeLista();
}

void ListaDupla::palavraAnterior()
{
    if (atual->ant != nullptr)
    {
        atual = atual->ant;

        std::cout << "Retornou para a palavra: " << atual->info << std::endl;
    } else{
        std::cout << "Lista vazia!!" << std::endl;
    }
}

void ListaDupla::palavraPosterior()
{
    if (atual->prox != nullptr)
    {
        atual = atual->prox;
        std::cout << "Retornou para a palavra: " << atual->info << std::endl;
    } else{
        std::cout << "Lista vazia!!" << std::endl;
    }
}

void ListaDupla::sair()
{
}

int main()
{
    ListaDupla editorTexto;
    char tecla;
    std::string palavra;

    while (true)
    {
        std::cout << "Selecione uma opção: " << std::endl;

        tecla = getch();

        switch (tecla)
        {

        case 'E':
            std::cout << "Digite a nova palavra: " << std::endl;
            std::cin >> palavra;
            editorTexto.editarPalavra(palavra);
            break;

        case 'D':
            std::cout << "Digite a palavra desejada" << std::endl;
            std::cin >> palavra;
            editorTexto.inserirPalavra(palavra);
            break;

        case 'S':
            std::cout << "Digite a palavra a ser excluida" << std::endl;
            std::cin >> palavra;
            editorTexto.eliminarPalavra(palavra);
            break;

        case '<':
            editorTexto.palavraAnterior();
            break;

        case '>':
            editorTexto.palavraPosterior();
            break;

        case 'X':
            editorTexto.sair();
            return 0;
        }
    }
}
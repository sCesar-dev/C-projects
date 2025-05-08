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

void ListaDupla::editarPalavra(std::string palavra)
{
    std::cout << "Digite a palavra a editar: " << palavra << std::endl;
    atual->info = palavra;
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
}

void ListaDupla::eliminarPalavra(std::string palavra)
{
    aux = inicio;
    do
    {
        if(aux->info == palavra)
        {
            delete aux;
            if(inicio == nullptr){
                std::cout << "Lista vazia!!" << std::endl;
                break;
            }
        }
        aux = aux->prox;
    } while (aux->prox != inicio);
    if(aux->prox = inicio)
    {
        aux->prox->ant = inicio;
    }
}

int main()
{
    ListaDupla editorTexto;
    char tecla;
    std::string palavra;
    std::cout << "Selecione uma opção: " << std::endl;

    while (true)
    {
        tecla = getch();

        switch (tecla)
        {

        case 'E':
            editarPalavra();
            break;

        case 'D':
            std::cout << "Digite a palavra desejada" << std::endl;
            std::cin >> palavra;
            editorTexto.inserirPalavra(palavra);
            break;

        // case 'S':
        //     eliminarPalavra();
        //     break;

        // case /*Inserir seta*/ '<':
        //     palavraAnterior();
        //     break;

        // case /*Inserir seta*/ '<':
        //     palavraPosterior();
        //     break;

        // case 'X':
        //     sair();
        //     break;
        }
    }
}
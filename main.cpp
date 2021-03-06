#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;
#include "Fila_Arranjo.h"


int main()
{
    setlocale(LC_ALL, "portuguese");
    tInfo item;
    tFila f;
    qInit(f);
    print(f);

    escolhas opcao;
    while((opcao = choice(f)) != FIM)
    {
        switch (opcao)
        {
            case ENFILEIRA:
                setDados(item);
                enQueue(f,item);
                break;
            case DESENFILEIRA:
                deQueue(f);
                break;
            case IMPRIME:
                print(f);
                system("pause");
                break;
            default:
                cerr << "Op��o incorreta!\n";
                break;
        }
    }
    return 0;
}

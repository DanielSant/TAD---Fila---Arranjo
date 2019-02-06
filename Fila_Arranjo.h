#ifndef FILA_ARRANJO_H_INCLUDED
#define FILA_ARRANJO_H_INCLUDED

// ---FILA IMPLEMENTDA POR ARRANJOS
const int tMax = 10;

typedef int apontador;

typedef struct
{
    char chave;
    // outros campos
} tInfo;

typedef struct
{
    tInfo item[tMax];
    apontador primeiro;
    apontador ultimo;
    int total;
} tFila;

enum escolhas {CRIA, ENFILEIRA, DESENFILEIRA, IMPRIME, FIM};
escolhas choice(tFila& Fila);
void setDados(tInfo& item);
void qInit(tFila& fila);
bool qIsEmpety(tFila& fila);
bool qIsFull(tFila& fila);
void adc(int& pos);
void enQueue(tFila& fila, tInfo item);
void deQueue(tFila& fila);
void print(tFila& fila);

// -------------------------------
escolhas choice(tFila& fila)
{
    system("cls");
    print(fila);
    int menuChoice;
    cout << "\nMenu: [FILA CIRCULAR - ARRANJO]" << endl
         << "1 - Enfileira\n"
         << "2 - Desenfileira\n"
         << "3 - Imprime\n"
         << "4 - Fim do programa\n"
         << "Opção: ";
    cin >> menuChoice;
    return (escolhas) menuChoice;
}
// -------------------------------
void setDados(tInfo& item)
{
    cout << "\nInforme o código: ";
    cin >> item.chave;
}
// -------------------------------
void qInit (tFila& fila)
{
    fila.primeiro = 0;
    fila.ultimo = 0;
    fila.total = 0;
}
// -------------------------------
bool qIsEmpety (tFila& fila)
{
    return fila.total == 0 ? true:false;
}
// -------------------------------
bool qIsFull (tFila& fila)
{
    return fila.total == tMax ? true:false;
}
// -------------------------------
void adc (int& pos)
{
    pos++;
    if (pos > tMax)
        pos = 0;
}
// -------------------------------
void enQueue (tFila& fila, tInfo item)
{
    if (qIsFull(fila))
    {
        cout << "Erro: Fila cheia!" << endl;
        system("pause");
    }
    else
    {
        fila.item[fila.ultimo] = item;
        adc(fila.ultimo);
        fila.total++;
    }
}
// -------------------------------
void deQueue (tFila& fila)
{
    if (qIsEmpety(fila))
    {
        cout << "Erro: Fila vazia!" << endl;
        system("pause");
    }
    else
    {
        adc(fila.primeiro);
        fila.total--;
    }
}
// -------------------------------
void print(tFila& fila)
{
    cout << "Itens na fila: " << endl;
    if (qIsEmpety(fila))
        cout << "Fila vazia!" << endl;
    else
    {
        int p = fila.primeiro;
        for (int aux = 1; aux <= fila.total; aux++)
        {
            cout << fila.item[p].chave << " ";
            adc(p);
        }
        cout << endl;
    }
    cout << "\nPRIMEIRO = " << fila.primeiro << endl;
    cout << "ULTIMO = " << fila.ultimo << endl;
    cout << "TOTAL = " << fila.total << endl;
}

#endif // FILA_ARRANJO_H_INCLUDED

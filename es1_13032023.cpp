#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int RIGHE = 6;
const int COLONNE = 6;

void inizializzaRandom(int mat[][COLONNE])
{
    // srand(time(NULL));
    for (int i = 0; i < RIGHE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {

            mat[i][j] = rand() % 10;
        }
    }
}

void stampaMatrice(int mat[][COLONNE])
{
    cout << "   ";
    for (int i = 0; i < COLONNE; i++)
    {
        cout << "  " << i << " ";
    }
    cout << endl;
    int trattini = COLONNE * 4 + 4;
    for (int i = 0; i < trattini; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < RIGHE; i++)
    {
        cout << i << "| ";

        for (int j = 0; j < COLONNE; j++)
        {
            cout << "  " << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int sommaKappa(int mat[][COLONNE], int num)
{
    int somma = 0;
    for (int i = 0; i < RIGHE; i++)
    {
        somma += mat[i][num];
    }
    return somma;
}

int sommaRighe(int mat[][COLONNE], int num)
{
    int somma = 0;
    for (int i = 0; i < COLONNE; i++)
    {
        somma += mat[num][i];
    }
    return somma;
}

int confrontaSomme(int mat[][COLONNE], int ind)
{
    int sum = sommaKappa(mat, ind);
    for (int i = 0; i < RIGHE; i++)
    {
        if (sum == sommaRighe(mat, i))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int matrice[RIGHE][COLONNE];
    inizializzaRandom(matrice);
    stampaMatrice(matrice);
    int k;
    cout << "Inserisci il valore della colonna da confrontare: ";
    cin >> k;
    if ((k >= 0) and (k <= RIGHE - 1))
    {
        int ris = confrontaSomme(matrice, k);
        if (ris == -1)
        {
            cout << "Le somme delle righe sono tutte diverse dalla somma della colonna " << k;
        }
        else
        {
            cout << "La riga " << ris << " ha la somma uguale alla somma della colonna " << k;
        }
    }
    else
    {
        cout << "Numero errato" << endl;
    }
}
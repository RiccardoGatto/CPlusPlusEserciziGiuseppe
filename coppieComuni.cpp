#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int RIGHE = 15;
const int COLONNE = 2;

void inizializzaMatriceRandom(int mat[][COLONNE])
{
    srand(time(NULL));
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
        if (i >= 10)
        {
            cout << i << "| ";
        }
        else
        {
            cout << i << " | ";
        }

        for (int j = 0; j < COLONNE; j++)
        {
            cout << "  " << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkUguali(int mat[][COLONNE])
{
    for (int i = 0; i < RIGHE; i++)
    {
        for (int j = i + 1; j < RIGHE; j++)
        {
            if (mat[i][0] == mat[j][0] and mat[i][1] == mat[j][1])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int punti[RIGHE][COLONNE];
    inizializzaMatriceRandom(punti);
    stampaMatrice(punti);
    if (checkUguali(punti))
    {
        cout << "Ci sono coordinate uguali" << endl;
    }
    else
    {
        cout << "Non ci sono coordinate uguali" << endl;
    }
}
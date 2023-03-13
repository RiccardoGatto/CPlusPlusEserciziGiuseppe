#include <iostream>
#include <random>
#include <time.h>
using namespace std;
const int RIGHE = 7;
const int COLONNE = 4;
const int LUNGHEZZA = 10;

bool presente(int num, int arr[])
{
    for (int i = 0; i < LUNGHEZZA; i++)
    {
        if (num == arr[i])
        {
            return true;
        }
    }
    return false;
}

void inizializzaMatriceRandom(int mat[][COLONNE])
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

void inizializzaArrayRandom(int arr[])
{
    for (int i = 0; i < LUNGHEZZA; i++)
    {
        arr[i] = rand() % 10;
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

void stampaArray(int arr[])
{
    for (int i = 0; i < LUNGHEZZA; i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}

int contaNonComuni(int mat[][COLONNE], int arr[])
{
    int cont = 0;
    for (int i = 0; i < RIGHE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {
            if (!presente(mat[i][j], arr))
            {
                cont++;
            }
        }
    }
    return cont;
}

int main()
{
    int matrice[RIGHE][COLONNE];
    inizializzaMatriceRandom(matrice);
    int array[LUNGHEZZA];
    inizializzaArrayRandom(array);
    stampaMatrice(matrice);
    cout << "-----------------------------------------" << endl;
    stampaArray(array);
    cout << "-----------------------------------------" << endl;
    cout << contaNonComuni(matrice, array) << " elementi della matrice non sono presenti nell'array";
}
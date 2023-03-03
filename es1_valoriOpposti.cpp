#include <iostream>
#include <array>
using namespace std;

void inizializza (int arr[], int lung)
{
    for (int i = 0; i < lung; i++) // RIEMPIO L'ARRAY
    {
        arr[i] = (int)NULL;
    }
}

bool presente(int num, int arr[], int lung)
{
    for (int i = 0; i < lung; i++)
    {
        if (num == arr[i])
        {
            return true;
        }
    }
    return false;
}

bool check(int arr[], int lung)
{
    for (int i = 0; arr[i] != 0; i++)
    {
        if (!presente(arr[i] * -1, arr, lung))
        {
            return false;
        }
    }
    return true;
}

bool cercaOpposti(int arr[], int lung)
{
    int i = 0;
    int input = 1;
    while (input != 0 and i < lung)
    {
        cout << "Inserisci numero (0 per terminare): ";
        cin >> input;
        arr[i] = input;
        i++;
    }
    return check(arr, i-1);
}

int main()
{
    int dim = 100;
    int array[dim];
    (cercaOpposti(array, dim)) ? cout << "\nOgni elemento ha il suo opposto" : cout << "\nNon tutti gli elementi hanno il loro opposto";
}
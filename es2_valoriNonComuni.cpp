#include <iostream>
#include <array>
using namespace std;
void riempi(int arr[], int lung)
{
    for (int i = 0; i < lung; i++) // RIEMPIO L'ARRAY
    {
        cout << "Ora inserisci il " << i + 1 << " numero: ";
        cin >> arr[i];
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

int main()
{
    int l1;
    cout << "Lunghezza primo array: ";
    cin >> l1;
    int a1[l1];
    riempi(a1, l1);
    int l2;
    cout << "Lunghezza secondo array: ";
    cin >> l2;
    int a2[l2];
    riempi(a2, l2);
    for (int i = 0; i < l2; i++)
    {
        if (!presente(a2[i], a1, l1))
        {
            cout << a2[i] << endl;
        }
    }
}
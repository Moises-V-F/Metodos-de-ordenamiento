#include <iostream>
#define largo 10

using namespace std;

void mostrar(int n, int arreglo[]);
void selection(int n, int arreglo[]);

int main()
{
    int arreglo[largo] = {2,1,8,9,0,3,5,7,4,6};
    mostrar(largo,arreglo);
    cout << endl;
    selection(largo,arreglo);
    mostrar(largo,arreglo);
    return 0;
}

void mostrar(int n, int arreglo[])
{
    for(int i=0;i<n;i++)
    {
        cout << arreglo[i] << " ";
    }
}

void selection(int n, int arreglo[])
{
    int aux, i, j, ubi;
    for(i=0;i<n-1;i++)
    {
        ubi = i;
        for(j=i+1;j<n;j++)
        {
            if(arreglo[j]<arreglo[ubi])
            {
                ubi = j;
            }
            aux=arreglo[ubi];
        }
        arreglo[ubi] = arreglo[i];
        arreglo[i] = aux;
    }
}

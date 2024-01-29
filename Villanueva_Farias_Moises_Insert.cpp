#include <iostream>
#define largo 10

using namespace std;

void mostrar(int n, int arreglo[]);
void insertar(int n,int  arreglo[]);

int main()
{
    int arreglo[largo] = {2,1,8,9,0,3,5,7,4,6};
    mostrar(largo, arreglo);
    cout << endl;
    insertar(largo, arreglo);
    mostrar(largo, arreglo);
    return 0;
}

void mostrar(int n, int arreglo[])
{
    for(int i=0;i<n;i++)
    {
        cout << arreglo[i] << " ";
    }
}

void insertar(int n, int arreglo[])
{
    int i, aux, j;
    for(i=0;i<n;i++)
    {
        aux = arreglo[i+1];
        j = i;
        while((aux<arreglo[j]) && (j >=0))
        {
            arreglo[j+1] = arreglo[j];
            arreglo[j] = aux;
            j--;
        }
    }
}

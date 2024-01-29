#include <iostream>
#define largo 10

using namespace std;

void mostrar(int n, int arreglo[]);
void burbuja(int n, int arreglo[]);

int main()
{
    int arreglo[largo] = {2,1,8,9,0,3,5,7,4,6};
    mostrar(largo, arreglo);
    cout << endl;
    burbuja(largo, arreglo);
    mostrar(largo, arreglo);

    return 0;
}

void mostrar(int n, int arreglo[])
{
    for(int i=0; i<n; i++)
    {
        cout << arreglo[i] << " ";
    }
}

void burbuja(int n, int arreglo[])
{
    int aux;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(arreglo[j]>arreglo[j+1])
        {
            aux = arreglo[j];
            arreglo[j] = arreglo[j+1];
            arreglo[j+1] = aux;
        }
    }
}

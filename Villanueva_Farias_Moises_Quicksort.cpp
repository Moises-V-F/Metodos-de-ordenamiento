#include <iostream>
#define largo 10

using namespace std;

void quicksort(int arreglo[], int izq, int der);
void mostrar(int n, int arreglo[]);

int main()
{
    int arreglo[largo]={1,7,5,2,4,0,9,3,6,8};
    mostrar(largo,arreglo);
    cout << endl;
    quicksort(arreglo, 0, largo-1);
    mostrar(largo,arreglo);
    return 0;
}

void quicksort(int arreglo[], int izq, int der)
{
    int i, d, x, aux;
    i = izq;
    d = der;
    x = arreglo[(izq + der) / 2];
    do
    {
        while((x > arreglo[i]) && (d <= der))
        {
            i++;
        }
        while((x < arreglo[d]) && (izq < d))
        {
            d--;
        }
        if( i <= d)
        {
            aux = arreglo[i];
            arreglo[i] = arreglo[d];
            arreglo[d] = aux;
            i++;
            d--;
        }
    }while( i <= d);
    if(izq < d)
    {
        quicksort(arreglo, izq, d);
    }
    if(i < der)
    {
        quicksort(arreglo, i, der);
    }

}

void mostrar(int n, int arreglo[])
{
    for(int i=0;i<n;i++)
    {
        cout << arreglo[i] << " ";
    }
}

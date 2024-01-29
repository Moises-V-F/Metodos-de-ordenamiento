/*
    *------------------------*
    |Villanueva Farías Moisés|
    |09/03/2020              |
    |Metodo de ordenamiento  |
    |Radixsort               |
    *------------------------*
*/
#include <iostream>
#define largo 10

using namespace std;

void mostrar(int contenedor[]);

int getmax(int contenedor[], int n);
void countsort(int contenedor[], int n, int exp);
void radixsort(int contenedor[], int n);

int main()
{
    int contenedor[largo]={89,22,10,37,14,28,23,45,0,66};
    int n=largo;
    mostrar(contenedor);
    cout << "" << endl;
    radixsort(contenedor,n);
    mostrar(contenedor);
    return 0;
}

int getmax(int contenedor[],int n)
{
    int maxx = contenedor[0];
    for(int i=1;i<n;i++)
    {
        if(contenedor[i]>maxx)
        {
            maxx = contenedor[i];
        }
    }
    return maxx;
}

void countsort(int contenedor[],int n,int exp)
{
    int salida[n];
    int i, adicion[10]={0};

    for(i=0;i<n;i++)
    {
        adicion[(contenedor[i]/exp)%10]++;
    }
    for(i=1;i<10;i++)
    {
        adicion[i]+=adicion[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        salida[adicion[(contenedor[i]/exp)%10]-1]=contenedor[i];
        adicion[(contenedor[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
    {
        contenedor[i]=salida[i];
    }
}

void radixsort(int contenedor[],int n)
{
    int m=getmax(contenedor,n);

    for(int exp=1;m/exp>0;exp*=10)
    {
        countsort(contenedor,n,exp);
    }
}

void mostrar(int contenedor[])
{
    for(int i=0;i<largo;i++)
    {
        cout << contenedor[i] << " ";
    }
}

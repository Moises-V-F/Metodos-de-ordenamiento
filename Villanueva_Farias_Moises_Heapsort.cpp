/*
    *------------------------*
    |Villanueva Farías Moisés|
    |07/03/2020              |
    |Metodo de ordenamiento  |
    |Heapsort                |
    *------------------------*
*/
#include <iostream>
#define largo 10

using namespace std;

void heapsort(int contenedor[],int n);
void heapsort_sub(int contenedor[],int n, int i);
void mostrar(int contenedor[]);

int main()
{
    int contenedor[largo]={9,2,1,7,4,8,3,5,0,6};
    int n=largo;
    mostrar(contenedor);
    cout << "" << endl;
    heapsort(contenedor,n);
    mostrar(contenedor);
    return 0;
}

void heapsort(int contenedor[], int n)
{
    int aux;
    for(int i = n/2-1; i>=0; i--)
    {
        heapsort_sub(contenedor,n, i);
    }
    for(int i = n-1; i>=0; i--)
    {
        aux=contenedor[0];
        contenedor[0]=contenedor[i];
        contenedor[i]=aux;

        heapsort_sub(contenedor, i, 0);
    }
}

void heapsort_sub(int contenedor[],int n, int i)
{
    int indicador,d,iz,aux;
    indicador=i;
    iz= 2*i+1;
    d= 2*i+2;

    if(iz<n && contenedor[iz]>contenedor[indicador])
    {
        indicador = iz;
    }
    if(d<n && contenedor[d]>contenedor[indicador])
    {
        indicador = d;
    }
    if(indicador != i)
    {
        aux = contenedor[i];
        contenedor[i]=contenedor[indicador];
        contenedor[indicador] = aux;

        heapsort_sub(contenedor,n,indicador);
    }

}

void mostrar(int contenedor[])
{
    for(int i=0;i<largo;i++)
    {
        cout << contenedor[i] << " ";
    }
}

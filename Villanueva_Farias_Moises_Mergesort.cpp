#include <iostream>
#define largo 10

using namespace std;

void mostrar(int arreglo[], int n);
void Merge(int arreglo[], int low, int mid, int high);
void mergeSort(int arreglo[], int low, int high);

int main()
{
    int arreglo[largo] = {2,1,8,9,0,3,5,7,4,6};

    mostrar(arreglo, largo);
    cout << endl;
    mergeSort(arreglo, 0, largo);
    mostrar(arreglo, largo);
    return (0);
}

void mostrar(int arreglo[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout << arreglo[i] << " ";
    }
}

void Merge(int arreglo[], int low, int mid, int high)
{
    int temp[high + 1], i=low, j=mid+1, k=0;

    while(i<=mid && j<=high)
    {
        if(arreglo[i]<=arreglo[j])
        {
            temp[k++] = arreglo[i++];
        }
        else
        {
            temp[k++] = arreglo[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++] = arreglo[i++];
    }
    while(j<=high)
    {
        temp[k++] = arreglo[j++];
    }
    k--;
    while(k>=0)
    {
        arreglo[k + low] = temp[k];
        k--;
    }
}

void mergeSort(int arreglo[], int low, int high)
{
    int mid;

    if(low<high)
    {
        mid = (low + high) / 2;
        mergeSort(arreglo, low, mid);
        mergeSort(arreglo, mid + 1, high);
        Merge(arreglo, low, mid, high);
    }
}



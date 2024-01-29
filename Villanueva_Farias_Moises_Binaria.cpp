#include <iostream>
#define largo 10

using namespace std;

void binaria(int arreglo[], int b, int n);

int main()
{
    int b, arreglo[largo] = {1,2,3,4,5,6,7,8,9,10};
    cout << "Ingrese numero que se buscara 1 a 10: ";
    cin >> b;
//    cout << "Posicion del numero buscado: " <<
    binaria(arreglo, b, largo);
    return 0;
}

void binaria(int arreglo[], int b, int n)
{
    int cal=n-1, i=0, mid;
    do
    {
        mid=(i+cal)/2;
        if(arreglo[mid]<=b)
        {
            i=mid+1;
        }
        if(arreglo[mid]>=b)
        {
            cal=mid-1;
        }

    }while(i<=cal);

    cout << "El numero se encuentra en la posicion: " << mid;
}

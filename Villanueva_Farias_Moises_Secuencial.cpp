#include <iostream>
#define largo 10

using namespace std;

int secuencial(int arreglo[], int b, int n);

int main()
{
    int b, arreglo[largo] = {2,1,8,9,0,3,5,7,4,6};
    cout << "Ingrese numero a buscar de 0 a 9: ";
    cin >> b;
    cout << "Ubicacion del numero buscado: " << secuencial(arreglo, b, largo);
    return 0;
}

int secuencial(int arreglo[], int b, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arreglo[i]==b)
        {
            return i;
            break;
        }
        else if(i==n-1)
        {
            return -1;
            break;
        }
    }
    return 0;
}

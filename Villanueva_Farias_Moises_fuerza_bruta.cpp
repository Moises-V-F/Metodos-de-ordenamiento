#include <iostream>
#define largo 20
#define buscada 10

using namespace std;

void encontrado(int i, int j);

 int main()
{
    int i,j=0,aux;
    char buscar[buscada];
    char cadena[largo]={'i','o','a','k','d','i','d','h','n','m','a','j','a','j','f','l','a','k','d','k'};
    cout << "Ingrese cadena a buscar: ";
    cin >> buscar;
    for(i=0;i<largo;i++)
    {
        if(cadena[i]==buscar[j])
        {
            aux=i+1;
            j++;
            for(aux;aux<largo;aux++)
            {
                if(buscar[j+1]=='\0')
                {
                    encontrado(i,j);
                    break;
                }
                if(cadena[aux]==buscar[j])
                {
                    j++;
                }else{
                    j=0;
                    break;
                }
            }
        }
    }
    return 0;
}

void encontrado(int i, int j)
{
    cout << "Cadena encontrada del indice " << i << " al indice " << j+i;
}

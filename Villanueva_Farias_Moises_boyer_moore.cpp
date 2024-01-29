#include<iostream>
#include <stdlib.h>
#include<string.h>

#define MAXT 1001
#define MAXP 1000

using namespace std;

char        texto[MAXT]={'k','d','k','h','a','l','a','c','m','a'};
char        patron[MAXP] ;
signed int  rep  ;
signed int  comp ;

void preBMBc(char *P, int m, int tabla[])
{
    int i;
    for (i = 0; i < 256; ++i)
        tabla[i] = m;

    for (i = 0; i < m - 1; ++i)
    {
        tabla[P[i]] = m - i - 1;

    }

}

void BMH( char *T, int n , char *P, int m)
{
    int  j , bmBC[256] ;
    char c ;

    preBMBc(P, m, bmBC) ;


    j = 0;
    while (j <= n - m)
    {
        c = T[j + m - 1] ;

        if ( P[m - 1] == c && memcmp(P, T + j, m - 1) == 0 )
        {
             cout<<" * Encontrado en : "<< j + 1 << endl;
             rep ++ ;
        }

        j = j + bmBC[c] ;     comp ++ ;

    }
}

int main()
{
    rep = 0 ;

    cout<<endl<<" Ingrese Patron : \n" ;
    cin >> patron;

    int n  = strlen( texto ) ;
    int m  = strlen( patron ) ;

    BMH( texto , n , patron , m ) ;

    if(rep  == 0)
        cout<<endl<<endl<<" >> Patron no encontrado ..! " ;
    else
        cout<<endl<<endl<<" >> Ocurrencias : "<< rep ;

    cout<<endl<<endl<<" >> Comparaciones : "<< comp ;
    return 0;
}

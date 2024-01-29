#include <iostream>
#include <string.h>
#define MAX(A,B) (A>B) ? A : B ;
#define largo 100
#define largo_d 50

using namespace std;

int M,N;

int *Prefijo(char P[], int *Delta)
{
  Delta[1] = 0;
  int k = 0;

  for( int i = 2; i <= M; i++ )
     {
      while( (k > 0) && ( P[k + 1] != P[i]))
            k = Delta[k];

      if (P[k + 1] == P[i])
          k++;

      Delta[i] = k;

      cout<<endl<<" Delta["<<i<<"] : "<<Delta[i]<<endl;
     }

  return Delta;

}

void Morris_Pratt_Matcher(char T[], char P[])
{
  int *Delta = new int[largo_d];

  Delta = Prefijo(P,Delta);

  int j = 0 ;

  for ( int i = 1; i <= N ; i++)
      {

       while( (j > 0) && ( P[j + 1] != T[i]))
            j = Delta[j];

       if (P[j + 1] == T[i])
          j++;

       if ( j == M)
          {
           cout<<"Match en : "<<i - M<<endl<<endl;
           j = Delta[j];
         }
    }

}


int main()
{
 char Texto[largo]={'s','k','d','j','a','h','e','m','f','b'},Patron[largo];
 do
   {
    cout<<"Ingrese Patron : ";
    cin>>Patron;

    M = strlen(Patron);
    N = strlen(Texto);


    if( M > N )
       cout<<"ERROR!!! Texto > Patron... \n";

   }
 while( M > N );


 Morris_Pratt_Matcher(Texto,Patron);
}

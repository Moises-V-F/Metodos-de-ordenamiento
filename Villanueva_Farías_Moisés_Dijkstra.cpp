/*
    *------------------------*
    |Villanueva Farías Moisés|
    |12/05/2020              |
    |Algoritmo dijktra funci-|
    |on para encontrar el    |
    |camino más corto entre  |
    |dos puntos dados        |
    *------------------------*
*/

#include <iostream>
#include <iomanip>
#include <list>
 using namespace std;

struct label {
   int nro;
   int prev;
   int peso;
   int marca;
};
typedef struct label label_t;

using namespace std;

void dijkstra( int, int **, int, int );

int main () {


   int numNodos = 10;

   int i, j, **A;

   if ( ( A = new int*[numNodos] ) == NULL ) return 1;
   for ( i = 0; i < numNodos; i++ )
      if ( ( A[i] = new int[numNodos] ) == NULL ) return 1;

   for ( i = 0; i < numNodos; i++ )
      for ( j = 0; j < numNodos; j++ )
         A[i][j] = 0;


   A[0][1] = 105;
   A[0][2] = 127;
   A[0][5] = 218;

   A[1][0] = 105;
   A[1][2] = 231;
   A[1][3] = 186;

   A[2][0] = 127;
   A[2][1] = 231;
   A[2][3] = 150;
   A[2][4] = 190;
   A[2][5] = 118;

   A[3][1] = 186;
   A[3][2] = 150;
   A[3][4] = 115;
   A[3][8] = 196;

   A[4][2] = 190;
   A[4][5] = 104;
   A[4][7] = 142;
   A[4][8] = 136;
   A[4][3] = 115;
   A[4][6] = 129;


   A[5][2] = 118;
   A[5][4] = 104;
   A[5][7] = 134;

   A[6][5] = 84;
   A[6][4] = 129;
   A[6][7] = 50;
   A[6][9] = 79;

   A[7][6] = 50;
   A[7][9] = 99;
   A[7][8] = 109;
   A[7][4] = 142;
   A[7][5] = 134;

   A[8][3] = 196;
   A[8][4] = 136;
   A[8][7] = 109;
   A[8][9] = 168;

   A[9][6] = 79;
   A[9][7] = 99;
   A[9][8] = 168;

    cout<<"DIJKSTRA \n\n\n";
    cout<<"0.-Punto de entrega 1"<<endl;
    cout<<"1.-Punto de entrega 3"<<endl;
    cout<<"2.-Punto de entrega 5"<<endl;
    cout<<"3.-Punto de entrega 4"<<endl;
    cout<<"4.-Punto de entrega 8"<<endl;
    cout<<"5.-Punto de entrega 2"<<endl;
    cout<<"6.-Punto de entrega 6"<<endl;
    cout<<"7.-Punto de entrega 10"<<endl;
    cout<<"8.-Punto de entrega 7"<<endl;
    cout<<"9.-Punto de entrega 9"<<endl;

    int origen, destino;
    cout<<"seleccione el punto de entrega inicio: ";
    cin>>origen;
    cout<<"seleccione punto de entrega destino: ";
    cin>>destino;

    cout<<"presione enter para continur";
    cout<<endl;


   cout << "Matriz de adyacencia:" << endl << endl;
   for ( i = 0; i < numNodos; i++ ) {
      for ( j = 0; j < numNodos; j++ )
         cout << setw(2) << A[i][j] << "  ";
      cout << endl;
   }
   cout << endl;

   dijkstra( numNodos, A, origen,destino);

   delete [] A;
   for ( i = 0; i < numNodos; i++ )
      delete A[i];

   return 0;
}

void dijkstra( int N, int **A, int a, int b ) {

   label_t *Labels;
   int i, i0, j, peso;
   int *ruta;

   if ( ( Labels = new label_t[N] ) == NULL ) return;

   if ( a < 0 || a > N - 1 ) return;

   if ( b < 0 || b > N - 1 ) return;


   for ( i = 0; i < N; i++ ) {
      Labels[i].nro = i;
      if ( i != a ) {
         Labels[i].prev = -1;
         Labels[i].peso = -1;
         Labels[i].marca = 0;
      }
      else {
         Labels[i].prev = -1;
         Labels[i].peso = 0;
         Labels[i].marca = 0;
      }
   }

   while ( 1 ) {
      peso = -1;
      i0 = -1;
      for ( i = 0; i < N; i++ ) {
         if ( Labels[i].marca == 0 && Labels[i].peso >= 0 )
            if ( peso == -1 ) {
               peso = Labels[i].peso;
               i0 = i;
            }
            else if ( Labels[i].peso <= peso ) {
               peso = Labels[i].peso;
               i0 = i;
            }
      }
      if ( i0 == -1 ) {
         cout << "Ya no quedan nodos por analizar." << endl;
         break;
      }

      cout << "Analizando nodo " << i0 << endl;

      for ( i = 0; i < N; i++ ) {
         if ( A[i0][i] > 0 ) {

            if ( Labels[i].peso == -1 || Labels[i0].peso + A[i0][i] < Labels[i].peso ) {
               if ( Labels[i0].peso + A[i0][i] < Labels[i].peso )
                  cout << "   [ mejorando coste de nodo " << i << " ]" << endl;
               Labels[i].peso = Labels[i0].peso + A[i0][i];
               Labels[i].prev = i0;
               cout << "   coste de nodo " << i << " desde nodo " << i0 << ": " << Labels[i].peso << endl;
            }
         }
      }
      Labels[i0].marca = 1;
      cout << "   [ nodo " << i0 << " marcado ]" << endl;

      for ( i = 0; i < N; i++ ) {
         cout << i << ": [";
         if ( Labels[i].peso == -1 ) cout << "Inf";
         else cout << Labels[i].peso;
         cout << ", " << Labels[i].prev ;
         if ( Labels[i].marca == 1 ) cout <<  ", x]" << endl;
         else cout << "]" << endl;
      }
      cout << endl;
      cout<<endl;

   }

   int longitud = 2;
   i = b;
   while ( ( i = Labels[i].prev ) != a ) longitud++;
   if ( ( ruta = new int[longitud] ) == NULL ) return;

   ruta[longitud - 1] = b;
   i = b;
   j = 0;
   for ( j = 1; j < longitud; j++ ) {
      i = Labels[i].prev;
      ruta[longitud - j - 1] = i;
   }

   cout << endl << "Ruta mas corta entre nodo " << a << " y nodo " << b << ":" << endl << endl;
   for ( i = 0; i < longitud; i++ ) {
      cout << ruta[i];
      if ( i < longitud - 1 ) cout << " - ";
   }
   cout << endl << endl << "Costo total: " << Labels[b].peso << endl << endl;

   delete ruta;
   delete [] Labels;
}

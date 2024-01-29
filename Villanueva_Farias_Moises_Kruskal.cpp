/*
    *-------------------------*
    |Villanueva Farías Moisés |
    |02/05/2020               |
    |Algoritmo kruskal        |
    |Tiene el mismo objetivo  |
    |que dijkstra buscar      |
    |camions cortos, pero en  |
    |este caso busca unicame- |
    |nte el arbol de expansion|
    |mas corto o el que cubre |
    |con menos peso en total  |
    los puntos del grafo
    *-------------------------*
*/
#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 1005

using namespace std;

int padre[ MAX ];


void MakeSet( int n ){
    for( int i = 1 ; i <= n ; ++i ) padre[ i ] = i;
}


int Find( int x ){
    return ( x == padre[ x ] ) ? x : padre[ x ] = Find( padre[ x ] );
}


void Union( int x , int y ){
    padre[ Find( x ) ] = Find( y );
}


bool sameComponent( int x , int y ){
    if( Find( x ) == Find( y ) ) return true;
    return false;
}


int V , E;
struct Edge{
    int origen;
    int destino;
    int peso;
    Edge(){}

    bool operator<( const Edge &e ) const {
        return peso < e.peso;
    }
}arista[ MAX ];
Edge MST[ MAX ];

void Kruskal(){
    int origen , destino , peso;
    int total = 0;
    int numAristas = 0;

    MakeSet( V );
    std::sort( arista , arista + E );

    for( int i = 0 ; i < E ; ++i ){
        origen = arista[ i ].origen;
        destino = arista[ i ].destino;
        peso = arista[ i ].peso;


        if( !sameComponent( origen , destino ) ){
            total += peso;
            MST[ numAristas++ ] = arista[ i ];
            Union( origen , destino );
        }
    }


    if( V - 1 != numAristas ){
        puts("No existe MST valido para el grafo ingresado, el grafo debe ser conexo.");
        return;
    }
    cout << "Kruskal\n\n\n";
    puts( "El arbol Minimo Expandido encontrado contiene las siguientes aristas");
    for( int i = 0 ; i < numAristas ; ++i )
        cout << MST[ i ].origen << " - " << MST[ i ].destino << " - " << MST[ i ].peso << endl;

    cout << "El costo minimo de todas las aristas es : " << total ;
}

int main(){
    int mst;
    V=11;
    E=24;



        arista[0].origen=0; arista[0].destino=1; arista[0].peso=250;
        arista[1].origen=0; arista[1].destino=2; arista[1].peso=310;
        arista[2].origen=0; arista[2].destino=3; arista[2].peso=299;
        arista[3].origen=0; arista[3].destino=4; arista[3].peso=345;
        arista[4].origen=0; arista[4].destino=5; arista[4].peso=450;

        arista[5].origen=1; arista[5].destino=5; arista[5].peso=230;
        arista[6].origen=1; arista[6].destino=9; arista[6].peso=312;

        arista[7].origen=2; arista[7].destino=3; arista[7].peso=170;
        arista[8].origen=2; arista[8].destino=6; arista[8].peso=415;

        arista[9].origen=3; arista[9].destino=6; arista[9].peso=317;
        arista[10].origen=3; arista[10].destino=4; arista[10].peso=190;

        arista[11].origen=4; arista[11].destino=6; arista[11].peso=330;
        arista[12].origen=4; arista[12].destino=7; arista[12].peso=180;
        arista[13].origen=4; arista[13].destino=5; arista[13].peso=180;

        arista[14].origen=5; arista[14].destino=7; arista[14].peso=314;
        arista[15].origen=5; arista[15].destino=8; arista[15].peso=267;
        arista[16].origen=5; arista[16].destino=9; arista[16].peso=255;

        arista[17].origen=6; arista[17].destino=7; arista[17].peso=230;
        arista[18].origen=6; arista[18].destino=10; arista[18].peso=300;

        arista[19].origen=7; arista[19].destino=10; arista[19].peso=275;
        arista[20].origen=7; arista[20].destino=8; arista[20].peso=198;

        arista[21].origen=8; arista[21].destino=10; arista[21].peso=225;
        arista[22].origen=8; arista[22].destino=9; arista[22].peso=280;

        arista[23].origen=9; arista[23].destino=10; arista[23].peso=450;


    Kruskal();

    return 0;
}

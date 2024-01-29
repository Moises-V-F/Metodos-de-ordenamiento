/*
    *------------------------*
    |Villanueva Farías Moisés|
    |22/03/2020              |
    |Busqueda de mejor camino|
    |en un grafo no dirigido |
    |Dijkstra                |
    *------------------------*
*/
#include <iostream>
#include <queue>
#include <vector>
#define MAXV 100
#define oo 0x3f3f3f3f
#define Libreria_Gadner 1
#define Libreria_Fibonacci 2
#define Libreria_Voronoi 3
#define Libreria_Euler 4
#define Casita 5
#define Libreria_Hilbert 6
#define Libreria_Fahrenheit 7
#define Libreria_Gauss 8
#define Libreria_Konisberg 9
#define Libreria_Richter 10
#define Libreria_Celsius 11

using namespace std;


struct Edge
{
	int node;
	int cost;
	Edge(int _node, int _cost) : node(_node), cost(_cost) {}
	Edge() : node(-1), cost(-1) {}
};

struct Graph
{
	vector<Edge> G[MAXV];
	int V;
	int E;
};

struct State
{
	int node;
	int cost;
	State(int _node, int _cost) : node(_node), cost(_cost) {}
	bool operator <(const State &b) const
	{
		return cost > b.cost;
	}
};

int contenedor[100]={0}, f;

int algoritmo(const int begin, const int end, const Graph graph)
{
    int a=0;
	priority_queue<State> pq;
	vector<int> Dist(graph.V, oo);
	vector<bool> mark(graph.V, false);

	Dist[begin] = 0;
	pq.push(State(begin, 0));
	while(!pq.empty())
	{
		State st = pq.top(); pq.pop();
		mark[st.node] = true;
		contenedor[a]=st.node;
		a++;
		if (st.node == end)
        {
            f=a;
            return st.cost;
        }

		int T = (int)graph.G[st.node].size();
		for(int i = 0; i < T; ++i)
		{

			if (!mark[graph.G[st.node][i].node] && ((Dist[st.node] + graph.G[st.node][i].cost) < Dist[graph.G[st.node][i].node]))
			{
				Dist[graph.G[st.node][i].node] = st.cost + graph.G[st.node][i].cost;
				pq.push(State(graph.G[st.node][i].node, st.cost + graph.G[st.node][i].cost));
			}
		}
	}
	f=a;
	return -1;
}

struct Programa
{
	int V, E;
	int comienzo, fin;
	void definirGrafo(Graph& graph)
	{
		graph.V = 11;
		graph.E = 24;
	}
	void cargarGrafo(Graph & graph)
	{

			graph.G[Libreria_Gadner].push_back(Edge(Libreria_Fibonacci, 310));
			graph.G[Libreria_Fibonacci].push_back(Edge(Libreria_Gadner, 310));

			graph.G[Libreria_Gadner].push_back(Edge(Libreria_Voronoi, 170));
			graph.G[Libreria_Voronoi].push_back(Edge(Libreria_Gadner, 170));

			graph.G[Libreria_Gadner].push_back(Edge(Libreria_Euler, 415));
			graph.G[Libreria_Euler].push_back(Edge(Libreria_Gadner, 415));

			graph.G[Libreria_Fibonacci].push_back(Edge(Libreria_Voronoi, 299));
			graph.G[Libreria_Voronoi].push_back(Edge(Libreria_Fibonacci, 299));

			graph.G[Libreria_Fibonacci].push_back(Edge(Casita, 345));
			graph.G[Casita].push_back(Edge(Libreria_Fibonacci, 345));

			graph.G[Libreria_Fibonacci].push_back(Edge(Libreria_Fahrenheit, 450));
			graph.G[Libreria_Fahrenheit].push_back(Edge(Libreria_Fibonacci, 450));

			graph.G[Libreria_Fibonacci].push_back(Edge(Libreria_Hilbert, 250));
			graph.G[Libreria_Hilbert].push_back(Edge(Libreria_Fibonacci, 250));

			graph.G[Libreria_Voronoi].push_back(Edge(Casita, 190));
			graph.G[Casita].push_back(Edge(Libreria_Voronoi, 190));

			graph.G[Libreria_Voronoi].push_back(Edge(Libreria_Euler, 317));
			graph.G[Libreria_Euler].push_back(Edge(Libreria_Voronoi, 317));

			graph.G[Libreria_Euler].push_back(Edge(Casita, 330));
			graph.G[Casita].push_back(Edge(Libreria_Euler, 330));

			graph.G[Libreria_Euler].push_back(Edge(Libreria_Gauss, 230));
			graph.G[Libreria_Gauss].push_back(Edge(Libreria_Euler, 230));

			graph.G[Libreria_Euler].push_back(Edge(Libreria_Konisberg, 300));
			graph.G[Libreria_Konisberg].push_back(Edge(Libreria_Euler, 300));

			graph.G[Casita].push_back(Edge(Libreria_Fahrenheit, 180));
			graph.G[Libreria_Fahrenheit].push_back(Edge(Casita, 180));

			graph.G[Casita].push_back(Edge(Libreria_Gauss, 180));
			graph.G[Libreria_Gauss].push_back(Edge(Casita, 180));

			graph.G[Libreria_Hilbert].push_back(Edge(Libreria_Fahrenheit, 230));
			graph.G[Libreria_Fahrenheit].push_back(Edge(Libreria_Hilbert, 230));

			graph.G[Libreria_Hilbert].push_back(Edge(Libreria_Celsius, 312));
			graph.G[Libreria_Celsius].push_back(Edge(Libreria_Hilbert, 312));

			graph.G[Libreria_Fahrenheit].push_back(Edge(Libreria_Gauss, 314));
			graph.G[Libreria_Gauss].push_back(Edge(Libreria_Fahrenheit, 314));

			graph.G[Libreria_Fahrenheit].push_back(Edge(Libreria_Richter, 267));
			graph.G[Libreria_Richter].push_back(Edge(Libreria_Fahrenheit, 267));

			graph.G[Libreria_Fahrenheit].push_back(Edge(Libreria_Celsius, 255));
			graph.G[Libreria_Celsius].push_back(Edge(Libreria_Fahrenheit, 255));

			graph.G[Libreria_Gauss].push_back(Edge(Libreria_Konisberg, 275));
			graph.G[Libreria_Konisberg].push_back(Edge(Libreria_Gauss, 275));

			graph.G[Libreria_Gauss].push_back(Edge(Libreria_Richter, 198));
			graph.G[Libreria_Richter].push_back(Edge(Libreria_Gauss, 198));

			graph.G[Libreria_Konisberg].push_back(Edge(Libreria_Richter, 225));
			graph.G[Libreria_Richter].push_back(Edge(Libreria_Konisberg, 225));

			graph.G[Libreria_Konisberg].push_back(Edge(Libreria_Celsius, 450));
			graph.G[Libreria_Celsius].push_back(Edge(Libreria_Konisberg, 450));

			graph.G[Libreria_Richter].push_back(Edge(Libreria_Celsius, 280));
			graph.G[Libreria_Celsius].push_back(Edge(Libreria_Richter, 280));

	}
	void Dijkstra(Graph graph)
	{
		cout << "Ingrese Vertice Inicial: " << endl;
		cin >> comienzo;
		cout << "Ingrese Vertice Final: " << endl;
		cin >> fin;
		int n = algoritmo(comienzo, fin, graph);
		cout << "Longitud del Camino mas Corto: " << n << endl;
	}
	void mostar()
	{
	        for(int i=0;contenedor[i]!=0;i++)
            {
                cout << contenedor[i] << " ";
            }
	}
};

int main()
{


	Programa programa;
	Graph graph;

	cout << "Algoritmo de Dijkstra en C++" << endl;
	cout << "1.-Libreria Gadner" << endl;
	cout << "2.-Libreria Fibonacci" << endl;
	cout << "3.-Libreria Voronoi" << endl;
	cout << "4.-Libreria Euler" << endl;
	cout << "5.-Libreria Casita" << endl;
	cout << "6.-Libreria Hilbert" << endl;
	cout << "7.-Libreria Fahrenheit" << endl;
	cout << "8.-Libreria Gauss" << endl;
	cout << "9.-Libreria Konisberg" << endl;
	cout << "10.-Libreria Ritcher" << endl;
	cout << "11.-Libreria Celsius" << endl;

	programa.cargarGrafo(graph);
	programa.Dijkstra(graph);
    programa.mostar();

}

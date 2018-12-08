#include <array>

//a
const int Nmax = 100;
using matrix = std::array<std::array<int, Nmax>, Nmax>;

struct graph {
	int som;
	matrix adj;
};

//b
void init (graph &g, int card) {
	g.som = card;
	for(int i=1;i<=g.som;i++)
		for(int j=1;j<=g.som;j++)
			g.adj[i][j]=0;
}

void ajouteArete(graph &g, int i, int j) {
	g.adj[i][j]=1;
	g.adj[j][i]=1;
}


/*int main () {
	graph g;
	init(g,10);

	//b
	ajouteArete(g,1,3);
	ajouteArete(g,2,3);
	ajouteArete(g,2,4);
	ajouteArete(g,4,3);

	ajouteArete(g,5,6);
	ajouteArete(g,6,8);
	ajouteArete(g,8,5);

	ajouteArete(g,7,10);

}*/
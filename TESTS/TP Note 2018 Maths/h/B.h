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


graph makeGraphB () {
	graph B;
	init(B,10);

	ajouteArete(B,1,3);
	ajouteArete(B,2,3);
	ajouteArete(B,2,4);
	ajouteArete(B,4,3);

	ajouteArete(B,5,6);
	ajouteArete(B,6,8);
	ajouteArete(B,8,5);

	ajouteArete(B,7,10);

	return B;
}

/* 

B.h est le meme fichier que B.cpp (ln B.cpp -T ./h/B.h)
Le main ici est commente' pour pouvoir l'utiliser 
dans C.cpp et D.cpp

*//*int main () {
	graph g = makeGraphB();
}*/
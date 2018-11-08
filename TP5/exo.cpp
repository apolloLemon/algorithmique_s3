#include <iostream>
#include <fstream>

//a
#include <array>
const int DEFAULT_SIZE = 10;
using matrix = std::array<std::array<bool,DEFAULT_SIZE>,DEFAULT_SIZE>;

//c
using couleurSommet = std::array<int,DEFAULT_SIZE>;
struct matrix_couleur {
	matrix adj;
	couleurSommet clr;
	int size;
};

//b
matrix MatrixZero (int s) {
	matrix out;
	for(int i=0;i<s;i++)
		for(int j=0;j<s;j++)
			out[i][j]=false;
	return out;
}

void ajouteArete(matrix &G, int i, int j){
	G[i][j] = true;
	G[j][i] = true;
}

//d
bool correct (matrix_couleur G){
	for(int i=0;i<G.size;i++)
		for(int j=0;j<G.size;j++)
			if(i!=j && G.adj[i][j] && G.clr[i]==G.clr[j])
				return false;
	return true;
}

//e
int conflits (matrix_couleur G) {
	int out = 0;
	for(int i=0;i<G.size;i++)
		for(int j=i;j<G.size;j++)
			if(i!=j && G.adj[i][j] && G.clr[i]==G.clr[j])
				out++;
	return out;
}

int main () {

	matrix_couleur G;
	std::ifstream graphe("TP5/fichier_graph_colorations/Myciel2.txt");
	graphe >> G.size;
	G.adj = MatrixZero(G.size);

	while(graphe){
		int a,b;
		graphe >>a>>b;
		ajouteArete(G.adj,a-1,b-1);
	}

	std::ifstream coloration("TP5/fichier_graph_colorations/ColNonCorrect1.txt");

	for(int i=0;i<G.size;i++){
		for(int j=0;j<G.size;j++) {
			std::cout <<G.adj[i][j];
		}
		std::cout<<std::endl;
	}

	int i=0;
	while(coloration){
		coloration >> G.clr[i];
		i++;
	}

	std::cout << conflits(G)<<std::endl;
	return 0;
}
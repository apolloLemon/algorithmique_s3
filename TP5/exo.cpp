#include <iostream>

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
	G.size = 5;
	G.adj = MatrixZero(G.size);
	
	ajouteArete(G.adj, 0,1);
	ajouteArete(G.adj, 0,3);
	ajouteArete(G.adj, 1,2);
	ajouteArete(G.adj, 2,4);
	ajouteArete(G.adj, 3,4);

	//G.clr = {1,2,1,2,3};
	G.clr = {1,1,1,2,3};
	
	for(int i=0;i<G.size;i++){
		for(int j=0;j<G.size;j++) std::cout <<G.adj[i][j];
		std::cout<<std::endl;
	}

	std::cout << conflits(G)<<std::endl;
	return 0;
}
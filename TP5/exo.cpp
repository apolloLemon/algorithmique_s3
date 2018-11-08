//a
#include <array>
const int DEFAULT_SIZE = 5;
using matrix = std::array<std::array<bool,DEFAULT_SIZE>,DEFAULT_SIZE>;

//b
matrix MatrixZero (int s) {
	matrix out;
	for(int i=0;i<s;i++)
		for(int j=0;i<s;j++)
			out[i][j]=0;
	return out;
}

void ajouteArete(matrix &G, int i, int j){
	G[i][j] = true;
	G[j][i] = true;
}

//c
using couleurSommet = std::array<int,DEFAULT_SIZE>;
struct matrix_couleur {
	matrix adj;
	couleurSommet clr;
	int size;
};

//d
bool correct (matrix_couleur G){
	for(int i=0;i<G.size;i++)
		for(int j=0;j<G.size;j++)
			if(i!=j && G.adj[i][j] && G.clr[i]=G.clr[j])
				return false;
	return true;
}
//a
#include <array>
const int SIZE = 5;
using matrix = std::array<std::array<bool,SIZE>,SIZE>;

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
using couleurSommet = std::array<int,SIZE>;
struct matrix_couleur {
	matrix adj;
	couleurSommet clr;
};
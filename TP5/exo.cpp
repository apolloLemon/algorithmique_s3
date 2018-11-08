//a
#include <array>
const int SIZE = 5;
using matrix = std::array<std::array<int,SIZE>,SIZE>;

//b
matrix MatrixZero (int s) {
	matrix out;
	for(int i=0;i<s;i++)
		for(int j=0;i<s;j++)
			out[i][j]=0;
	return out;
}
#include <array>
#include <iostream>

//a
const int TABMAX = 10;

using CELL = int *;

struct CELL_link {
	CELL cell;	
	CELL_link * next;
};
using CELL_list = CELL_link *;

using VERTS = std::array<CELL, TABMAX>;
using ARCS = std::array<CELL_list, TABMAX>;

struct graph {
	int size;
	VERTS vert;
	ARCS arcs;
};

//b
void InitGraph (graph &g, int size) {
	g.size = size;
}

graph CreateGraph (int size) {
	graph out;
	out.size = size;
	for(int i=0;i<size;i++){
		out.vert[i] = new int;
		*(out.vert[i]) = i+1;
	}
	return out;
}


void AjouterArc () {

}




//TestCode
void afficheSommet (graph g){

	std::cout << std::endl;
	for(int i=0;i<g.size;i++){
		std::cout << g.vert[i] << " " 
		<< *g.vert[i] << std::endl;
	}

}

int main () {

	graph g;
	g = CreateGraph(5);
	afficheSommet(g);

	return 0;
}
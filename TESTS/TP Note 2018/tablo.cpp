#include <array>

using CELL = int *;

struct CELL_link {
	CELL cell;	
	link * next;
};
using CELL_list = CELL_link *;

struct graph {
	const int Taille;
	std::array<CELL, Taille>;
	std::array<CELL_list,Taille>;
};
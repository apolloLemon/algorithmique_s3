#include <iostream>
#include <cstdlib>

//Exo1
struct link {
	int val;
	link * suiv;
};
using valsRoulette = link *;

struct roulette {
	valsRoulette vals;
	int taille;
};
void init_roulette (roulette &A);
void ajoute_numero (roulette &A, int n);
roulette creer_roulette (int n);
void tourner_roulette (roulette &A);
int lancer_roulette (roulette &A);


//a
struct nt {
	char a;
	int g;
	std::array<nt*,3> s;
	int ss;
	roulette r;
};

//b
struct graph {
	int taille;
	nt * start;
};

//c
nt makeKnot (char a, int g, int r){
	nt out;
	out.a = a;
	out.g = g;
	out.ss = 0;
	out.r = creer_roulette(r);
}

void addChildKnot (nt &A, nt &B) {
	if(A.ss>3) return;
	A.s[A.ss++] = B;
}

graph creer_graph () {
	graph out;
	out.taille = 1;
	out.start = &makeKnot('A',5,3);

}

int main (){
	graph a;
	a = creer_graph;
}









//Exo1
void init_roulette (roulette &A){
	A.vals = nullptr;
	A.taille = 0;
}
void ajoute_numero (roulette &A, int n) {
	A.taille++;
	valsRoulette tmp = new link;
	tmp->val = n;

	tmp->suiv = A.vals;
	if(A.vals == NULL){
		A.vals = tmp;
		tmp->suiv = tmp;
	} else if (A.vals == A.vals->suiv){
		A.vals->suiv = tmp;
	} else {
		valsRoulette i = A.vals;
		while(i->suiv != A.vals) i = i->suiv;
		i->suiv = tmp;
	}

	tmp->suiv = A.vals;
}
roulette creer_roulette (int n) {
	roulette out;
	init_roulette(out);

	for(int i=0;i<n;i++){
		ajoute_numero(out, i);
	}
	return out;
}
void tourner_roulette (roulette &A){
	A.vals = A.vals->suiv;
}
int lancer_roulette (roulette &A) {
	int a = rand()%A.taille;
	for(int i=0;i<a;i++){
		tourner_roulette(A);
	}
	return A.vals->val;
}
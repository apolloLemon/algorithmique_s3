#include <iostream>
#include <cstdlib>
#include <array>

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
using ntptr = nt *;

//b
struct graph {
	int taille;
	std::array<nt*,100> knots;
};

//c
nt makeKnot (char a, int g){
	nt out;
	out.a = a;
	out.g = g;
	out.s = {nullptr,nullptr,nullptr};
	out.ss = 0;
	return out;
}

void addChildKnot (nt* A, nt* B) {
	if(A->ss>3) return;
	A->s[A->ss++] = B;
}

graph creer_graph () {
	graph out;
	for(int i='A';i<='N';i++){
		ntptr newknot = new nt;
		*newknot = makeKnot((char)i,rand()%50);
		out.knots[i-'A'] = newknot;
	}

	addChildKnot(out.knots['A'-'A'],out.knots['B'-'A']);
	addChildKnot(out.knots['A'-'A'],out.knots['C'-'A']);
	addChildKnot(out.knots['A'-'A'],out.knots['D'-'A']);
	addChildKnot(out.knots['B'-'A'],out.knots['E'-'A']);
	addChildKnot(out.knots['B'-'A'],out.knots['F'-'A']);
	addChildKnot(out.knots['B'-'A'],out.knots['G'-'A']);
	addChildKnot(out.knots['C'-'A'],out.knots['F'-'A']);
	addChildKnot(out.knots['C'-'A'],out.knots['G'-'A']);
	addChildKnot(out.knots['C'-'A'],out.knots['H'-'A']);
	addChildKnot(out.knots['D'-'A'],out.knots['G'-'A']);
	addChildKnot(out.knots['D'-'A'],out.knots['H'-'A']);
	addChildKnot(out.knots['D'-'A'],out.knots['I'-'A']);
	addChildKnot(out.knots['E'-'A'],out.knots['J'-'A']);
	addChildKnot(out.knots['E'-'A'],out.knots['K'-'A']);
	addChildKnot(out.knots['F'-'A'],out.knots['J'-'A']);
	addChildKnot(out.knots['F'-'A'],out.knots['K'-'A']);
	addChildKnot(out.knots['F'-'A'],out.knots['L'-'A']);
	addChildKnot(out.knots['G'-'A'],out.knots['K'-'A']);
	addChildKnot(out.knots['G'-'A'],out.knots['L'-'A']);
	addChildKnot(out.knots['G'-'A'],out.knots['M'-'A']);
	addChildKnot(out.knots['H'-'A'],out.knots['L'-'A']);
	addChildKnot(out.knots['H'-'A'],out.knots['M'-'A']);
	addChildKnot(out.knots['H'-'A'],out.knots['N'-'A']);
	addChildKnot(out.knots['I'-'A'],out.knots['M'-'A']);
	addChildKnot(out.knots['I'-'A'],out.knots['N'-'A']);
	return out;
}

//d
void detruirGraph (graph a){
	for(int i=0;i<a.taille;i++){
		ntptr tmp = a.knots[i];
		a.knots[i]=nullptr;
		delete tmp;
	}
	a.taille = 0;
}

//e
nt* entree (graph a){
	return a.knots[0];
}

//f
bool est_feuille (nt a){
	return (a.ss = 0);
}

//g
int nb_fils (nt a){
	return a.ss;
}

//h
nt* fils_n(nt a, int n){
	return a.s[n-1];
}

//i
void installer_roulettes (graph &A){
	for(int i=0;i<A.taille;i++){
		A.knots[i]->r = creer_roulette(nb_fils(*A.knots[i]));
	}
}

//j
int jouer (graph A){
	int out = 0;
	nt knot = *entree(A);
	while(not est_feuille(knot)){
		out+=knot.g;
		knot = *fils_n(knot,lancer_roulette(knot.r));
	}
	return out+knot.g;
}


int main (){
	srand(342789);
	graph a;
	a = creer_graph();

	std::cout << a.knots[0]->a <<std::endl;
	std::cout << a.knots[0]->s[0]->a <<std::endl;

	std::cout << jouer(a)<<std::endl;
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
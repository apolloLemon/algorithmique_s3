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
	int gain;

};

int main (){
	roulette a;
	a = creer_roulette(5);
}

//b
void init_roulette (roulette &A){
	A.vals = nullptr;
	A.taille = 0;
}

//c
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

//d
roulette creer_roulette (int n) {
	roulette out;
	init_roulette(out);

	for(int i=0;i<n;i++){
		ajoute_numero(out, i);
	}
	return out;
}

//e
void tourner_roulette (roulette &A){
	A.vals = A.vals->suiv;
}

//f
int lancer_roulette (roulette &A) {
	int a = rand()%A.taille;
	for(int i=0;i<a;i++){
		tourner_roulette(A);
	}
	return A.vals->val;
}
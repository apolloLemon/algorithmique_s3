#include <iostream>
#include <cstdlib>

//a
struct link {
	int val;
	link * suiv;
};
using valsRoulette = link *;

struct roulette {
	valsRoulette vals;
	int taille;
};

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

int main () {
	srand(time(NULL));

	std::cout << "main"<<std::endl;
	roulette a;
	a = creer_roulette(5);

	tourner_roulette(a);
	tourner_roulette(a);

	valsRoulette i = a.vals;
	do {
		std::cout << i->val << std::endl;
		i = i->suiv;
	} while(i != a.vals);
	std::cout <<a.taille<<std::endl;
	std::cout << std::endl;
	std::cout <<lancer_roulette(a)<<std::endl;

	std::cout <<"end"<<std::endl;
	return 0;
}
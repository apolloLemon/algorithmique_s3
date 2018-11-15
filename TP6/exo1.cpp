#include <iostream>

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
	//std::cout << "init_roulette"<<std::endl;
	A.vals = nullptr;
	A.taille = 0;
}

//c
void ajoute_numero (roulette &A, int n) {
	//std::cout << "ajoute_numero"<<std::endl;
	A.taille++;
	valsRoulette tmp = new link;
	//std::cout << "ajoute_numero 1"<<std::endl;
	tmp->val = n;

	tmp->suiv = A.vals;
	if(A.vals == NULL){
	//std::cout << "ajoute_numero NULL"<<std::endl;		
		A.vals = tmp;
		tmp->suiv = tmp;
	} else if (A.vals == A.vals->suiv){
		//std::cout << "ajoute_numero uno"<<std::endl;
		A.vals->suiv = tmp;
	} else {
		valsRoulette i = A.vals;
		//std::cout << "ajoute_numero 3"<<std::endl;
		while(i->suiv != A.vals) i = i->suiv;
		//std::cout << "ajoute_numero 4"<<std::endl;
		i->suiv = tmp;
	}

	tmp->suiv = A.vals;

		
}

//d
roulette creer_roulette (int n) {
	//std::cout << "creer_roulette"<<std::endl;
	roulette out;
	init_roulette(out);

	for(int i=0;i<n;i++){
		ajoute_numero(out, i);
	}
	return out;
}

int main () {

	std::cout << "main"<<std::endl;
	roulette a;
	a = creer_roulette(5);

	valsRoulette i = a.vals;
	do {
		std::cout << i->val << std::endl;
		i = i->suiv;
	} while(i != a.vals);
	std::cout <<a.taille<<std::endl;

	std::cout <<"end"<<std::endl;
	return 0;
}
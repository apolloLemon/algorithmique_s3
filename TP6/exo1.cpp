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
	A->vals = NULL;
	A->taille = 0;
}

//c
void ajoute_numero (roulette &A, int n) {
	valsRoulette tmp = new link;
	tmp->val = n;
	tmp->suiv = A;
	roulette i = A;
	while(i->suiv != A) i = i->suiv;
	i->suiv = tmp;	
}
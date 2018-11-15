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
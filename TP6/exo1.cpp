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
	A.taille++;
	valsRoulette tmp = new link;
	tmp->val = n;
	tmp->suiv = A.vals;
	valsRoulette i = A.vals;
	while(i->suiv != A.vals) i = i->suiv;
	i->suiv = tmp;	
}

//d
roulette creer_roulette (int n) {
	roulette out;
	init_roulette(out);

	for(int i=0;i<n;i++){
		ajoute_numero(out, i);
	}
}

int main () {



	return 0;
}
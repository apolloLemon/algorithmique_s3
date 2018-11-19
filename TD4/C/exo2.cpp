struct knot {
	char a;
	knot * g;
	knot * d;
};
using tree = knot *;

const int TAILLE = 100;
using Tab = std::array<tree,TAILLE>;

struct PILE {
	Tab val;
	int som;
};

bool PileVide(PILE a);
void Empiler(PILE &a, int x);
int Depiler(PILE &a);
void AffichePile(PILE a);

void affiche_Prefix_Iteratif_with_help (tree A) {
	if(A==NULL) return;

	PILE P; P.som = 0;
	tree current;
	Empiler(P,A);
	while(!PileVide(P)){
		current = Depiler(P);
		std::cout<<current->val<<" ";
		if(current->d!=NULL){
			Empiler(P,current->d)
		}
		if(current->g!=NULL){
			Empiler(P,current->g)
		}
	}
}
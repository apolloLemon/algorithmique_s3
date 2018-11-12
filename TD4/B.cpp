//a
struct noeud {
	int var;
	noeud * gauche;
	noeud * droit;
};
using arbre_bi = noeud *;


//b
int poids (arbre_bi A){
	if(A==NULL) return 0;
	return A.var + poids(A.gauche) + poids(A.droit);
}
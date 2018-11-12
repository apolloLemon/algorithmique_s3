//a
struct noeud {
	int val;
	noeud * gauche;
	noeud * droit;
};
using arbre_bi = noeud *;


//b
int poids (arbre_bi A){
	if(A==NULL) return 0;
	return A->val + poids(A->gauche) + poids(A->droit);
}

//c
bool pere (arbre_bi A){
	return (A->gauche != NULL or A->droit != NULL);
}

bool est_bien_forme (arbre_bi A){
	if(A->gauche == NULL and A->droit == NULL) return true;

	//if(A->droit != NULL and A->gauche != NULL)
	return (A->val > 
	((int)pere(A->droit)*A->droit->val 
	+ (int)pere(A->gauche)*A->gauche->val)) 
	&& est_bien_forme(A->droit) 
	&& est_bien_forme(A->gauche);
	/*
	Only works on complete Trees
	*/
}



//c Correction
bool est_feuille (arbre_bi A){
	if(A==NULL) return false;
	else return (A->gauche==NULL && A->droit==NULL);
}

bool est_bien_forme (arbre_bi A){
	if(A==NULL) return true;
	else {
		if(est_feuille(A)) return true;
		else {
			bool gauche, droit;
			if(A->gauche!=NULL){
				if(est_feuille(A->gauche) && (a->gauche->val >= a->val)) return false;
				else gauche = est_bien_forme(A->gauche);
			}
			if(A->droit!=NULL){
				if(est_feuille(A->droit) && (a->droit->val >= a->val)) return false;
				else droit = est_bien_forme(A->droit);
			}
		}
	}
}
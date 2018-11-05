//1
struct LMent {
	int val;
	LMent * next;
};

using liste = *LMent;

//2
float moyenne (liste L){
	if (L==NULL) return 0;
	else{
		float nb = 0;
		int somme = 0;
		Liste p=L;
		while(p!=NULL){
			somme+=p->val;
			nb++;
			p=p->suiv;
		}
	}
	return somme/nb;
}

//3
void supp_double (List &L){
	Liste p1,p2;
	p1=L;
	while(p1!=NULL){
		p2=p1->suiv;
		while(p2!=NULL){
			if(p1->val==p2->val) supp(p2);
			p2=p2->suiv;
		}
	}
}

//4
void PremAuBout (Liste &L){
// 4.a : Il n'y a pas besoin de reserver plus de memoire

	Liste p = L;
	if(L!=NULL){
		while(p->suiv != NULL) p=p->suiv;
		p->suiv = L;
		p=L;
		L=L->suiv;
		p->suiv=NULL;
	}
// 4.c : O(n)
}

//5
struct Liste_Autre {
	Liste debut;
	Liste fin;
};

void PremAuBout(Liste_Autre &L) {
	fin->suiv = debut;
	fin = debut;
	debut = debut->suiv;
	fin->suiv = NULL;
}
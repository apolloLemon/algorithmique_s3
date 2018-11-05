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
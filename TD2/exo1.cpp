struct element {
	int val;
	element * suiv;
}

using Liste = element *;


int main (){}

//a
bool triee (Liste L){
	if((L==NULL) || (L->suiv==NULL)) return 1;
	return 
		(L->val < L->suiv->val) and triee(L->suiv);
}

//b
void ajoute_debut (Liste &L, int x) {
	a = new element;
	a->val = x;
	a->suiv = L;
	L = a;
}

void insert (Liste L, int x){
	if(L==NULL or x < L->val) {
		ajoute_debut(L,x);
	}
	else insert(L->suiv,x);
}
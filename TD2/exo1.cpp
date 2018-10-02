struct element {
	int val;
	element * suiv;
}

using Liste = element *;


int main (){}

//a
int triee (Liste L){
	if((L==NULL) || (L->suiv==NULL)) return 1;
	return 
		(L->val < L->suiv->val) and triee(L->suiv);
}


struct LMent {
	int val;
	LMent * next;
};

using Liste = LMent *;

/*
Liste vide:
Liste = NULL;

Une liste avec un LMent
LMent a;
a->next = a;
*/

bool Vide (Liste a) {
	if (a==NULL) return true;
	else return false;
}

bool one_LMent (Liste a){
	if(Vide(a)) return false;
	return (a==a->next);
}

void affiche_Liste (const Liste &a) {}
// const & optimise la copie
//et protege le pointeur 

void affiche_Liste (Liste a) {
	if(Vide(a)) return;
	a=a->next; //car la liste pointe vers le dernier

	Liste premier = a;
	do{
		std::cout << a->val << std::endl;
		a = a->next; 					//1
	} while (a != premier);				//n
}

int length_iteratif (Liste a) {
	int out = 0;
	Liste b = a;
	do {
		out++;
		a = a->next;
	} while (a != b);

	return out;
}

int length_recursif (Liste a, Liste b) {
	if(a==NULL) return 0;
	if(a==b) return 1;
	return 1+length_recursif(a->next, b);
}
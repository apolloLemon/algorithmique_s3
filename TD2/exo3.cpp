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

void affiche_Liste (Liste a) {
	

	a=a->next; //car la liste pointe vers le dernier

	Liste premier = a;
	do{
		std::cout << a->val << std::endl;
		a = a->next; 					//1
	} while (a != premier);		//n
}


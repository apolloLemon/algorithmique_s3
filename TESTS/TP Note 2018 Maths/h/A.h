#include <iostream>

struct link {
	int val;
	link * suiv;
};

using pile = link *;

void initPile (pile &p) {
	p = nullptr;
}

int sommet (pile p) {
	return p->val;
}

void depiler (pile &p) {
	pile tmp = p;
	p=p->suiv;
	delete tmp;
}

void empiler (pile &p, int x) {
	pile tmp = new link;
	tmp->val = x;
	tmp->suiv = p;
	p = tmp;
}

bool vide (pile p) {
	return (p==nullptr);
}

/*int main () {

	pile a;
	initPile(a);

	for (int i=1;i<=10;i++){
		std::cout << "empiler " << x <<std::endl;
		empiler(a,i);
	}
	while(!vide(a)){
		std::cout << "depiler " << sommet(p) <<std::endl;
		depiler(a);
	}
	return 0;
}*/
struct noeud {
	int e;
	noeud * g;
	noeud * d;
};
using tree = noeud *;

void rotation_gauche (tree &a){

	tree p = a;
	a = a->d;
	p->d = a->g;
	a->g = p;

	//tree i = a->g;
	//while(i->g!=nullptr) i=i->g; wrong
	//i->g = tmp;

}

void rotation_droite (tree &a) {

	tree p = a;
	a = a->g;
	p->g = a->d;
	a->d = p;

}

void rotation_gauche_droite (tree &a) {
	rotation_gauche(a->g);
	rotation_droite(a);
}
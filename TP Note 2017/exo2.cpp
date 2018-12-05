#include <iostream>
#include <string>

//1
struct knot {
	std::string str;
	knot * g;
	knot * d;
	knot * p;
};
using AB = knot *;

//2
void initArbre (AB &a){
	a=nullptr;
	a->p = nullptr;
}

//3
void addKnot_to (AB &a, std::string etiq, AB parent){
	a = new knot;
	a->str = etiq;
	a->g=a->d=nullptr;
	a->p = parent;
	//std::cout << a << std::endl;
}

void addKnot (AB &a, char s, std::string etiq){
	if(s=='G'){
		addKnot_to(a->g, etiq);
	} else 
	if(s=='D'){
		addKnot_to(a->d, etiq);	
	}
}

//4
bool est_feuille (AB a) {
	return (!a->g) and (!a->d);
}

//5
bool est_interne (AB a) {
	return !est_feuille(a);
}

//6
AB addressOf (AB a, std::string etiq) {
	if(a==nullptr) return NULL;
	if(a->str == etiq) return a;
	AB g = addressOf(a->g, etiq);
	AB d = addressOf(a->g, etiq);
	if(g) return g;
	else return d;
}

//7
void afficheNoeud (AB a) {
	std::cout << a->str <<std::endl;
}


void affiche_prefixe (AB a) {
	if(!a) return;
	afficheNoeud(a);
	//std::cout<<a->g<<std::endl;
	affiche_prefixe(a->g);
	//std::cout<<a->d<<std::endl;
	affiche_prefixe(a->d);
}

//8
int main (){

	AB a;
	addKnot_to (a, "Usine");
	addKnot(a,'G',"Depot A");
	addKnot(a,'D',"Depot B");
	addKnot(a->g,'G',"Magasin 1");
	addKnot(a->g,'D',"Magasin 2");
	addKnot(a->d,'G',"Depot C");
	addKnot(a->d,'D',"Magasin 5");
	addKnot(a->d->g,'G',"Magasin 3");
	addKnot(a->d->g,'D',"Magasin 4");


	affiche_prefixe(a);

	return 0;
}

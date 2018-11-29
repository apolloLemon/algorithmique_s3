#include <iostream>

//a
struct knot {
	int x;
	knot * g;
	knot * d;
};
using BiTree = knot *;

//b
void ajouteFeuille (BiTree &a, BiTree &b) {
	if(b->x > a->x){
		if(a->d!=nullptr) ajouteFeuille(a->d,b);
		else a->d=b;

	} else { 
	
		if(a->g!=nullptr) ajouteFeuille(a->g,b);
		else a->g=b;
	}
}

void ajouteFeuille (BiTree &a, int e) {
	BiTree b = new knot;
	b->x = e;

	if(a==nullptr) a = b;
	else ajouteFeuille(a,b);	
}

//c
void afficheNoeud (BiTree a){
	std::cout <<"@ "<< a << "\te = " <<a->x
		<<"\t\tg@ "<<a->g<<"\td@ "<<a->d<<std::endl;
}

void afficheBiTree (BiTree a) {
	if(a->g!=nullptr) afficheBiTree(a->g);
	if( a  !=nullptr) afficheNoeud(a);
	if(a->d!=nullptr) afficheBiTree(a->d);
}


int main (){
	BiTree a;
	a=nullptr;
	ajouteFeuille(a,2);
	ajouteFeuille(a,1);
	ajouteFeuille(a,8);
	ajouteFeuille(a,94);
	ajouteFeuille(a,33);
	ajouteFeuille(a,4);
	ajouteFeuille(a,9);
	ajouteFeuille(a,-1);
	ajouteFeuille(a,-60);

	afficheBiTree(a);

}
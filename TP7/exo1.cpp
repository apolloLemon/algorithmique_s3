#include <iostream>
#include <ctime>
#include <cstdlib>

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

//d
bool intree (BiTree a, int x) {
	if(a==nullptr) return false;

	return intree(a->g,x) or a->x == x or intree(a->d,x);

}







//tester Code
void randomTree(BiTree &a, int s, int m){
	for(int i=0;i<s;i++){
		ajouteFeuille(a,rand()%m+1);
	}
}

int main (){
	srand(time(NULL));
	BiTree a;
	a=nullptr;
	randomTree(a,10,20);

	afficheBiTree(a);

	std::cout<<"Is 3 is"<<(intree(a,3)?" ":"n't ")<<"in the tree\n";
}
#include <string>

//1
struct knot {
	std::string str;
	knot * g;
	knot * d;
};
using AB = knot *;

//2
void initArbre (AB &a){
	a=nullptr;
}

//3
void addKnot_to (AB &a, std::string etiq){
	a = new knot;
	a->str = etiq;
	a->g=a->d=nullptr;
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


int main (){return 0;}

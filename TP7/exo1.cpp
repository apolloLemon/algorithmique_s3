//a
struct knot {
	int x;
	knot * g;
	knot * d;
};
using BiTree = knot *;

//b
void ajouteFeuille (BiTree &a, BiTree &b) {
	if(b.x > a.x){
		if(a->d!=NULL) ajouteFeuille(a->d,b);
		else a.d=b;

	} else { 
	
		if(a->g!=NULL) ajouteFeuille(a->g,b);
		else a.g=b;
	}
}

void ajouteFeuille (BiTree &a, int e) {
	BiTree b = new knot;
	b.x = e;

	if(a==NULL) a = b;
	else ajouteFeuille(a,b);	
}
/*a
M R F O A D I L B E

F O R M I D A B L E
*/

/*b
P = Prefix: L D N W O U R E F
I = Infixe: W N O D L E R U F

On cherche P[0] dans I, je note I[i] -> noeud actuel
Avec les char I[j] je cree les souschaines:
	I_gauche si j < i
	I_droite si j > i
Avec les char P[k] je cree' les souschaines:
	P_gauche si 0 < k <= longeur(I_gauche)
	P_droite si k > longeur(I_gauche)

On recommance avec les couples de souchaines:
P_gauche, I_gauche  et  P_droite, I_droite
*/
int position(Ch,c);
char caractere(Ch,i);
int longeur(Ch);
string sousChaine(Ch,deb,nbCar);

struct knot {
	char a;
	knot * g;
	knot * d;
};
using tree = knot *;

void creerArbre(tree &A,string P, string I){
	A->a = P[0];
	int Ia = position(I,A->a);
	
	//Ia = longeur(Ig)
	string Ig = sousChaine(I,0,Ia);
	string Id = sousChaine(I,Ia+1,longeur(I)-Ia-1);
	string Pg = sousChaine(P,1,Ia);
	string Pg = sousChaine(P,Ia+1,longeur(Id));


	if(length(Pg)!=0){
		tree g = new knot;
		A->g = g;
		creerArbre(A->g,Pg,Ig);
	}
	
	if(length(Pd)!=0){
		tree d = new knot;
		A->d = d;
		creerArbre(A->d,Pd,Id);
	}
}
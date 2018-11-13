/*a
M R F O A D I L B E

E O R M I D A B L E
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
	
	string Ig = sousChaine(I,0,Ia);
	string Id = sousChaine(I,Ia,longeur(I)-Ia-1);
	string Pg = sousChaine(P,1,longeur(Ig));
	string Pg = sousChaine(P,longeur(Ig),longeur(Id));

	tree g = new knot;
	tree d = new knot;
	A->g = g; A->d = d;
	creerArbre(A->g,Pg,Ig);
	creerArbre(A->d,Pd,Id);
}
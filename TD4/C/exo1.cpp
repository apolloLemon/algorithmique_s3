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
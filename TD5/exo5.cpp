/*
d(a)=h(a->g)-h(a->d)
if(d(a)) = {-1,0,1} => equilibre'

if(d(a)) == -2 => right is heavier
d(a->d) == -1 => rg(a) will balance the tree
d(a->d) == 1 => rgd(a) -> rd(a)rg(a->d)

d(a) == 2 => left is heavier
d(a->g) == 1 => rg(a)
d(a->g) == -1 => rdg(a)

*/


//teacher code
void ajout (tree &a, int x){
	while(!feuille(a)){
		if(x >= a->val) {
			empiler(a->d, P)
			while(!vide(P)){
				t = depile(P)
				if (d(t)=2 or -2) {
					cherche_bonne_rotation(t);
				}
			}
		}
		else { //(x < a->val)
			//opposite
		}
	}
}
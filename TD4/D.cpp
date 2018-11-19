/*a
On represente traditionnellement 
un arbre n-aire par un arbre binaire
car c'est une representation simple
*/

//Db.jpg

//c
bool estfeuille (knot* a){
	return (a->g == NULL && a!=NULL);
}

//d
void affiche_fils (knot* a){
	if(estfeuille(a))return;
	a=a->d;
	while(a!=NULL){
		affiche(a->val);
		a=a->d;
	}
}
//a
struct ArbreParfait {
	char arr[] = {'H','D','K','B','F','J','L','A','C','E','G','I'};
	int taille;	
};


//b
void affiche_infixe (ArbreParfait A){

	A.taille;

	int hauteur;

	int i=0;
	while(pow(2,i) < A.taille) i++;
	hauteur = i;


	affiche_infixe(ArbreParfait )

	affiche_infixe(ArbreParfait )
}

void infixe_corr(ArbreParfait T, int lect){
	if(2*lect <= T.taille)
		infixe(T,2*lect);
	afficher(T.arr[lect]);
	if(2*lect+1 <= T.taille)
		infixe(T,2*lect+1);
}
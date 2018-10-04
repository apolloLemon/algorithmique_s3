struct maillon {
	int val;
	maillon * suiv;
}

using Liste = maillon *;

Liste L;
L = NULL;

L = new maillon;
(*L).val = 75;
(*L).suiv = NULL;

L->val;
L->suiv;

L->suiv->suiv->val;
(*(*(*L).suiv).suiv).val;


/*
Pointeur 		type* varName
valeur pointe' 	type *varName
*/
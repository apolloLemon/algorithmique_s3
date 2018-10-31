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





InserTrie (Liste L, int e) {
	Liste nouveau = new maillon;
	nouveau->val = e;
	if(L==NULL){
		nouveau->suiv=NULL;
		L=nouveau;
	} else {
		Liste p = L;
		if(p->val > e){
			nouveau->suiv = p;
			p = nouveau;
		} else {
			while ((p->suiv != NULL) && (p->val < e)){
				p=p->suiv;
				if(p->suiv == NULL){
					p->suiv = nouveau;
					nouveau->suiv = NULL;
				} else {
					nouveau->suiv = p->suiv;
					p->suiv = nouveau;
				}
			}
		}
	}
}

InserTrieR (Liste &L, int e){
	if(L==NULL){
		L=new maillon;
		L->suiv=NULL;
		L->val = e;
	} else {
		if (e<=L->val){
			Liste nouveau = new maillon;
			nouveau->val = e;
			nouveau->suiv = L;
			L=nouveau;
		}else{
			InserTrieR(L->suiv,e);
		}
	}
}
#include <iostream>

struct maillon {
	int valeur;
	maillon *precedent, *suivant;
};

struct liste {
	maillon *tete, *queue;
	int taille;
};

/*
 * Retourne une liste vide
 * O(1)
 */
liste creer_vide() {
	liste l;

	l.tete = NULL;
	l.queue = NULL;
	l.taille = 0;
	
	return l;
}

/*
 * Retourne vrai si la liste 'l' est vide, faux sinon
 * O(1)
 */
bool est_vide(liste l) {
	return (l.tete == NULL);
}

/*
 * Ajoute l'élément 'elt' en tête de la liste 'l'
 * O(1)
 */
void inserer_tete(liste &l, int elt) {
	maillon *nouveau = new maillon;

	nouveau->valeur = elt;
	nouveau->precedent = NULL;
	nouveau->suivant = l.tete;
	if(est_vide(l)) {
		l.queue = nouveau;
	} else { 
		l.tete->precedent = nouveau;
	}
	
	l.tete = nouveau;
	l.taille++;
}

/*
 * Ajoute l'élément 'elt' en queue de la liste 'l'
 * O(1)
 */
void inserer_queue(liste &l, int elt) {
	maillon *nouveau = new maillon;
	
	nouveau->valeur = elt;
	nouveau->precedent = l.queue;
	nouveau->suivant = NULL;
	if(est_vide(l)) {
		l.tete = nouveau;
	} else { 
		l.queue->suivant = nouveau;
	}
	
	l.queue = nouveau;
	l.taille++;
}

/*
 * Affiche les éléments de la liste 'l' de la tête jusqu'à la queue
 * Version itérative
 * O(n)
 */
void affiche_tete_queue(liste l) {
	maillon *m = l.tete;
	
	while(m != NULL) {
		std::cout << m->valeur << " ";
		m = m->suivant;
	}
	
	std::cout << std::endl;
}

/*
 * Affiche la valeur du maillon 'm' puis les maillons suivants
 * Si 'm' est NULL, on affiche simplement un retour à la ligne
 * Version récursive
 */
void affiche_queue_tete_rec(maillon *m) {
	if(m != NULL) {
		std::cout << m->valeur << " ";
		affiche_queue_tete_rec(m->precedent);
	} else {
		std::cout << std::endl;
	}
}

/*
 * Affiche les éléments de la liste 'l' de la queue jusqu'à la tête
 * Version récursive
 * O(n)
 */
void affiche_queue_tete(liste l) {
	affiche_queue_tete_rec(l.queue);
}

/*
 * Retourne la taille de la liste 'l'
 * Version itérative (version récursive inutile)
 * O(1)
 */
int taille_liste(liste l) {
	return l.taille;
}

/*
 * Supprime l'élément en tête de la liste 'l'
 * O(1)
 */
void supprime_tete(liste &l) {
	if(!est_vide(l)) {
		maillon *supp = l.tete;
		
		l.tete = l.tete->suivant;
		if(l.tete != NULL) {
			l.tete->precedent = NULL;
		} else {
			l.queue = NULL;
		}
		
		delete supp;
		l.taille--;
	}
}

/*
 * Supprime l'élément en queue de la liste 'l'
 * O(1)
 */
void supprime_queue(liste &l) {
	if(!est_vide(l)) {
		maillon *supp = l.queue;
		
		l.queue = l.queue->precedent;
		if(l.queue != NULL) {
			l.queue->suivant = NULL;
		} else {
			l.tete = NULL;
		}
		
		delete supp;
		l.taille--;
	}
}

/*
 * Retourne le pointeur vers le maillon contenant l'élément 'elt' dans la liste 'l', ou NULL s'il n'est pas présent
 * Version itérative
 * O(n)
 */
maillon * recherche_elt(liste l, int elt) {
	maillon *m = l.tete;
	
	while((m != NULL) && (m->valeur != elt)) {
		m = m->suivant;
	}
	
	return m;
}

/*
 * Implémentation de la recherche récursive.
 * Retourne le pointeur vers le maillon contenant l'élément 'elt' dans la liste débutant par 'm', NULL s'il n'est pas présent
 * Version récursive
 */
maillon * recherche_elt_rec_imp(maillon *m, int elt) {
	if((m == NULL) || (m->valeur == elt)) {
		return m;
	} else {
		return recherche_elt_rec_imp(m->suivant, elt);
	}
}

/*
 * Retourne le pointeur vers le maillon contenant l'élément 'elt', ou NULL s'il n'est pas présent
 * Version récursive
 * O(n)
 */
maillon * recherche_elt_rec(liste l, int elt) {
	return recherche_elt_rec_imp(l.tete, elt);
}

/*
 * Libère l'espace mémoire utilisé par la liste
 * O(n)
 */
void supprimer_liste(liste &l) {
	while(!est_vide(l)) {
		supprime_tete(l);
	}
}

int main() {
	liste l;
	
	l = creer_vide();
	if(est_vide(l)) {
		std::cout << "Liste vide. (OK)" << std::endl;
	} else {
		std::cout << "Liste non-vide. (ERREUR)" << std::endl;
	}
	
	inserer_tete(l, 1);
	if(est_vide(l)) {
		std::cout << "Liste vide. (ERREUR)" << std::endl;
	} else {
		std::cout << "Liste non-vide. (OK)" << std::endl;
	}
	
	liste l2;
	l2 = creer_vide();
	inserer_queue(l2, 2);
	if(est_vide(l2)) {
		std::cout << "Liste vide. (ERREUR)" << std::endl;
	} else {
		std::cout << "Liste non-vide. (OK)" << std::endl;
	}
	
	inserer_tete(l, 0);
	inserer_queue(l, 2);
	inserer_queue(l, 3);
	affiche_tete_queue(l); // 0 1 2 3
	affiche_queue_tete(l); // 3 2 1 0
	
	inserer_queue(l2, 3);
	inserer_tete(l2, 1);
	inserer_tete(l2, 0);
	affiche_tete_queue(l2); // 0 1 2 3
	affiche_queue_tete(l2); // 3 2 1 0
	
	std::cout << "taille_liste(l) = " << taille_liste(l) << std::endl; // 4
	std::cout << "taille_liste(l2) = " << taille_liste(l2) << std::endl; // 4
	
	supprime_tete(l);
	affiche_tete_queue(l); // 1 2 3
	
	supprime_queue(l2);
	affiche_queue_tete(l2); // 2 1 0
	
	std::cout << "Recherche de 1 dans l : " << (recherche_elt(l, 1) == NULL ? "absent" : "présent") << std::endl; // présent
	std::cout << "Recherche de 0 dans l : " << (recherche_elt(l, 0) == NULL ? "absent" : "présent") << std::endl; // absent
	
	std::cout << "Recherche de 3 dans l2 : " << (recherche_elt_rec(l2, 3) == NULL ? "absent" : "présent") << std::endl; // absent
	std::cout << "Recherche de 2 dans l2 : " << (recherche_elt_rec(l2, 2) == NULL ? "absent" : "présent") << std::endl; // présent
	
	supprimer_liste(l);
	supprimer_liste(l2);
	
	if(est_vide(l)) {
		std::cout << "Liste vide. (OK)" << std::endl;
	} else {
		std::cout << "Liste non-vide. (ERREUR)" << std::endl;
	}
	
	return 0;
}

#include "./h/A.h"
#include "./h/B.h"

void Parcours (graph g, int start) {
	//array de sommets marques
	std::array<bool,Nmax> marque;
	for(int i=1; i<=g.som;i++) marque[i] = false;

	pile p;
	empiler(p,start);
	
	while(!vide(p)) {
		int s = sommet(p);depiler(p);
		std::cout << s << std::endl;
		marque[s] = true;
		for(int i=1;i<=g.som;i++)
			if(g.adj[s][i] && !marque[i])
				empiler(p,i); 
				//marque[i] = true; //ceci empaiche les doublons dans l'affichage
	}
}

int main () {

	//Graph B
	graph g = makeGraphB();


	for(int i=1;i<=g.som;i++){
		std::cout << "\nParcours a' partir de "<<i<<std::endl;
		Parcours(g,i);
	}

	return 0;
}
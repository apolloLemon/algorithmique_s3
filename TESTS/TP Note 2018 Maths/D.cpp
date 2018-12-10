#include "./h/A.h"
#include "./h/B.h"

using connexes = std::array<int,Nmax>;
using connexeMatrix = std::array<std::array<int,Nmax>,Nmax>;

connexes ParcoursComp (graph g) {
	//array de sommets marques'
	//change' de bool -> int pour l'indice du connexe
	connexes marque;
	marque[0]=g.som;
	for(int i=1; i<=g.som;i++) marque[i] = 0;

	int i=0; //indice du connexe
	for(int j=1; j<=g.som;j++){
		if(marque[j]) continue;
		i++; //on est dans un nouveau connexe

		pile p;
		empiler(p,j);
		
		while(!vide(p)) {
			int s = sommet(p);depiler(p);
			//std::cout << s << std::endl;
			marque[s] = i;
			for(int i=1;i<=g.som;i++)
				if(g.adj[s][i] && !marque[i])
					empiler(p,i); 
					//marque[i] = true; //ceci empaiche les doublons dans l'affichage
		}
	}

	return marque;
}

int nombreComposantes (connexes c){
	int out=1;
	for(int i=1;i<=c[0];i++)
		if(c[i]>out) out = c[i];
	return out;
}

void afficheConnexe (connexes c){
	for(int i=1;i<=c[0];i++){
		std::cout << c[i] << " : "<<i<<std::endl;
	}
}

void zeroMat (connexeMatrix &M) {
	for(int i=1;i<=M[0][0];i++)
		for(int j=1;j<=M[0][0];j++)
			M[i][j]=0;
}

connexeMatrix connexeToMatrix (connexes c) {
	connexeMatrix out;
	out[0][0] = nombreComposantes(c);
	zeroMat(out);

	for(int i=1;i<=c[0];i++){
		out[c[i]][i]=i;
	}
	return out;
}

void afficheMat (graph g,connexeMatrix M){
	for(int i=1;i<=M[0][0];i++){
		std::cout << "Connexe "<<i<<std::endl;
		for(int j=1;j<=g.som;j++)
			if(M[i][j]) std::cout << M[i][j] << " ";
		std::cout<<std::endl;
	}
}

int main () {

	//Graph B
	graph g = makeGraphB();

	//afficheConnexe(ParcoursComp(g));

	std::cout<<std::endl;

	afficheMat(g,connexeToMatrix(ParcoursComp(g)));


	return 0;
}
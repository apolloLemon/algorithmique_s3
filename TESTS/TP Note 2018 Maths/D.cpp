#include "./h/A.h"
#include "./h/B.h"
;
using connexes = std::array<int,Nmax+1>;
using connexeMatrix = std::array<std::array<int,Nmax>,Nmax>;

connexes ParcoursComp (graph g) {
	//array de sommets marques'
	//change' de bool -> int pour l'indice du connexe
	connexes marque;
	marque[0]=g.som;
	for(int i=1; i<=g.som;i++) marque[i] = 0;

	for(int j=1; j<=g.som;j++){
		pile p;
		empiler(p,j);
		
		int i=0; //indice du connexe
		while(!vide(p)) {
			int s = sommet(p);depiler(p);
			if(marque[s]) continue; //si un sommet est dans un connexe, on skip

			i++; //on est dans un nouveau connexe
			std::cout << s << std::endl;
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

void zeroMat (connexeMatrix &M) {
	for(int i=1;i<=M[0][0];i++)
		for(int j=1;j<=M[0][0];j++)
			M[i][j]=1;
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

	afficheMat(g,connexeToMatrix(ParcoursComp(g)));


	return 0;
}
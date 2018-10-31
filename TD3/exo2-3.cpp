//EXO2

//Number of edges of a non oriented graph with n vertices
(N*(N-1))/2

//number of (non)oriented graphs is N nertices
2^((N*(N-1))/2) //(non)

2^(N^2)

//nombre de cycles passant une seul fois par chaque
//sommet d'un graph complet
(n-1)!


//EXO3
/* a
Sp et Sp' sont 2 puits du graph(V,E)

=> forall Si =/= Sp in E => Sp'->Sp in E
Sp' est un puit
=> forall Si =/=, Sp' -> Si not in E => Sp'->Sp notin E
Absurde
*/

//b
//Matrice
int puit (matrice){
	for(i=1;i<=N;i++){ //O(N^2)
		int a=0;
		for(j=1;j<=N;j++){
			if(i!=j) a+=matrice[i][j];
		}
		if(a==0){ //O(N)
			int b=0;
			for(k<N){
				b+=matrice[k][i];
			}
			if(b>=N-1) return i;
		}
	}
	return 0;
} //O(N^2)

//Matrice Prof
bool est_puit (matrice, s) {
	for(i=1;i<N){
		if(j!=i){
			if(matrice[s][i]==1 or matrice[i][s]==0)
				return false;
		}
	}
	return true;
} //O(n)
int Trouve_Puit (matrice) {
	for(i<N){
		if(est_puit(matrice,i))
			return i;
	}
	return 0;
} //O(n^2)

//Liste d'adjacance
bool test_liste(liste, i) {
	if (liste != NULL){
		if(liste->val==i) return true;
		else return test_liste(liste->suiv, i);
	}
	else return false;
} //O(n)
int test_puit (ListeA,i) {
	for(j<N)
		if(j!=i and !test_liste(ListeA[j],i))
			return false;

	if(ListeA[i]==NULL or (ListeA[i]->val==i and ListeA[i]->suiv==NULL))
		return true;
	else return false;
} //O(n^2)
int Trouve_Puit (ListeA) {
	for(i<N){
		if(test_puit(ListeA,i))
			return i;
	}
	return 0;
} //O(n^3)
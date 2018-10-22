/* GRAPHES Oriente'
Nombre de Sommets = N
nombre arc = p
nombre max d'arcs sortant d'un sommet = m
*/


//Operations Matrices
Matrice[N][N] = {
	{0,1,1,...},
	{1,0,0,...},
	{1,1,1,...},
	...
}


//deternimer un arc entre i et j
bool arc_existant (matrice, i, j){
	return matrice[i][j];
} //O(1)

//ajouter un arc entre i et j
matrice[i][j] = 1; //O(1)

//retirer un arc entre i et j
matrice[i][j] = 0; //O(1)

//calculer degree d'un somet s
int deg_S (matrice, s){
	int deg = 0
	for(i<N){
		deg += matrice[s][i];
		deg += matrice[i][s];
	}
	return deg;
}

//tout les sucesseurs d'un sommet s
void successeurs (matrice,s){
	for(i<N)
		if(matrice[s][i]) //we have a successor
} //O(N)


//tout les predecesseurs
void  pred (matrice,s){
	if(i<N)
		if(matrice[i][s]) //we have a pedecessor
} //O(N)




//Operation liste d'ajacence
using liste = std::array<int,N>
using listeA = std::array<liste,m>

//determiner un arc entre i et j
bool arc_existant (ListeA, i, j){
	Liste L = ListeA[i]
	while((L!=NULL) && (L->suiv!=j)){ //O(N) //O(n)
		L = L->suiv;
	}
	if(L==NULL) return false;
	else return true;
}

//ajouter un arc entre i et j
void add_arc (ListeA,i,j){
	Liste L = new maillon;
	L->val = j;
	L->suiv =  ListeA[i]
	ListeA[i] = L
} //O(1)
/*assuming the edge doesn't already exist
we can just add to the head of the list*/

//calculer degree d'un sommet s
int deg_S (ListeA,s) {
	int deg = 0;
	for(i<N) {
		if(i!=s){
			Liste L = ListeA[i] //if Arc_Exists() deg++
			while(L!=NULL){
				if(L->val = s) deg++;
				L = L->suiv;
			}
		}
	}
	Liste L = ListeA[s]
	while(L!=NULL){
		deg++
		L=L->suiv
	}
} //O(N^2)


//Successeurs de S
void successor (ListeA, s) {
	liste L = ListeA[s]
	while(L!=NULL){
		//we have a successor
		L=L->suiv;
	}
} //O(m)

//Predecessor de S
void Predecessor (ListeA, s) {
	for(i<N)
		if(Arc_Exists(ListeA,i,s)) //we have a pred
}//O(N^2)
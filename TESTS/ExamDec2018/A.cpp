/*1

Le tableau Place est de dimension n+1 pour stocker une valeur de 'debut liste de successeurs de i+1'
on utilise Place[i] comme indice de debut de 'liste de successeurs de i'
Place[i+1]-1 comme indice de fin de 'liste de successeurs de i'

Si tout les sommets sont connectees' a' tout les autres sommets pour n sommets on aurra (n(n-1))/2 arc
mais on peu aussi se limiter a' une liste de taille egale a' place[i+1]-1 car c'est de dernier indice utile

*/

//2
struct Graph { // de Representation par tableau de successeurs
	int n;
	array<int, n+1 > place;
	array<int, (n*(n-1))/2 > successeurs;
	//array<int, place[n]-1> successeurs; //ou
};

//3
bool arcEntre(int i, int j, Graph g) {
	for(int k = g.place[i]; k < g.place[i+1]; k++)
		if(successeurs[k]==j) return true;

	return false;
}

//4
int sommetMaxDeg (Graph g) {
	int out=0;
	int degout=0;
	//array<int,g.n> deg; //on peu utiliser un array et stocker tout les deg, mais que celui du max nous interesse
	for(int i=0;i<n;i++){
		int degi=g.place[i+1]-g.place[i];
		if(degi>degout){
			out = i;
			degout=degi;
		}
	}
	return out;
}

//5
int demideginf(int s, Graph g){
	int out=0;
	for(int i=0;i<g.place[g.n];i++)
		if(successeurs[i]==s) out++;
	return out;
}

/*6
On peu stocker un poid pour chaque arc dans une nouvelle dimention pour chaque valeur du tablo successeur
sois array<array<int,place[n]>,2> ou array<array<int,2>,place[n]>
*/
struct Graph_Pondere { // de Representation par tableau de successeurs
	int n;
	array<int, n+1 > place;
	array<int, (n*(n-1))/2 > successeurs;
	array<successeurs, 2> successeursPondere;
};
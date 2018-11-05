using liste = std::array<int,SIZE>;
using matrix = std::array<liste,SIZE>;

matrix adjacance;

liste visites;
int parcours_Proffondeur(matrix adj, int sommet, liste visites, int dist){
	if(visites[s]==1) return;
	visites[s] = 1;
	for(int i=0;i<SIZE;i++){
		if(s==i) continue;

		if(adj[s][i]!=0){
			cout << "De "<<s<<" a' "<<i<<" : "<<adj[s][i]<<" dist (Total: "<<dist+=adj[s][i]<<")\n";

			parcours_Proffondeur(adj,i,visites, dist);
		}
	}
}
void long_chemin (mat G, int S, tab &M, tab &longeur){
	M[s]=true;
	printf("%d est visite a une distance de %d de la source",s,longeur[s]);

	for(i<SIZE){
		if(G[s][i]!=-1 && (!M[i])){
			longeur[i] = longeur[s]+G[s][i];
			long_chemin(G,i,M,longeur);
		}
	}
}
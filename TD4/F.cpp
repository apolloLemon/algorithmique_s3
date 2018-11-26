/*a
le minimum dans un ABPPO est a' la racine de l'arbre, 
et c'est le premier du arr RPZ l'ABPPO
*/

//Pre-b
using TAS = std::array<int,100>;
struct ABPPO {
	TAS tas;
	int taille;
};

//b
void srtLM (ABPPO &a, int i){
	//if(i%2!=0) i--;
	if(i<1)return;

	if(a.tas[i] < a.tas[i/2]){
		int tmp = a.tas[i];
		a.tas[i]= a.tas[i/2];
		a.tas[i/2]=tmp;
		srtLM(a,i/2);
	}
}

void ajouteLM (ABPPO &a, int x){
	a.tas[++a.taille]=x;

	int i = a.taille;
	srtLM(a,i);
}

//c
void SrtABPPO (ABPPO &a, int i){
	if(i>taille) return;
	if(a.tas[i] > a.tas[i*2] 
		or a.tas[i] > a.tas[i*2+1])	{
		int s = (int)(a.tas[i*2] >= a.tas[i*2+1]);
		swap(a.tas[i],a.tas[2*i+s]);
	}
	SrtABPPO(a,2*i+s);
}

int rmMin (ABPPO &a){
	
}


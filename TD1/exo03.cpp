#include <iostream>

/*
Ecrire un algo qui amene tous les elements nuls en debut
et calcule le nombre de 0 (p)
*/

int main (){
	const int n = 10;
	int Tab[n] = {1,0,0,0,0,1,0,0,0,0};

	int p = 0;

	int i=0;

	while(i<n) {
		if ( Tab[i] == 0 ) {
			Tab[i] = Tab[p];
			Tab[p] = 0;
			p++;
		}
		i++;
	}

	for(int i=0;i<n;i++) std::cout << Tab[i] << std::endl;
	std::cout << "Il y a "<<p<<" zeros"<<std::endl;
}
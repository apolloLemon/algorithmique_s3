#include <iostream>
#include <cstdlib>
#include <array>

const int BUFF = 10;

using Tab = std::array<int, BUFF>;

void InitTab (Tab &T) {
	for(int i=0;i<T.size();i++){
		T[i] = rand();
	}
}

void AffPetitTab (Tab T) {
	if(T.size()>10) return;

	for(int i=0;i<T.size();i++)
		std::cout<<T[i]<<std::endl;
}

void swap (int &a,int &b){
	int c = a;
	a=b;
	b=c;
}

int partage (Tab & T, int i, int j) {
	int l,k;
	int p = T[i];
	l=i+1; k=j;
	while(l<=k){
		while(T[k]>p) k--;
		while(T[l]<=p) l++;
		if(l<k) {
			swap(T[l],T[k]);
			l++;k--;
		}
	}
	swap(T[i],T[k]);
	return k;
}

void Tri_Rapid (Tab & T, int i, int j) {
	int a;
	if(i<j){
		a = partage(T,i,j);
		Tri_Rapid(T,i,a-1);
		Tri_Rapid(T,a+1,j);
	}	
}

int main () {
	srand(time(NULL));
	Tab T;
	InitTab(T); AffPetitTab(T);

	std::cout<<std::endl;

	Tri_Rapid(T,0,T.size()-1); AffPetitTab(T);
}
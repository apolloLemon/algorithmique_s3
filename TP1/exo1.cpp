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

	for(int i=0;i<T.size();i++) {
		std::cout<<T[i]<<std::endl;
	}
}

void Tri_Insertion (Tab &T) {
	for(int i=0;i<T.size();i++){
		int temp = T[i];
		int j=i;
		while(j>0 and temp<T[j-1]){
			T[j]=T[j-1];
			j--;
		}
		T[j]=temp;
	}
}

int main () {
	srand(time(NULL));
	Tab T;
	InitTab(T); AffPetitTab(T);

	std::cout<<std::endl;

	Tri_Insertion(T); AffPetitTab(T);
}
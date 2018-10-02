#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>

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
	Tab A,B;
	InitTab(A); AffPetitTab(A);
	B=A;

	std::cout<<std::endl;

	clock_t A_Time = clock();
	Tri_Insertion(A);
	A_Time = clock()-A_Time;

	clock_t B_Time = clock();
	Tri_Rapid(B,0,B.size()-1);
	B_Time = clock()-B_Time;

	std::cout << "Tri Insertion: " << A_Time << std::endl;
	std::cout << "Tri Rapide: " << B_Time << std::endl;
}
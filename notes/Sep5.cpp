#include <iostream>
#include <array>

using liste = std::array<int,10>;

int pluspetit(liste L){
	int min = L[0];
	
	for(int i=1;i<L.size();i++){ //L.size() iterrations
	
		if ( L[i] < min ) // 1 Comparaison 
			min = L[i];
	
	}
	
	return min;
}

int main (){

	liste nums = {5,3,2,5,23,4,3,22,34,81};
	std::cout << pluspetit(nums)<< std::endl;

	return 0;
}

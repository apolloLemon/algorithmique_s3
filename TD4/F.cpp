#include <array>
#include <vector>
#include <utility>
#include <iostream>

/*a
le minimum dans un ABPPO est a' la racine de l'arbre, 
et c'est le premier du arr RPZ l'ABPPO
*/

//Pre-b
using TAS = std::array<int,100>;
using list = TAS;
struct ABPPO {
	TAS tas;
	int taille;
};

//b O(log2 n)
void srtLM (ABPPO &a, int i){
	//if(i%2!=0) i--; because integer division always rounds down
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

//c O(log2 n)
void SrtABPPO (ABPPO &a, int i){
	int s;
	if(i>a.taille) return;
	if(i*2+1<=a.taille){
		if(a.tas[i] > a.tas[i*2] 
				or a.tas[i] > a.tas[i*2+1])	{
			s = (int)(a.tas[i*2] >= a.tas[i*2+1]);
			std::swap(a.tas[i],a.tas[2*i+s]);
		}
		SrtABPPO(a,2*i+s);
	}
}

int rmMin (ABPPO &a){
	int out = a.tas[1];
	std::swap(a.tas[1],a.tas[a.taille--]);
	SrtABPPO(a,1);
	return out;
}

/********
HEAP SORT
********/

//pre-A


//a O(n log2 n)
void List2Tree (ABPPO &a, std::vector<int> b){
	for(int i=0;i<b.size();i++){
		ajouteLM(a,b[i]); //O(log2 n)
	}
}

//b
//void initList (liste &b){}

//c&d O(n log2 n)
void addtoSortedList (ABPPO &a, std::vector<int> &b){
	int i=0;
	while(a.taille>0){
		int tmp = rmMin(a);
		b.push_back(tmp);
	}
}

int main () {

	std::vector<int> b = {16,14,12,15,123,19,6,2,7,4,4002,3214,7779};
	std::vector<int> v;
	ABPPO a;

	std::cout <<"Unsorted List: ";
	for(int i=0;i<b.size();i++){
		std::cout<<b[i]<<" ";
	} std::cout<<std::endl;

	std::cout<<"                     ///////////\n";
	List2Tree(a,b);
	std::cout<<"                    /HEAP SORT/\n";	
	addtoSortedList(a,v);
	std::cout<<"                   ///////////\n";

	std::cout <<"  Sorted List: ";
	for(int i=0;i<v.size();i++){
		std::cout<<v[i]<<" ";
	} std::cout<<std::endl;

	return 0;
}
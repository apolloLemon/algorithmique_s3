#include <iostream>
#include <array>

const unsigned int SIZE = 10;

struct file {
	std::array<int,SIZE> e;
	int HEAD, TAIL;
};

int i_next (int i);
void init_F (file &a);
bool vide (file a);
bool pleine (file a);
void insertion (file &a, int x);
void affichage (file a);
int consultation (file a);
void suppression (file &a);

int main (){
	file A;
	init_F(A);
	std::cout << "\nA vide "<<vide(A)<<std::endl;
	
	for(int i=1;i<=SIZE+1;i++){
		insertion(A,i);
	}

	std::cout << "\nA pleine "<<pleine(A)<<std::endl;
	affichage(A);
	consultation(A);
	suppression(A);
	consultation(A);

	return 0;
}

int i_next (int i){
	return ++i % SIZE;
}

void init_F (file &a){
	std::cout<<"init_F"<<std::endl;
	a.HEAD = 0;
	a.TAIL = SIZE;
}

bool vide (file a) {
	std::cout<<"vide"<<std::endl;
	return (a.HEAD == i_next(a.TAIL));
}

bool pleine (file a){
	std::cout<<"pleine"<<std::endl;
	//return 0;
	return (a.HEAD == i_next(i_next(a.TAIL)));
}

void insertion (file &a, int x){
	std::cout<<"insertion"<<std::endl;
	if(pleine(a)) {
		std::cout <<"File pleine, erreur insertion"<<std::endl;
		return;
	}
	a.TAIL = i_next(a.TAIL);
	a.e[a.TAIL] = x;
}

int consultation (file a){
	std::cout<<"consultation"<<std::endl;
	if(vide(a)) {
		return 0;
		std::cout <<"File vide, erreur consultation"<<std::endl;
	}
	return a.e[a.HEAD];
}

void suppression (file &a){
	std::cout<<"suppression"<<std::endl;
	a.HEAD = i_next(a.HEAD);
}

void affichage (file a){
	std::cout<<"affichage"<<std::endl;
	int start = a.HEAD;
	do{
		std::cout << a.e[a.HEAD] << " ";
		a.HEAD = i_next(a.HEAD);
	}while(a.HEAD!=start);
	std::cout<<std::endl;
}
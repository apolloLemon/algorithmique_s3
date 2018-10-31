#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <cmath>

const int TAILLE = 100;
using Tab = std::array<float,TAILLE>;

struct PILE {
	Tab val;
	int som;
};

bool PileVide(PILE a);
void Empiler(PILE &a, float x);
float Depiler(PILE &a);

float plus(float a, float b) {return a+b;}
float mult(float a, float b) {return a*b;}
float puis(float a, float b) {return pow(a,b);} //a^b
float racc(float a) {return sqrt(a);}

int main(){
	PILE A;
	A.som=0;
	std::istringstream expression("2 5 + 4 5 3 + 2 ^ x RAC x");

	std::string s;

	while(std::getline(expression, s, ' ')){
		if(s=="+"){
			Empiler(A,plus(Depiler(A),Depiler(A)));
		} else if(s=="*"){
			Empiler(A,mult(Depiler(A),Depiler(A)));
		} else if(s=="^"){
			Empiler(A,puis(Depiler(A),Depiler(A)));
		} else if(s=="RAC"){
			Empiler(A,racc(Depiler(A)));
		} else {
			Empiler(A,std::atof(s.c_str()));
		}
	}

	std::cout<<A.val[0]<<std::endl;
}

bool PileVide(PILE a){
	return (a.som);
}

bool PilePleine(PILE a){
	return (a.som==100);
}

void Empiler(PILE &a, float x){
	//if(!PilePleine(a))
		a.val[a.som++]=x;
}
float Depiler(PILE &a){
	//if(!PileVide(a))
		return a.val[--a.som];
}
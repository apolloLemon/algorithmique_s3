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

void AffichePile(PILE a);

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
		std::cout << "getline " << s << std::endl;
		if(s=="+"){
			Empiler(A,plus(Depiler(A),Depiler(A)));
		} else if(s=="x"){
			Empiler(A,mult(Depiler(A),Depiler(A)));
		} else if(s=="^"){
			Empiler(A,puis(Depiler(A),Depiler(A)));
		} else if(s=="RAC"){
			Empiler(A,racc(Depiler(A)));
		} else {
			Empiler(A,std::atof(s.c_str()));
		}
		AffichePile(A);
	}

}

bool PileVide(PILE a){
	return (a.som);
}

bool PilePleine(PILE a){
	return (a.som==100);
}

void Empiler(PILE &a, float x){
	std::cout << "Empiler "<<x<<std::endl;
	//if(!PilePleine(a))
		a.val[a.som++]=x;
}
float Depiler(PILE &a){
	std::cout << "Depiler "<<a.som<<std::endl;
	//if(!PileVide(a))
		--a.som;
		return a.val[a.som];
}

void AffichePile(PILE a){
	std::cout << "Sommet : " << a.som<<std::endl;
	for(int i=a.som-1;i>=0;i--){
		std::cout<<a.val[i]<<" ";
	}
	std::cout<<std::endl;
}
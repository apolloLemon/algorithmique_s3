#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <cmath>

const int TAILLE = 100;
using Tab = std::array<float,TAILLE>;

struct PILE {
	Tab bob;
	int som;
};

void Empiler(PILE &a, float x);
void Depiler(PILE &a);

float plus(float a, float b) {return a+b}
float mult(float a, float b) {return a*b}
float puis(float a, float b) {return pow(a,b)} //a^b
float racc(float a) {return sqrt(a)}

int main(){
	PILE A;
	std::istringstream expression("2 5 + 4 5 3 + 2 ^ x RAC x");

	std::string s;

	while(std::getline(expression, s, ' ')){
		switch (s){
			case '+':
				Empiler(A,plus(Depiler(A),Depiler(A)));
				break;
			case '*':
				Empiler(A,mult(Depiler(A),Depiler(A)));
				break;
			case '^':
				Empiler(puis(Depiler(A),Depiler(A)));
				break;
			case "RAC":
				Empiler(racc(Depiler(A)));
				break;
			default:
				Empiler(A,std::stof(s));
				break;
		}
	}
}

void Empiler(PILE &a, float x){

}
void Depiler(PILE &a){

}
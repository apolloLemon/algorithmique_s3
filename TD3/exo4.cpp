#include <iostream>
#include <array>

const int SIZE = 4;

using liste = std::array<int,SIZE>;
using matrix = std::array<liste,SIZE>;

matrix adjacance;

using pp = std::array<bool,SIZE>;
struct walker {
	liste distance;
	//int position;
	pp visites;
};

void parcours_Proffondeur(const matrix &adj, int s, walker &r){
	//if(r.visites[s]) return;
	r.visites[s] = true;
	//r.position = s;
	//std::cout << "boby est en "<<s<<std::endl;

	for(int i=0;i<SIZE;i++){
		//if(s==i) continue;

		if(adj[s][i]!=0 and !r.visites[i]){
			r.distance[i]=r.distance[s]+adj[s][i];
			std::cout << "De "<<s<<" a' "<<i<<" : "<<adj[s][i]<<" dist (Total Distance from source: "<<r.distance[i]<<")\n";
			parcours_Proffondeur(adj,i,r);
		}
	}
}

int main () {

	matrix adjehGaleh;
	adjehGaleh[0] = {0,3,0,2};
	adjehGaleh[1] = {0,0,2,1};
	adjehGaleh[2] = {6,0,0,0};
	adjehGaleh[3] = {0,0,2,0};
	walker boby;

	parcours_Proffondeur(adjehGaleh, 3, boby);

	//std::cout << boby.distance<< std::endl;

	return 0;
}
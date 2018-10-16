const int BUFF = 100;
using liste = std::array<int,BUFF>;

struct Pile {
	liste LMents;
	int sommet;
}

Pile CreatePile ();
int Top(Pile p);
void DePile(Pile &p);
void AddPile(Pile &p,int e);
bool emptyPile (Pile p);

int main () {
	Pile P1, P2, P3;

	while(!emptyPile(P1)){
		AddPile(P3,Top(P1));
		DePile(P1);
	}
	while(!emptyPile(P3)){
		int a = Top(P3)
		AddPile(P1,a);
		if(a%2==0) AddPile(P2,a);
		DePile(P3);
	}
}
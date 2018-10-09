const int BUFF = 100;
using liste = std::array<int,BUFF>;

struct Pile {
	liste LMents;
	int sommet;
}

Pile CreatePile ();
int Top(Pile p);
void DePile(Pile &p);
void Pile(Pile &p,int e);
bool emptyPile (Pile p);
//1
const unsigned int SIZE = 20;
struct file {
	std::array<char,SIZE> e;
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

//2
struct knot {
	std::string str;
	knot * g;
	knot * d;
	knot * p;
	
	file liv;

};
using AB = knot *;

//3
void initArbre (AB &a){
	a=nullptr;
	a->p = nullptr;
	init_F(a->liv);
}

//older STUFF
void addKnot_to (AB &a, std::string etiq, AB parent){
	a = new knot;
	a->str = etiq;
	a->g=a->d=nullptr;
	a->p = parent;
	//std::cout << a << std::endl;
}

void addKnot (AB &a, char s, std::string etiq){
	if(s=='G'){
		addKnot_to(a->g, etiq);
	} else 
	if(s=='D'){
		addKnot_to(a->d, etiq);	
	}
}

//3
bool estRacine (AB a) {
	return (a) && (!a->p);
}

//4
bool estFilsgauche (AB a){
	return a == a->p->g;
}

//5
bool estFilsdroit (AB a){
	return a == a->p->d;
}

////EXO1
//4
bool est_feuille (AB a) {
	return (!a->g) and (!a->d);
}

//5
bool est_interne (AB a) {
	return !est_feuille(a);
}

//6
AB addressOf (AB a, std::string etiq) {
	if(a==nullptr) return NULL;
	if(a->str == etiq) return a;
	AB g = addressOf(a->g, etiq);
	AB d = addressOf(a->g, etiq);
	if(g) return g;
	else return d;
}

//7
void afficheNoeud (AB a) {
	std::cout << a->str <<std::endl;
}


void affiche_prefixe (AB a) {
	if(!a) return;
	afficheNoeud(a);
	//std::cout<<a->g<<std::endl;
	affiche_prefixe(a->g);
	//std::cout<<a->d<<std::endl;
	affiche_prefixe(a->d);
}
///OLDERSTUFF



//4
void Commande (AB &a, std::string etq) {
	AB tmp = addressOF(a, etq);
	char tmpC;
	while(tmp){
		if(tmp=tmp->p->g) tmpC = 'G';
		else if(tmp=tmp->p->d) TmpC = 'D';
		insertion(tmp->liv, tmpC);
		tmp = tmp->p;
	}
}

//5





//FILE FUNCTIONS
int i_next (int i){
	return ++i % SIZE;
}

void init_F (file &a){
	std::cout<<"init_F"<<std::endl;
	a.HEAD = 0;
	a.TAIL = SIZE-1;
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

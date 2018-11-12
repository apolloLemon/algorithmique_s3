bool tour = false; //AI
tour = true; //Joueur


const  int cAllumettes = 8;
int allumettes = cAllumettes;


int Jouer(int n);
void jeu(int n,bool j);

int main (){}

void jeu(int n, bool j){
	cout<<"Il y a"<<n<<"allumettes, c'est au tour de "<<(tour ? "Joueur" : "IA";)<<endl;
	if(j) n = Jouer(n);
	if(n%4==0) n -= Rand()%3;
}



///Correction

void jeu(bool J, int N){
	if(N==0 or N<0){
		if(J) cout <<"IA win";
		else cout << "player win";
	}
	else {
		cout << "Il reste "<<N<<"allumettes\n";
		if(J) jeu(!J,N-jouer(N));
		else{
			if(N%4=0){
				a = Rand()%3+1;
				cout <<"IA rm"<<a<<"matches";
				jeu(!J,N-a);
			} else {
				cout << "IA rm"<<N%4<<"matches";
				jeu(!J,N-(N%4));
			}
		}
	}
}
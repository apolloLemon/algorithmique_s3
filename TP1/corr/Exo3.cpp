/* Cours de structure de donn�es et algorithmes.
 * TP 1 : Complexit� algorithmique. Algorithmes de tris.
 * Le but de ce tp est de comparer en pratique l'efficacit� des algorithmes de tris,
 * sur des donn�es g�n�r�es al�atoirement. */

#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>

const int GrandeTaille = 100000;  // Nombre max. d'�l�ments � trier

using namespace std;
using Tab = array <int,GrandeTaille>;

/* Proc�dure de tri par insertion.
 * Complexit� temporelle dans le pire cas : O(n^2).
 * Complexit� temporelle en moyenne : O(n^2).*/
void TriInsertion(Tab &T, int TailleT)
{
	int i, k, x;
	for (i = 1; i < TailleT; i++)
    {
		x = T[i];
		k = i - 1;
		while (k >= 0 && T[k] > x)
      {
			T[k + 1] = T[k];
			k--;
      }
		T[k + 1] = x;
    }
}

//Proc�dure d'�change de deux �l�ments du tableau, d'indices i et j.
void Echange(Tab &T, int i, int j)
{
	int k = T[i];
	T[i] = T[j];
	T[j] = k;
}

/* Proc�dure de tri � bulles.
 * Complexit� temporelle dans le pire cas : O(n^2).
 * Complexit� temporelle en moyenne : O(n^2).*/
void TriBulles(Tab &T, int TailleT)
{
	int i, j;
	for (i = 0; i <= TailleT - 2; i++)
		for (j = TailleT - 1; j >= i + 1; j--)
			if (T[j] < T[j - 1]) Echange(T, j, j - 1);
}

/* Fonction partage pour le tri rapide.
 * Le pivot est l'�l�ment d'indice g au d�but de la fonction.
 * La position finale du pivot est retourn�e.*/
int Partage(Tab &T, int TailleT, int g, int d)
{
	int l = g + 1, r = d;
	int p = T[g];
	while (l <= r)
    {
		while (T[r] > p) r--;
		while (l < TailleT and T[l] <= p) l++;
		if (l < r)
      {
			Echange(T, l, r);
			l++;
			r--;
      }
    }
	Echange(T, g, r);
	return r;
}

/* Proc�dure de tri rapide.
 * Complexit� temporelle dans le pire cas : O(n^2).
 * Complexit� temporelle en moyenne : O(n log n).*/
void TriRapide(Tab &T, int TailleT, int g, int d)
{
	int pp;
	if (g < d)
    {
		pp = Partage(T, TailleT, g, d);
		TriRapide(T, TailleT, g, pp - 1);
		TriRapide(T, TailleT, pp + 1, d);
    }
}

void InitTab(Tab &T)
{  for(int i=0;i<GrandeTaille;i++) T[i] = rand();  }

int main()
{
  Tab TRef; // Tableau qui servira de "r�f�rence" (pour effectuer les tris sur les MEMES tab.)
  Tab T;    // Tab. dans lequel le tri est effectu�, apr�s copie du tableau de r�f�rence.
	clock_t Begin_Time; // Pour calculer les temps d'ex�cution des tris
	int i,j;
  srand(time(NULL));  // Pour initialiser le g�n�rateur de nombres al�atoires
  InitTab(TRef);  	// Initialisation de TRef., chaque �l�ment recevant une valeur enti�re al�atoire entre 0 & RAND_MAX
  cout << "------------------------------------------------------\n";
  cout << "Comparaison des temps d'execution des 3 tris (en sec.)\n";
  cout << "sur des tableaux de tailles 100, 1000, 10000 & 100000\n";
  cout << "------------------------------------------------------\n";
	cout << "\nTri par insertion\n";
	for(i=100;i<=GrandeTaille;i*=10)
  {
    for(j=0;j<i;j++) T[j]=TRef[j];  // Copie des i 1iers �l�ments de TRef dans T
    cout << i << " entiers : ";
		Begin_Time = clock();
    TriInsertion(T,i);
    cout << (float)(clock()-Begin_Time)/CLOCKS_PER_SEC << endl;
  }
  cout << "\n------------";
	cout << "\nTri a bulles\n";
	for(i=100;i<=GrandeTaille;i*=10)
  {
    for(j=0;j<i;j++) T[j]=TRef[j];  // Copie des i 1iers �l�ments de TRef dans T
    cout << i << " entiers : ";
		Begin_Time = clock();
    TriBulles(T,i);
    cout << (float)(clock()-Begin_Time)/CLOCKS_PER_SEC << endl;
  }
  cout << "\n----------";
	cout << "\nTri rapide\n";
	for(i=100;i<=GrandeTaille;i*=10)
  {
    for(j=0;j<i;j++) T[j]=TRef[j];  // Copie des i 1iers �l�ments de TRef dans T
    cout << i << " entiers : ";
		Begin_Time = clock();
    TriRapide(T,i,0,i-1);
    cout << (float)(clock()-Begin_Time)/CLOCKS_PER_SEC << endl;
  }
  // La valeur 0 est retourn�e au syst�me d'exploitation, indiquant que le programme s'est ex�cut� correctement.
  return 0;
}

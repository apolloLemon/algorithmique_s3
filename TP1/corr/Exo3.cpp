/* Cours de structure de données et algorithmes.
 * TP 1 : Complexité algorithmique. Algorithmes de tris.
 * Le but de ce tp est de comparer en pratique l'efficacité des algorithmes de tris,
 * sur des données générées aléatoirement. */

#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>

const int GrandeTaille = 100000;  // Nombre max. d'éléments à trier

using namespace std;
using Tab = array <int,GrandeTaille>;

/* Procédure de tri par insertion.
 * Complexité temporelle dans le pire cas : O(n^2).
 * Complexité temporelle en moyenne : O(n^2).*/
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

//Procédure d'échange de deux éléments du tableau, d'indices i et j.
void Echange(Tab &T, int i, int j)
{
	int k = T[i];
	T[i] = T[j];
	T[j] = k;
}

/* Procédure de tri à bulles.
 * Complexité temporelle dans le pire cas : O(n^2).
 * Complexité temporelle en moyenne : O(n^2).*/
void TriBulles(Tab &T, int TailleT)
{
	int i, j;
	for (i = 0; i <= TailleT - 2; i++)
		for (j = TailleT - 1; j >= i + 1; j--)
			if (T[j] < T[j - 1]) Echange(T, j, j - 1);
}

/* Fonction partage pour le tri rapide.
 * Le pivot est l'élément d'indice g au début de la fonction.
 * La position finale du pivot est retournée.*/
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

/* Procédure de tri rapide.
 * Complexité temporelle dans le pire cas : O(n^2).
 * Complexité temporelle en moyenne : O(n log n).*/
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
  Tab TRef; // Tableau qui servira de "référence" (pour effectuer les tris sur les MEMES tab.)
  Tab T;    // Tab. dans lequel le tri est effectué, après copie du tableau de référence.
	clock_t Begin_Time; // Pour calculer les temps d'exécution des tris
	int i,j;
  srand(time(NULL));  // Pour initialiser le générateur de nombres aléatoires
  InitTab(TRef);  	// Initialisation de TRef., chaque élément recevant une valeur entière aléatoire entre 0 & RAND_MAX
  cout << "------------------------------------------------------\n";
  cout << "Comparaison des temps d'execution des 3 tris (en sec.)\n";
  cout << "sur des tableaux de tailles 100, 1000, 10000 & 100000\n";
  cout << "------------------------------------------------------\n";
	cout << "\nTri par insertion\n";
	for(i=100;i<=GrandeTaille;i*=10)
  {
    for(j=0;j<i;j++) T[j]=TRef[j];  // Copie des i 1iers éléments de TRef dans T
    cout << i << " entiers : ";
		Begin_Time = clock();
    TriInsertion(T,i);
    cout << (float)(clock()-Begin_Time)/CLOCKS_PER_SEC << endl;
  }
  cout << "\n------------";
	cout << "\nTri a bulles\n";
	for(i=100;i<=GrandeTaille;i*=10)
  {
    for(j=0;j<i;j++) T[j]=TRef[j];  // Copie des i 1iers éléments de TRef dans T
    cout << i << " entiers : ";
		Begin_Time = clock();
    TriBulles(T,i);
    cout << (float)(clock()-Begin_Time)/CLOCKS_PER_SEC << endl;
  }
  cout << "\n----------";
	cout << "\nTri rapide\n";
	for(i=100;i<=GrandeTaille;i*=10)
  {
    for(j=0;j<i;j++) T[j]=TRef[j];  // Copie des i 1iers éléments de TRef dans T
    cout << i << " entiers : ";
		Begin_Time = clock();
    TriRapide(T,i,0,i-1);
    cout << (float)(clock()-Begin_Time)/CLOCKS_PER_SEC << endl;
  }
  // La valeur 0 est retournée au système d'exploitation, indiquant que le programme s'est exécuté correctement.
  return 0;
}

/* Cours de structure de données et algorithmes.
 * TP 1 : Complexité algorithmique. Algorithmes de tris.
 * Le but de ce tp est de comparer en pratique l'efficacité des algorithmes de tris,
 * sur des données générées aléatoirement. */

#include <iostream>
#include <cstdlib>  // rand
#include <array>
#include <ctime>  // srand

const int TailleTab = 5;  // Nombre d'éléments à trier

using namespace std;
using Tab = array <int,TailleTab>;

/* Procédure de tri par insertion.
 * Complexité temporelle dans le pire cas : O(n^2).
 * Complexité temporelle en moyenne : O(n^2).*/
void TriInsertion(Tab &T) // Exo. 1, quest. c
{
	int i, k, x;
	for (i = 1; i < TailleTab; i++)
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

void InitTab(Tab &T)
{  for(int i=0;i<TailleTab;i++) T[i] = rand();  }

void AffTab(Tab T, string msg)
{
  cout << msg << endl;
  for(int i=0; i<TailleTab;i++) cout << "T[" << i+1 << "] = " << T[i] << endl;
}

/* Fonction partage pour le tri rapide.
 * Le pivot est l'élément d'indice g au début de la fonction.
 * La position finale du pivot est retournée.*/
int Partage(Tab &T, int g, int d)
{
	int l = g + 1, r = d;
	int p = T[g];
	while (l <= r)
    {
		while (T[r] > p) r--;
		while (l < TailleTab and T[l] <= p) l++;
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
void TriRapide(Tab &T, int g, int d)
{
	int pp;
	if (g < d)
    {
		pp = Partage(T, g, d);
		TriRapide(T, g, pp - 1);
		TriRapide(T, pp + 1, d);
    }
}

int main()  // Teste les 2 tris (avec affichage) sur des "petits" tableaux
{
  Tab T;   // Tableau à initialiser, trier & afficher
  cout << "---------------------------------\n";
  cout << "Teste les 2 tris (avec affichage)\n";
  cout << "---------------------------------\n";
  srand(time(NULL));  // Pour initialiser le générateur de nombres aléatoires
  InitTab(T);
  AffTab(T, "\nAvant tri par insertion");
  TriInsertion(T);
  AffTab(T, "\nApres tri par insertion");
  InitTab(T); // Ré-initialise T avec de nouveaux nombres aléatoires
  AffTab(T, "\n-------------------------\nAvant tri rapide");
  TriRapide(T,0,TailleTab-1);
  AffTab(T, "\nApres tri rapide");
  // La valeur 0 est retournée au système d'exploitation, indiquant que le programme s'est exécuté correctement.
  return 0;
}

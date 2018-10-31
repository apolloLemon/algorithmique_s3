/* Cours de structure de donn�es et algorithmes.
 * TP 1 : Complexit� algorithmique. Algorithmes de tris.
 * Le but de ce tp est de comparer en pratique l'efficacit� des algorithmes de tris,
 * sur des donn�es g�n�r�es al�atoirement. */

#include <iostream>
#include <cstdlib>  // rand
#include <array>
#include <ctime>  // srand

const int TailleTab = 5;  // Nombre d'�l�ments � trier

using namespace std;
using Tab = array <int,TailleTab>;

/* Proc�dure de tri par insertion.
 * Complexit� temporelle dans le pire cas : O(n^2).
 * Complexit� temporelle en moyenne : O(n^2).*/
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

//Proc�dure d'�change de deux �l�ments du tableau, d'indices i et j.
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
 * Le pivot est l'�l�ment d'indice g au d�but de la fonction.
 * La position finale du pivot est retourn�e.*/
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

/* Proc�dure de tri rapide.
 * Complexit� temporelle dans le pire cas : O(n^2).
 * Complexit� temporelle en moyenne : O(n log n).*/
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
  Tab T;   // Tableau � initialiser, trier & afficher
  cout << "---------------------------------\n";
  cout << "Teste les 2 tris (avec affichage)\n";
  cout << "---------------------------------\n";
  srand(time(NULL));  // Pour initialiser le g�n�rateur de nombres al�atoires
  InitTab(T);
  AffTab(T, "\nAvant tri par insertion");
  TriInsertion(T);
  AffTab(T, "\nApres tri par insertion");
  InitTab(T); // R�-initialise T avec de nouveaux nombres al�atoires
  AffTab(T, "\n-------------------------\nAvant tri rapide");
  TriRapide(T,0,TailleTab-1);
  AffTab(T, "\nApres tri rapide");
  // La valeur 0 est retourn�e au syst�me d'exploitation, indiquant que le programme s'est ex�cut� correctement.
  return 0;
}

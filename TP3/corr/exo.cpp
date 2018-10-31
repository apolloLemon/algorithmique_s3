#include <iostream>
#include <array>

const int TAILLE_MAX = 6;
using Tableau = std::array<int, TAILLE_MAX>;

struct File
{
	Tableau tab;
	int tete, queue;
};

File init_file()
{
	File nouvelle_file;
	nouvelle_file.tete       = 0; nouvelle_file.queue      = TAILLE_MAX-1;
	return nouvelle_file;
}

int succ(int pos)  {	return (pos + 1) % TAILLE_MAX;}

bool vide(File file) {	return succ(file.queue) == file.tete;}

bool pleine(File file) { return succ(succ(file.queue)) == file.tete; }

void ajouter(File &file, int elt)
{
	if(not pleine(file))
    { file.queue = succ(file.queue); file.tab[file.queue] = elt; }
}

int consultation(File file)
{
	if(not vide(file)) return file.tab[file.tete];
  return -1;
}

int supprimer(File &file)
{
	int val = consultation(file);
	if(not vide(file)) file.tete = succ(file.tete);
	return val;
}

void afficher(File file)
{
	if(vide(file)) std::cout << "vide   ";
	else  if(pleine(file)) std::cout << "pleine ";
        else std::cout << "non    ";
	std::cout << " : [";
	for(int i = file.tete; i != succ(file.queue); i = succ(i)) std::cout << file.tab[i] << " ";
	std::cout << "]" << std::endl;
}

int main()
{
	File f = init_file();
	afficher(f);
	ajouter(f, 1);	afficher(f);
	ajouter(f, 2);	afficher(f);
	ajouter(f, 3);	afficher(f);
	ajouter(f, 4);	afficher(f);
	ajouter(f, 5);	afficher(f);
	ajouter(f, 6);	afficher(f);
	supprimer(f);	afficher(f);
	ajouter(f, 6);	afficher(f);
	supprimer(f);	afficher(f);
	supprimer(f);	afficher(f);
	supprimer(f);	afficher(f);
	supprimer(f);	afficher(f);
	supprimer(f);	afficher(f);
	return 0;
}
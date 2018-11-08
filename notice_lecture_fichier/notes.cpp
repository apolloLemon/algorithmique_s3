#include <iostream>
#include <fstream>
#include <string>

void lecture_notes(std::string nom_fichier) {
	std::ifstream fichier(nom_fichier); // On tente d'ouvrir le fichier

	if(fichier) { // Si le fichier est ouvert, on traite les données.
		double somme_notes=0;
		int nombre_etudiants;

		double note;
		std::string nom;

		// La première donnée est le nombre d'étudiants
		fichier >> nombre_etudiants;

		// L'affichage des réels se fera à deux décimales près
		std::cout.precision(2);
		std::cout << std::fixed;

		for(int i=0; i<nombre_etudiants; ++i) {
			// Ensuite chaque ligne est formée du nom puis de la note
			fichier >> nom;
			fichier >> note;

			// On additionne les notes :
			somme_notes = somme_notes + note;

			// On affiche la note de la personne lue :
			std::cout << nom << " a la note de " << note << std::endl;
		}

		// On affiche la moyenne
		std::cout << "La moyenne est de "
			<< somme_notes/nombre_etudiants << std::endl;
	} else { // ... sinon on affiche une erreur.
		std::cout << "Erreur : Impossible d'ouvrir le fichier "
			<< nom_fichier << "." << std::endl;
	}
}

int main() {
	lecture_notes("notes.txt");

	return 0;
}

#include "Unit1.h"

using namespace std;

void Lecture_fichier(std::string ad_file, T_Probleme &p) {

	ifstream fichier(ad_file, ios::in);  // on ouvre le fichier en lecture

	if (fichier)  // si l'ouverture a réussi
	{
		std::string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
		getline(fichier, contenu);  // on met dans "contenu" la ligne

		stringstream ss(contenu);

		ss >> p.nb_sommet;

		cout << "Nombre de Sommets: " << p.nb_sommet << endl;

		cout << endl << "Affichage du fichier lu" << endl;

		float c;
		int compteur, j;

		for (int i = 1; i <= p.nb_sommet; i++)
		{
			// Lecture ligne par ligne
			getline(fichier, contenu);
			cout << contenu << endl;

			// Lecture caractère par caractère
			compteur = 0;
			j = 0;

			stringstream ss2(contenu);

			while (ss2 >> c)
			{
				// cout << c << endl;
				switch (compteur) {
				case 0:
					j = int(c);
					break;
				case 1:
					p.X[j] = c;
					break;
				case 2:
					p.Y[j] = c;
					break;
				}
				compteur++;
			}
		}

		cout << "Reussi" << endl;

		fichier.close();  // on ferme le fichier
	}
	else  // sinon
	{
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
}

void Affichage_Probleme(T_Probleme &p) {
	int i;
	for (i = 1; i <= p.nb_sommet; i++) {
		cout << "X[i]=" << p.X[i] << " Y[i]=" << p.Y[i] << endl;
	}
}

void Pre_Calcul(T_Probleme &p) {
	int i, j;
	for (i = 1; i <= p.nb_sommet; i++) {
		for (j = 1; j <= p.nb_sommet; j++) {
			p.matrice_dist[i][j] = sqrt(pow(p.X[i] - p.X[j], 2) + pow(p.Y[i] - p.Y[j], 2));
		}
	}
}

void Affichage_Matrice(T_Probleme &p) {
	cout << "Affichage Matrice" << endl;
	int i, j;
	for (i = 1; i <= p.nb_sommet; i++) {
		for (j = 1; j <= p.nb_sommet; j++) {
			cout << p.matrice_dist[i][j] << " ";
		}
		cout << endl;
	}
}

void Generer_Sol_Aleatoire(T_Probleme &p, T_Sol &s) {
	int i;
	int tab[nb_sommets_max] = { 0 };
	
	s.LISTE[0] = 999;

	srand(time(NULL));

	for (i = 1; i <= p.nb_sommet; i++)
	{
		do
		{
			s.LISTE[i] = (int)(rand() % p.nb_sommet) + 1;
		} while (tab[s.LISTE[i]] >= 1);

		tab[s.LISTE[i]]++;

	}
	/*
	int i = 1;
	for (i = 1; i <= p.nb_sommet; i++) {
		s.LISTE[i] = i;
	}
	*/
};

void Calculer_Cout(T_Probleme &p, T_Sol &s) {
	int i = 1;
	int compteur = 1;
	float mon_cout = 0;
	while (i <= p.nb_sommet) {
		mon_cout += p.matrice_dist[s.LISTE[i]][s.LISTE[i + 1]];
		compteur++;
		i++;
	}
	cout << "Le Cout: " << mon_cout << endl;
	mon_cout += p.matrice_dist[s.LISTE[i]][s.LISTE[1]];
	cout << "Le Cout: " << mon_cout << endl;
}
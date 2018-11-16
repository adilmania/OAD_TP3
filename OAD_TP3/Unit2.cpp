#include "stdafx.h"
#include "Unit2.h"

// Fonction Plus Proche Voisin
void Plus_Proche_Voisin(T_Probleme &p, T_Sol &s, int SI) {
	int E[nb_sommets_max] = { 0 };
	int min;
	int j_min;
	int j;
	int i;

	s.LISTE[0] = 999;
	s.LISTE[1] = SI;

	// Remplir E
	for (i = 1; i <= p.nb_sommet; i++) {
		E[i] = i;
	}

	E[SI] = 0;

	for (i = 1; i <= p.nb_sommet; i++) {

		E[i] = 0;
		min = c_inf;

		for (j = 1; j <= p.nb_sommet; j++) {

			if (j != i && E[j] != 0 && p.matrice_dist[i][j] < min)
			{
				min = p.matrice_dist[i][j];
				j_min = j;
			}

		}

		E[j_min] = 0;
		s.LISTE[i + 1] = j_min;

	}

	Calculer_Cout(p, s);

}

// Fonction Plus Proche Voisin Randomisee
void Plus_Proche_Voisin_Randomisee(T_Probleme &p, T_Sol &s, int SI) {
	int E[nb_sommets_max] = { 0 };
	int SOM_PRO[6] = { 0 };
	int min;
	int j_min;
	int j;
	int i;

	s.LISTE[0] = 999;
	s.LISTE[1] = SI;

	// Remplir E
	for (i = 1; i <= p.nb_sommet; i++) {
		E[i] = i;
	}

	E[SI] = 0;

	for (i = 1; i <= p.nb_sommet; i++) {

		E[i] = 0;
		min = c_inf;

		// On met les 5 premiers sommets dans l'ordre
		// Si moins de 5 on s'arrête
		// Si le nouveau sommet #6 est meilleur que le pire
			// On l'Ajoute et on retrie

		for (j = 1; j <= p.nb_sommet; j++) {

			if (j != i && E[j] != 0 && p.matrice_dist[i][j] < min)
			{
				min = p.matrice_dist[i][j];
				j_min = j;
			}

		}

		E[j_min] = 0;
		s.LISTE[i + 1] = j_min;

	}

	Calculer_Cout(p, s);

}
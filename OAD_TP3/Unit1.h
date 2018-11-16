#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <time.h>

const int nb_sommets_max = 300;
const int c_inf = 9999;

typedef struct T_Probleme {
	int nb_sommet;
	float matrice_dist[nb_sommets_max][nb_sommets_max];
	float X[nb_sommets_max];
	float Y[nb_sommets_max];
}T_Probleme;

typedef struct T_Sol {
	float cout;
	int LISTE[nb_sommets_max] = { 0 };
}T_Sol;

// Fonction Fichier & PreCalcul

void Lecture_fichier(std::string ad_file, T_Probleme &p);
void Affichage_Probleme(T_Probleme &p);
void Pre_Calcul(T_Probleme &p);
void Affichage_Matrice(T_Probleme &p);

// Fonction Gerer une solution

void Generer_Sol_Aleatoire(T_Probleme &p, T_Sol &s);
void Calculer_Cout(T_Probleme &p, T_Sol &s);


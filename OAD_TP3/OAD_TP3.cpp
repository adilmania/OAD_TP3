// OAD_TP3.cpp : main project file.

#include "Unit2.h"

using namespace System;

int main(array<System::String ^> ^args)
{

	Console::WriteLine(L"Hello World");

	std::string ad_file = "A280.txt";

	T_Probleme un_probleme;
	T_Sol une_solution;

	Lecture_fichier(ad_file, un_probleme);

	// Affichage_Probleme(un_probleme);

	Pre_Calcul(un_probleme);

	Generer_Sol_Aleatoire(un_probleme, une_solution);

	Calculer_Cout(un_probleme, une_solution);

	Plus_Proche_Voisin(un_probleme, une_solution, 8);

	// Affichage_Matrice(un_probleme);
    return 0;

}

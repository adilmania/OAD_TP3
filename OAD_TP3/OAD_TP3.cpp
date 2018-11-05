// OAD_TP3.cpp : main project file.

#include "Unit1.h"

using namespace System;

int main(array<System::String ^> ^args)
{

	Console::WriteLine(L"Hello World");

	std::string ad_file = "A280.txt";

	T_Probleme un_probleme;
	T_Sol une_solution;

	Lecture_fichier(ad_file, un_probleme);

	Affichage_Probleme(un_probleme);

	Console::WriteLine(L"Hello World");

	Pre_Calcul(un_probleme);

	Generer_Sol_Aleatoire(un_probleme, une_solution);
	Generer_Sol_Aleatoire(un_probleme, une_solution);
	Generer_Sol_Aleatoire(un_probleme, une_solution);
	Generer_Sol_Aleatoire(un_probleme, une_solution);
	Generer_Sol_Aleatoire(un_probleme, une_solution);
	Generer_Sol_Aleatoire(un_probleme, une_solution);
	Generer_Sol_Aleatoire(un_probleme, une_solution);
	Generer_Sol_Aleatoire(un_probleme, une_solution);
	Generer_Sol_Aleatoire(un_probleme, une_solution);

	Calculer_Cout(un_probleme, une_solution);
	// Affichage_Matrice(un_probleme);
    return 0;

}

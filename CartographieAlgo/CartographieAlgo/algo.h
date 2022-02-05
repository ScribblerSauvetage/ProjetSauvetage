#include "utils.h"

/**************************
// Algo Valentin
**************************/
void algo_v1(Robot *robot, int grille[Taille_grille][Taille_grille], int veriteTerrain[Taille_grille][Taille_grille]);
void rechercheCaseSuivante(Robot *robot, int grille[Taille_grille][Taille_grille]);

/**************************
// Fonction Utilitaire
**************************/
void showGrille(int grille[Taille_grille][Taille_grille], Robot robot);
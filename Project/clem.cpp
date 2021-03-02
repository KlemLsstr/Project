#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int i, j; /* Variable pour les boucles & recherches dans les tableaux */
int col; /* Variable colonne */
int lig; /* Variable Ligne */
char tabbat[10][10]; /* Table de la solution avec les bateaux */
char grille[10][10]; /* Table de jeux */
char let; /* Variable pour afficher Coordonne en Lettre */
char tablet[9][2]; /* Tableau comparatif Lettre & chiffre */
time_t t; /* Variable pour générateur de nombre aléatoire */


/**MENU**/
void menu()
{
    cout << "     Bataille Navale\n";
    cout << "----------------------------\n";
    cout << "1 : Placer les bateaux \n";
    cout << "2 : Afficher solution\n";
    cout << "3 : Jouer\n";
    cout << "4 : Sauvegarder la partie\n";
    cout << "5 : Charger la partie\n";
    cout << "0 : Quitter\n";
}

/**Placement des bateaux**/
void Placer()
{
    int loc1; /* Location N°1 pour les coordonnees d'un bateau*/
        int loc2; // Location N°2 pour les coordonnees d'un bateau/
        int value; // variable indiquant le nombre de bateau pour 1 / 6 /
        srand((unsigned)time(&t)); // Mise en place du Generateur de nombre aléatoire /
        cout << "Entrez la taille de la grille de jeux (un carre)?\n"; // nb de lignes du tableau /
        cin >> lig;
    col = lig;


    if (lig < 2 || lig>9) // test pour les nombres minimum & maximum de lignes * /
    {
        while (lig < 2 || lig>9)
        {
            cout << "Taille incorrecte.\n";
            cout << "Ressaisir la taille ( >=2 <=9 ).\n";
            cin >> lig;
            col = lig;
        }
    }
    for (i = 1; i <= lig; i++) // Creation de la grille de point des bateaux /
    {
        for (j = 1; j <= col; j++)
        {
            tabbat[i][j] = '.';
        }
    }
    
    for (i = 1; i <= lig; i++) // Creation de la grille de point du jeux /
    {
        for (j = 1; j <= col; j++)
        {
            grille[i][j] = '.';
        }
    }
    cout << "Fin de creation de la grille.\n";

    value = col / 6; // Géneration des bateaux pour 1 / 6 des grilles /

        if (value < 2) // Si la valeur trouve pour 1 / 6 est < 2 alors je met 2 bateau /
        {
            value = 2;
        }
    if (value > 9) // Si la valeur trouve pour 1 / 6 est > 9 alors je met 10 bateau /
    {
        value = 10;
    }
    // Géneration des  coordonnées des bateaux /
        for (i = 1; i <= value; i++)
        {
            loc1 = (rand() % lig) + 1;
            loc2 = (rand() % col) + 1;

            while (tabbat[loc1][loc2] == 'X') // Vérification de risque de doublon * /
            {
                loc1 = (rand() % lig) + 1;
                loc2 = (rand() % col) + 1;
            }
            tabbat[loc1][loc2] = 'X';
        }
    cout << "Fin de creation des bateaux.\n";
    system("PAUSE");
}
/**Affichage de la solution (ou sont les bateaux?)**/
void Afficher()
{
    cout << "SOLUTION:\n"" "; // Afficher la solution /
        for (i = 1; i <= lig; i++) // 1er boucle pour afficher les coordonne en lettre /
        {
            let = 'A' + i - 1;
            cout << "   " << let;
        }

    for (i = 1; i <= lig; i++) // 2eme boucle pour afficher la table solution avec les bateaux * /
    {
        cout << "\n" << i;

        for (j = 1; j <= col; j++)
        {
            cout << "   " << tabbat[i][j];
        }
        cout << "\n";
    }
    system("PAUSE");
}
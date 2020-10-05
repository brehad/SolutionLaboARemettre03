//But: Demander à l'utilisateur de deviner un nombre aléatoire. Il a 5 chances. Lui dire s'il a réussi ou le nombre de chances qu'il lui reste.
//Auteur: Hadrien Breton
//Date: 2020-10-04

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");																													//Permet d'afficher les accents correctement dans la console

	int iRandom;																															// permet de mémoriser le nombre choisi aléatoirement par l’ordinateur
	int nb;																																	//Nombre choisi par l'utilisateur quand il essaie de deviner


	srand(time(0));																															// pour activer l’aléatoire dans le programme
	iRandom = rand() % 101;																													// l’ordinateur calcule un nombre aléatoire entre 0 et 100 et le stocke dans iRandom

	for (int chances = 5; chances > 0; chances--)																							//La variable "chances" est initialisé avec la valeur 5 (5 chances). À la fin de chaque occurence de la boucle, la variable "chances" diminue de 1. Quand elle arrive à 0, la boucle s'arrête.
	{
		cout << "Vous devez tenter de deviner un nombre entier aléatoire compris entre 0 et 100.\n";										//Explique le jeu à l'utilisateur
		cout << "Il vous reste " << chances << " chances.\n";																				//Affiche le nombre de chances restantes à l'utilisateur
		cout << "Veuillez entrer un nombre entre 0 et 100: \n";																				//Demande à l'utilisateur d'entrer un nombre
		cin >> nb;																															//Enregistre le nombre entré dans la variable nb

		if (nb >= 0 && nb <= 100)																											//Sert à vérifier si le nombre entré par l'utilisateur est bien entre 0 et 100.
		{
			if (nb == iRandom)																												//Sert à détecter si l'utilisateur à réussi.
			{
				cout << "\nVous avez réussi! Le nombre mystère était bien " << iRandom << ".\n";											//Annonce à l'utilisateur qu'il à réussi et confirme la valeur de iRandom
				break;																														//Brise la boucle pour arrêter le programme
			}
			else																															//Cette section est exécutée si l'utilisateur n'a pas la bonne réponse.
			{
				if (nb > iRandom)																											//Cette section est exécutée si le nombre de l'utilisateur est plus grand que iRandom
				{
					cout << "Vous vous êtes trompé!\nLe nombre mystère est plus petit que le nombre " << nb << ".\nVeuillez réessayer.\n";	//Annonce au joueur qu'il c'est trompé et que iRandom est plus petit que son nombre.
					system("pause");																										//Demande au joueur d'appuyer sur un bouton pour continuer, pour lui laisser le temps de lire le message précédent.
				}
				else if (nb < iRandom)																										//Cette section est exécutée si le nombre de l'utilisateur est plus petit que iRandom
				{
					cout << "Vous vous êtes trompé!\nLe nombre mystère est plus grand que le nombre " << nb << ".\nVeuillez réessayer.\n";	//Annonce au joueur qu'il c'est trompé et que iRandom est plus grand que son nombre.
					system("pause");																										//Demande au joueur d'appuyer sur un bouton pour continuer, pour lui laisser le temps de lire le message précédent.
				}
			}
		}
		else																																//Cette section est exécutée seulement si nb est plus petit que 0 ou plus grand que 100
		{
			cout << "Erreur: Veuillez entrer un nombre compris entre 0 et 100.\n";															//Affiche un message d'erreur à l'utilisateur
			chances++;																														//Ajoute un chance puisque l'utilisateur en a gaspillé une en tentant une valeur invalide
		}

		system("cls");																														//Efface tout ce qu'il y avait à l'écran pour ne pas q'il devienne trop encombré
	}

	return 0;
}

/* Plan de test
nb					résultat

0					Le jeu continue
100					Le jeu continue
-1					Erreur
101					Erreur
=(iRandom)			Gagné
<(iRandom)			Plus grand
>(iRandom)			Plus petit
*/
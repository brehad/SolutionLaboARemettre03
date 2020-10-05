//But: Demander � l'utilisateur de deviner un nombre al�atoire. Il a 5 chances. Lui dire s'il a r�ussi ou le nombre de chances qu'il lui reste.
//Auteur: Hadrien Breton
//Date: 2020-10-04

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");																													//Permet d'afficher les accents correctement dans la console

	int iRandom;																															// permet de m�moriser le nombre choisi al�atoirement par l�ordinateur
	int nb;																																	//Nombre choisi par l'utilisateur quand il essaie de deviner


	srand(time(0));																															// pour activer l�al�atoire dans le programme
	iRandom = rand() % 101;																													// l�ordinateur calcule un nombre al�atoire entre 0 et 100 et le stocke dans iRandom

	for (int chances = 5; chances > 0; chances--)																							//La variable "chances" est initialis� avec la valeur 5 (5 chances). � la fin de chaque occurence de la boucle, la variable "chances" diminue de 1. Quand elle arrive � 0, la boucle s'arr�te.
	{
		cout << "Vous devez tenter de deviner un nombre entier al�atoire compris entre 0 et 100.\n";										//Explique le jeu � l'utilisateur
		cout << "Il vous reste " << chances << " chances.\n";																				//Affiche le nombre de chances restantes � l'utilisateur
		cout << "Veuillez entrer un nombre entre 0 et 100: \n";																				//Demande � l'utilisateur d'entrer un nombre
		cin >> nb;																															//Enregistre le nombre entr� dans la variable nb

		if (nb >= 0 && nb <= 100)																											//Sert � v�rifier si le nombre entr� par l'utilisateur est bien entre 0 et 100.
		{
			if (nb == iRandom)																												//Sert � d�tecter si l'utilisateur � r�ussi.
			{
				cout << "\nVous avez r�ussi! Le nombre myst�re �tait bien " << iRandom << ".\n";											//Annonce � l'utilisateur qu'il � r�ussi et confirme la valeur de iRandom
				break;																														//Brise la boucle pour arr�ter le programme
			}
			else																															//Cette section est ex�cut�e si l'utilisateur n'a pas la bonne r�ponse.
			{
				if (nb > iRandom)																											//Cette section est ex�cut�e si le nombre de l'utilisateur est plus grand que iRandom
				{
					cout << "Vous vous �tes tromp�!\nLe nombre myst�re est plus petit que le nombre " << nb << ".\nVeuillez r�essayer.\n";	//Annonce au joueur qu'il c'est tromp� et que iRandom est plus petit que son nombre.
					system("pause");																										//Demande au joueur d'appuyer sur un bouton pour continuer, pour lui laisser le temps de lire le message pr�c�dent.
				}
				else if (nb < iRandom)																										//Cette section est ex�cut�e si le nombre de l'utilisateur est plus petit que iRandom
				{
					cout << "Vous vous �tes tromp�!\nLe nombre myst�re est plus grand que le nombre " << nb << ".\nVeuillez r�essayer.\n";	//Annonce au joueur qu'il c'est tromp� et que iRandom est plus grand que son nombre.
					system("pause");																										//Demande au joueur d'appuyer sur un bouton pour continuer, pour lui laisser le temps de lire le message pr�c�dent.
				}
			}
		}
		else																																//Cette section est ex�cut�e seulement si nb est plus petit que 0 ou plus grand que 100
		{
			cout << "Erreur: Veuillez entrer un nombre compris entre 0 et 100.\n";															//Affiche un message d'erreur � l'utilisateur
			chances++;																														//Ajoute un chance puisque l'utilisateur en a gaspill� une en tentant une valeur invalide
		}

		system("cls");																														//Efface tout ce qu'il y avait � l'�cran pour ne pas q'il devienne trop encombr�
	}

	return 0;
}

/* Plan de test
nb					r�sultat

0					Le jeu continue
100					Le jeu continue
-1					Erreur
101					Erreur
=(iRandom)			Gagn�
<(iRandom)			Plus grand
>(iRandom)			Plus petit
*/
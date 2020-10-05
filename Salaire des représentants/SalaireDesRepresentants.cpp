//But: Entrer les ventes brutes hebdomadaires pour calculer le salaire des employ�s. Entrer -1 aux ventes pour terminer le programme.
//Auteur: Hadrien Breton
//Date: 2020-10-04

#include <iostream>																		//Pour pouvoir utiliser cout et cin
using namespace std;																	//Pour ne pas avoir � utiliser std:: devant cout et cin

int main()
{
	setlocale(LC_ALL, "");																//Pour afficher correctement les accents dans la console
	
	float ventes;																		//Montant brut des ventes
	float salaire;																		//Salaire de l'employ�
	
	cout << "Veuillez entrer le montant brut des ventes: \n";							//Affiche le message � l'�cran
	cin >> ventes;																		//Enregistre la valeur entr�e par l'utilisateur dans la variable ventes

	if (ventes < -1)																	//La section entre crochets est ex�cut�e seulement si ventes est plus petit que -1. Le programme accepte la valeur -1 puisque c'est la valeur pour arr�ter le programme.
	{
		cout << "Erreur: Veuillez entrer un nombre positif.\n";							//Affiche un message d'erreur
		
		system("pause");																//Demande � l'utilisateur d'appuyer sur une touche pour s'assurer qu'il a bien lu le message. Le programme ne continue pas tant que l'utilisateur n'appuie pas.
		system("cls");																	//Efface tout ce qu'il y a � l'�cran.
	}
	else																				//Le programme ex�cute cette section seulement s'il n'a pas ex�cut� le "if" pr�c�dent
	{
		while (ventes != -1)															//Le programme va ex�cuter cette section en boucle tant que la variable "ventes" n'est pas �gale � -1.
		{
			if (ventes < -1)															//M�me condition que plus haut pour afficher le m�me message d'erreur
			{
				cout << "Erreur: Veuillez entrer un nombre positif.\n";

				system("pause");
				system("cls");

				cout << "Veuillez entrer le montant brut des ventes: \n";				//Le programme redemmande d'entrer une valeur pour la variable "ventes" pour que �viter que la boucle conitnue � l'infini.
				cin >> ventes;
			}
			else																		//Le programme entre dans cette section seulement si "ventes" est �gale ou sup�rieure � 0 (puisque la boucle est rompue si la valeur est -1.
			{
				salaire = (ventes * 0.075) + 250;										//Le programme effectue le calcul pour le salaire et l'enregistre dans la variable "salaire"

				cout << "Le salaire de l'employ� est de " << salaire << " $.\n";		//Affiche le salaire de l'employ�

				system("pause");
				system("cls");

				cout << "Veuillez entrer le montant brut des ventes: \n";				//Le programme redemmande d'entrer une valeur pour "ventes" � la fin de la boucle pour qu'il puisse v�rifier que la valeur est valide.
				cin >> ventes;
			}
		}
		cout << "Vous �tes sortis du programme.\n";										//Affiche � l'utilisateur que le programme est termin�.
	}

	return 0;
}



/*Plan de test
Montant				Salaire				Erreur				Vous �tes sortis du programme
0					250
10					250.75
100					257,50
10000				1000
432.57				282.443
-1															X
-2										x
-1.1									x
-87										x
-30000									x
*/
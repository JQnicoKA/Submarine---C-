/**
* @author Lecas_Nicolas
* @file main.cpp
* @date 19/10/2021
* @brief Bienvenue dans ce code de simulation d'un environnement IOT !
		 Des commentaires seront présents tout le long du code afin
		 de documenter le travail.

		 L'idée générale de mon main est de proposer un menu regroupant
		 deux choix proposés à l'utilisateur. Le premier s'il veut observer
		 des salves de données venant des 4 capteurs en même temps toutes
		 les 5 secondes, et le deuxième s'il veut observer pendant un certain
		 temps les données de nos 4 capteurs envoyés à fréquence différente.
		 Pour se faire voici ma stratégie:
		 1er cas : Toutes les 5 secondes, et cela le nombre de fois que
		 		   l'utilisateur veut de données, on crée un objet de type
		 		   Scheduler qui va récupérer les valeurs de nos capteurs
		 		   pour les inscrire comme attributs. Suite à cela, affichage
		 		   et écriture de ces valmeurs dans des fichiers log grâce
		 		   à deux fonctions statiques de la classe Server
		 2ème cas : Toutes les secondes, même comportement que dans le premier
		 			cas à une différence. A l'itérieur des fonctions, on choisit
		 			quand traiter certains capteurs et quand en "délaisser"
		 			d'autres en fonction du nombre d'enregistrements déjà effectué.
		 			Ce stratagème me permettra de traiter la valeur de Pression
		 			toutes les secondes et les valeurs de lumière toutes les 4
		 			secondes par exemple

		 Le projet est fonctionnel et répond selon moi au cahier des charges imposé.
		 Cela dit, voici des points sur lesquels j'aurais pu améliorer ce code :
		 4 points faibles selon moi : -Premièrement même si les fréquences de traitement
		 							  sont différentes, ce n'est qu'une illusion car on
		 							  "récupère" les valeurs en soit toutes les secondes,
		 							  c'est seulement que parfois on ne les affiche et ne
		 							  les écrit pas dans les fichiers .log
		 							  -De plus, les valeurs ne sont pas en soit reçues et
		 							  traitées toutes les 1sec, mais toutes les (1, quelque
		 							  chose) secondes. Ce quelque chose est dû à mon utilisation
		 							  de sleep à chaque traitement et au retard engendré
		 							  par le processus du programme en lui même
		 							  -Troisièmement, j'aurais pu templéter plus de fonctions
		 							  et classes pour traiter des différents types dans le
		 							  2ème cas, en effet des parties de code sont quelquefois
		 							  répétitives, problème que j'aurai pu résoudre en consacrant
		 							  plus d'importance aux templates
		 							  -En dernier lieu, le manque de sécurité de mon code, si
		 							  l'utilisateur écrit n'importe quoi, le programme n'y sera
		 							  pas préparé et plantera
*/

#include "Scheduler.hpp"
#include "Server.hpp"

#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{

	int choix = 0; // Déclaration d'une variable choix qui va contenir le choix de l'utilisateur
	do{


		//Affichage du menu pour que l'utilisateur fasse son choix
		std::cout << "\n*************************************************************" << endl;
		std::cout << "Bienvenue dans notre simulation d'environnement de sous-marin" << endl;
		std::cout << "*************************************************************" << endl << endl;

		std::cout << "Que voulez-vous observer ?" << endl;
		std::cout << "1 : Obtenir des donnees toutes les 5 secondes" << endl;
		std::cout << "2 : Obtenir des donnees a differentes frequences" << endl;
		std::cout << "3 : Quitter le programme" << endl;

		// On récupère le choix de l'utilisateur
		cin>> choix;
		cin.ignore();

		/*
		*Cette valeur va représenter le nombre de valeurs que l'utilisateur désire dans la partie 1
		*et le nombre de secondes qu'il veut attendre dans la partie 2
		*/
		int combien;

 		//Switch qui va gérer les différents cas, c'est à dire les différents choix de l'utilisateur
		switch(choix)
		{
			//Cas dans lequel on lance notre programme pour afficher un relevé unique
			case 1 :
			{
				int ouEcrire =0;
				std::cout << "Ou voulez vous ecrire les donnees ?" << endl;
				std::cout << "1 : Dans la console uniquement" << endl;
				std::cout << "2 : Dans les fichiers uniquement" << endl;
				std::cout << "3 : Dans les deux" << endl;

				// On récupère le choix de l'utilisateur
				cin>> ouEcrire;
				cin.ignore();

				// On récupère le nombre de valeurs que l'utilisateur veut
				std::cout << "Combien de valeurs voulez-vous?" << endl;
				cin>> combien;
				cin.ignore();
				cout << "" << endl;
				cout << "Voici les valeurs de vos capteurs : " << endl << endl;

				/*
				*Creation d'une boucle qui crée un objet envoi1 de type Scheduler qui récupère les
				données des capteurs, puis affichage de ceux ci dans la console et inscription dans
				les fichiers de cesdites données grâce à deux fonctions statiques de Server
				*On fait ça le nombre de fois que l'utilisateur veut ses données
				 */
				int i=1;
				while(i != combien+1)
				{
					//Creation de l'objet envoi1, appel du constructeur par défaut de la classe Scheduler
					Scheduler envoi1;

	    			//Affichage et écriture console des attributs de l'objet donnee1, les valeurs de nos capteurs
	    			if(ouEcrire == 1 || ouEcrire == 3)
	    			{
	    				Server::consoleWrite(envoi1.getValeurTemperature(), envoi1.getValeurPression(), envoi1.getValeurHumidity(), envoi1.getValeurLight());
	    			}
	    			if(ouEcrire ==2 || ouEcrire == 3)
	    			{
	    				Server::fileWrite(envoi1.getValeurTemperature(), envoi1.getValeurPression(), envoi1.getValeurHumidity(), envoi1.getValeurLight());
	    			}

	    			//On effectue cette operation toutes les 5 secondes le nombre de fois voulues par l'utilisateur
					sleep(5);
					i++;
				}
			}
			break;

			//Pour la seconde partie, quand l'utilisateur voudra plusieurs relevés à un intervalle de temps régulier
			case 2 :
			{
				int ouEcrire =0;
				std::cout << "Ou voulez vous ecrire les donnees ?" << endl;
				std::cout << "1 : Dans la console uniquement" << endl;
				std::cout << "2 : Dans les fichiers uniquement" << endl;
				std::cout << "3 : Dans les deux" << endl;

				// On récupère le choix de l'utilisateur
				cin>> ouEcrire;
				cin.ignore();

				std::cout << "Les capteurs vont renvoyer des valeurs comme suit:" << endl;
				std::cout << "Capteur de Pression : Toutes les 1sec" << endl;
				std::cout << "Capteur de Temperature : Toutes les 2sec" << endl;
				std::cout << "Capteur d'Humidite : Toutes les 3sec" << endl;
				std::cout << "Capteur de Lumiere : Toutes les 4sec" << endl << endl;
				
				// On récupère le nombre de temps que l'utilisateur veut attendre
				std::cout << "Pendant combien de secondes voulez vous recevoir des valeurs?" << endl;
				cin>> combien;
				cin.ignore();
				cout << "" << endl;
				cout << "Voici les valeurs de vos capteurs : " << endl << endl;


				/*
				Creation d'une boucle qui appelle la fonctionGenerale de Scheduler
				le nombre de fois que l'utilisateur veut des données
				 */
				int i=1;
				while(i != combien+1)
				{
					//Creation de l'objet envoi1, appel du constructeur par défaut de la classe Scheduler
					Scheduler envoi1;

	    			//Affichage et écriture console des attributs de l'objet donnee1, les valeurs de nos capteurs
	    			if(ouEcrire == 1 || ouEcrire == 3)
	    			{
	    				Server::consoleWrite(envoi1.getValeurTemperature(), envoi1.getValeurPression(), envoi1.getValeurHumidity(), envoi1.getValeurLight(), i);
	    			}
	    			if(ouEcrire ==2 || ouEcrire == 3)
	    			{
	   					Server::fileWrite(envoi1.getValeurTemperature(), envoi1.getValeurPression(), envoi1.getValeurHumidity(), envoi1.getValeurLight(), i);
	   				}

	   				//On effectue cette operation toutes les secondes, le nombre de secondes que l'utilisateur veut
					sleep(1);
					i++;
				}
			}
			break;

			//Pour permettre à l'utilisateur de quitter le programme
			case 3 :
			{
				cout << "Merci pour votre participation" << endl;
			}
			break;
		}

	 }while(choix != 3);

    return 0;
}

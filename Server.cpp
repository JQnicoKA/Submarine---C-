/*
* Pour un confort visuel, ici les implémentations de chaque méthode seront séparés par :
**************************************************************************************************************************************************************************************ceci
*/

#include "Server.hpp"

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

/*
FORME CANONIQUE
*/

Server::Server()
{

}

Server::~Server()
{

}

/*
AUTRES METHODES
*/
//**************************************************************************************************************************************************************************************//

void Server::consoleWrite(int temperature, float pression, int humidity, int light)
{
	cout << "Temperature : " << temperature << " Degres Celsius"<< endl;
	cout << "Pression : " << pression << " Bar"<< endl;
	cout << "Humidity : " << humidity << " %"<< endl;
	cout << "Light : " << light << " Lux"<< endl;
}

//**************************************************************************************************************************************************************************************//

void Server::fileWrite(int temperature, float pression, int humidity, int light)
{
	/**
	Déclaration du flux et définition du chemin suivi pour trouver le fichier.txt dans lequel on veut écrire.
	On veut écrire à la suite du fichier et pas l'effacer à chaque nouveau relevé, on le précise avec ios::app
	*/
	ofstream monFluxTemperature ("temperature.log", ios::app);

	//Vérification nécessaire, si on rencontre une erreur dans l'ouverture du fichier, on s'arrête
	if(monFluxTemperature)
	{
		// On déclare un argument pour()
    	time_t tt;

  		// On déclare un pointeur pour stocker la valeur retournée par localtime()
    	struct tm* pti;

    	// On applique time()
    	time (&tt);

    	// On utilise localtime()
    	pti = localtime(&tt);

  		// Ecriture de la date et l'heure et des attributs dans le fichier
		monFluxTemperature << "Resultats au "<<  asctime(pti);
		monFluxTemperature << "Temperature : " << temperature << " Degres Celsius"<< endl <<endl;
	}

	/**
	Déclaration du flux et définition du chemin suivi pour trouver le fichier.txt dans lequel on veut écrire.
	On veut écrire à la suite du fichier et pas l'effacer à chaque nouveau relevé, on le précise avec ios::app
	*/
	ofstream monFluxPression ("pression.log", ios::app);

	//Vérification nécessaire, si on rencontre une erreur dans l'ouverture du fichier, on s'arrête
	if(monFluxPression)
	{
		// On déclare un argument pour()
    	time_t tt;

  		// On déclare un pointeur pour stocker la valeur retournée par localtime()
    	struct tm* pti;

    	// On applique time()
    	time (&tt);

    	// On utilise localtime()
    	pti = localtime(&tt);

  		// Ecriture de la date et l'heure et des attributs dans le fichier
		monFluxPression << "Resultats au "<<  asctime(pti);
		monFluxPression << "Pression : " << pression << " Bar"<< endl <<endl;
	}

	/**
	Déclaration du flux et définition du chemin suivi pour trouver le fichier.txt dans lequel on veut écrire.
	On veut écrire à la suite du fichier et pas l'effacer à chaque nouveau relevé, on le précise avec ios::app
	*/
	ofstream monFluxHumidity ("humidity.log", ios::app);

	//Vérification nécessaire, si on rencontre une erreur dans l'ouverture du fichier, on s'arrête
	if(monFluxHumidity)
	{
		// On déclare un argument pour()
    	time_t tt;

  		// On déclare un pointeur pour stocker la valeur retournée par localtime()
    	struct tm* pti;

    	// On applique time()
    	time (&tt);

    	// On utilise localtime()
    	pti = localtime(&tt);

  		// Ecriture de la date et l'heure et des attributs dans le fichier
		monFluxHumidity << "Resultats au "<<  asctime(pti);
		monFluxHumidity << "Humidity : " << humidity << " %"<< endl <<endl;
	}

	/**
	Déclaration du flux et définition du chemin suivi pour trouver le fichier.txt dans lequel on veut écrire.
	On veut écrire à la suite du fichier et pas l'effacer à chaque nouveau relevé, on le précise avec ios::app
	*/
	ofstream monFluxLight ("light.log", ios::app);

	//Vérification nécessaire, si on rencontre une erreur dans l'ouverture du fichier, on s'arrête
	if(monFluxLight)
	{
		// On déclare un argument pour()
    	time_t tt;

  		// On déclare un pointeur pour stocker la valeur retournée par localtime()
    	struct tm* pti;

    	// On applique time()
    	time (&tt);

    	// On utilise localtime()
    	pti = localtime(&tt);

  		// Ecriture de la date et l'heure et des attributs dans le fichier
		monFluxLight << "Resultats au "<<  asctime(pti);
		monFluxLight << "Light : " << light << " Lux"<< endl << endl;
	}

	else
	{
		cout << "ERROR : impossible to open the file" << endl;
	}

}

//**************************************************************************************************************************************************************************************//

void Server::consoleWrite(int temperature, float pression, int humidity, int light, int i)
{
    cout << "" << endl;
    cout << "Donnee " << i << ":" << endl;

    //Si i%2 =0, cela veut dire que i est un multiple de 2, on utilise ce stratagème pour que cette action s'effectue toutes les 2sec
    if(i%2 ==0)
    cout << "Temperature : " << temperature << " Degres Celsius"<< endl;
    cout << "Pression : " << pression << " Bar"<< endl;
    
    //Si i%3 =0, cela veut dire que i est un multiple de 3, on utilise ce stratagème pour que cette action s'effectue toutes les 3sec
    if(i%3 ==0)
    cout << "Humidity : " << humidity << " %"<< endl;
    
    //Si i%4 =0, cela veut dire que i est un multiple de 4, on utilise ce stratagème pour que cette action s'effectue toutes les 4sec
    if(i%4 ==0)
   cout << "Light : " << light << " Lux"<< endl;
}

//**************************************************************************************************************************************************************************************//

void Server::fileWrite(int temperature, float pression, int humidity, int light, int i)
{
    /**
    Déclaration du flux et définition du chemin suivi pour trouver le fichier.txt dans lequel on veut écrire.
    On veut écrire à la suite du fichier et pas l'effacer à chaque nouveau relevé, on le précise avec ios::app
    */
    ofstream monFluxTemperature ("temperature.log", ios::app);

    //Vérification nécessaire, si on rencontre une erreur dans l'ouverture du fichier, on s'arrête
    //Si i%2 =0, cela veut dire que i est un multiple de 2, on utilise ce stratagème pour que cette action s'effectue toutes les 2sec
    if(monFluxTemperature)
    {
        if(i%2 ==0)
            {
            // On déclare un argument pour()
            time_t tt;

            // On déclare un pointeur pour stocker la valeur retournée par localtime()
            struct tm* pti;

            // On applique time()
            time (&tt);

            // On utilise localtime()
            pti = localtime(&tt);

            // Ecriture de la date et l'heure et des attributs dans le fichier
            monFluxTemperature << "Resultats au "<<  asctime(pti);
            monFluxTemperature << "Temperature : " << temperature << " Degres Celsius"<< std::endl << endl;
            }
    }

    /**
    Déclaration du flux et définition du chemin suivi pour trouver le fichier.txt dans lequel on veut écrire.
    On veut écrire à la suite du fichier et pas l'effacer à chaque nouveau relevé, on le précise avec ios::app
    */
    ofstream monFluxPression ("pression.log", ios::app);

    //Vérification nécessaire, si on rencontre une erreur dans l'ouverture du fichier, on s'arrête
    if(monFluxPression)
    {
        // On déclare un argument pour()
        time_t tt;

        // On déclare un pointeur pour stocker la valeur retournée par localtime()
        struct tm* pti;

        // On applique time()
        time (&tt);

        // On utilise localtime()
        pti = localtime(&tt);

        // Ecriture de la date et l'heure et des attributs dans le fichier
        monFluxPression << "Resultats au "<<  asctime(pti);
        monFluxPression << "Pression : " << pression << " Bar"<< endl << endl;
    }

    /**
    Déclaration du flux et définition du chemin suivi pour trouver le fichier.txt dans lequel on veut écrire.
    On veut écrire à la suite du fichier et pas l'effacer à chaque nouveau relevé, on le précise avec ios::app
    */
    ofstream monFluxHumidity ("humidity.log", ios::app);

    //Vérification nécessaire, si on rencontre une erreur dans l'ouverture du fichier, on s'arrête
    //Si i%3 =0, cela veut dire que i est un multiple de 3, on utilise ce stratagème pour que cette action s'effectue toutes les 3sec
    if(monFluxHumidity)
    {
        if(i%3 ==0)
        {
            // On déclare un argument pour()
            time_t tt;

            // On déclare un pointeur pour stocker la valeur retournée par localtime()
            struct tm* pti;

            // On applique time()
            time (&tt);

            // On utilise localtime()
            pti = localtime(&tt);

            // Ecriture de la date et l'heure et des attributs dans le fichier
            monFluxHumidity << "Resultats au "<<  asctime(pti);
            monFluxHumidity << "Humidity : " << humidity << " %"<< endl << endl;
        }
    }

    /**
    Déclaration du flux et définition du chemin suivi pour trouver le fichier.txt dans lequel on veut écrire.
    On veut écrire à la suite du fichier et pas l'effacer à chaque nouveau relevé, on le précise avec ios::app
    */
    ofstream monFluxLight ("light.log", ios::app);

    //Vérification nécessaire, si on rencontre une erreur dans l'ouverture du fichier, on s'arrête
    //Si i%4 =0, cela veut dire que i est un multiple de 4, on utilise ce stratagème pour que cette action s'effectue toutes les 4sec
    if(monFluxLight)
    {
        if(i%4 ==0)
        {
            // On déclare un argument pour()
            time_t tt;

            // On déclare un pointeur pour stocker la valeur retournée par localtime()
            struct tm* pti;

            // On applique time()
            time (&tt);

            // On utilise localtime()
            pti = localtime(&tt);

            // Ecriture de la date et l'heure et des attributs dans le fichier
            monFluxLight << "Resultats au "<<  asctime(pti);
            monFluxLight << "Light : " << light << " Lux"<< endl << endl;
        }
    }

    else
    {
        cout << "ERROR : impossible to open the file" << endl;
    }

}
/**
* @author Lecas_Nicolas
* @file Server.hpp
* @date 17/10/2021
* @brief Classe qui va récupérer les données de nos 4 capteurs et qui implémente les fonctions
		 consoleWrite() et fileWrite() afin d'afficher dans la console et écrire dans un fichier
		 cesdites données
*/

#ifndef DEF_SERVER
#define DEF_SERVER

#include <iostream>

class Server
{
public:

	/*
	Ma classe Server n'ayant pas d'attributs, ça n'a pas de sens d'y intégrer un constructeur par
	recopie est un opérateur d'affectation
	*/
    Server();
    ~Server();

    /*
    *Fonction consoleWrite appelée lors du choix 1 de l'utilisateur, elle va afficher les valeurs
    des capteurs à la console
    *@param temperature, pression, humidity, light les valeurs de mes capteurs
    */
    static void consoleWrite(int temperature, float pression, int humidity, int light);

     /*
    *Fonction fileWrite appelée lors du choix 1 de l'utilisateur, elle va écrire les valeurs
    des capteurs dans mes fichiers log
    *@param temperature, pression, humidity, light les valeurs de mes capteurs
    */
    static void fileWrite(int temperature, float pression, int humidity, int light);

    /*
    *Fonction consoleWrite surchargée appelée lors du choix 2 de l'utilisateur, elle va 
    afficher les valeurs des capteurs à la console
    *@param temperature, pression, humidity, light les valeurs de mes capteurs
    *@param i le numéro de la donnée 1ére, 2ème, 8ème....
    */
    static void consoleWrite(int temperature, float pression, int humidity, int light, int i);

    /*
    *Fonction fileWrite surchargée appelée lors du choix 2 de l'utilisateur, elle va 
    afficher les valeurs des capteurs à la console
    *@param temperature, pression, humidity, light les valeurs de mes capteurs
    *@param i le numéro de la donnée 1ére, 2ème, 8ème....
    */
    static void fileWrite(int temperature, float pression, int humidity, int light, int i);
};

#endif

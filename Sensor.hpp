/**
* @author Lecas_Nicolas
* @file Sensor.hpp
* @date 17/10/2021
* @brief Classe qui possède 3 attributs m_valeur, m_min et m_max. Ces 3 attributs sont de type T
		 après avoir templété cette classe, ainsi chaque capteur peut définir un type pour son 
		 min et son max afin de résulter le bon type pour son m_valeur (Temperature, Humidity,
		 Light seront des int quand Pression sera un float) . Cette classe implément la fonction 
		 aleaGenVal() surchargee qui va retourner une valeur aléatoire int ou float entre m_min 
		 et m_max. Les capteurs précis qui héritent de cette classe vont définir leur m_min et 
		 m_max pour obtenir une m_valeur cohérente
*/

#ifndef DEF_SENSOR
#define DEF_SENSOR

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <cstdlib>
#include <ctime>

//Definition d'une classe Template T, reconnue dans ma classe Sensor
template <typename T>
class Sensor
{
public:

	//Forme canonique
    Sensor()
    {
		(void)m_min;
		(void)m_max;
		(void)m_valeur;
	}

    Sensor(Sensor const& AutreClasse)
    {
    	(void)AutreClasse;
	}
	
	~Sensor()
    {
	}

	Sensor& operator=(const Sensor& autreClasse)
	{
		m_valeur = autreClasse.m_valeur;
		m_min = autreClasse.m_min;
		m_max = autreClasse.m_max;
		return* this;
	}

    /**
	Accesseur qui permet, à l'appel de celui-ci, de récupérer
	la valeur de l'attribut m_valeur
	*/
    T getValeur() const
    {
			return m_valeur;
	}

protected:

	/**
	Retourne une valeur int aléatoire entre deux bornes
	@param min, notre borne inférieure
	@param max, notre borne supérieure
	@return int, notre nombre aléatoire généré
	*/
    int aleaGenVal(int min, int max)
    {
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);

		return dist6(rng);
	}

	/**
	Retourne une valeur float aléatoire entre deux bornes
	@param min, notre borne inférieure
	@param max, notre borne supérieure
	@return float, notre nombre aléatoire généré
	*/
	float aleaGenVal(float min, float max)
    {
    	srand (static_cast <unsigned> (time(0)));
		return min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
	}

	//Attributs
	T m_valeur; // Valeur relevée par notre capteur
	T m_min; // Minimum possible de cette valeur
	T m_max; // Maximum possible de cette valeur
};

#endif

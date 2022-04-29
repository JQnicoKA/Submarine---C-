#include <iostream>

#include "Scheduler.hpp"

using namespace std;

/*
FORME CANONIQUE
*/

Scheduler::Scheduler()
{
		//Creation de 4 capteurs
	    Humidity monHumidite;
	    Pression maPression;
	    Temperature maTemperature;
	    Light maLumiere;

	    //Nos attributs prennent la valeur des 4 capteurs via des accesseurs de Sensor
	    m_valeurTemperature = maTemperature.getValeur();
	    m_valeurPression = maPression.getValeur();
	    m_valeurHumidity = monHumidite.getValeur();
	    m_valeurLight = maLumiere.getValeur();
}


Scheduler::~Scheduler()
{

}


Scheduler::Scheduler(const Scheduler& autreClasse) : m_valeurTemperature(autreClasse.m_valeurTemperature), m_valeurPression(autreClasse.m_valeurPression), m_valeurHumidity(autreClasse.m_valeurHumidity), m_valeurLight(autreClasse.m_valeurLight)
{

}

Scheduler& Scheduler :: operator=(const Scheduler& autreClasse)
{
	m_valeurTemperature = autreClasse.m_valeurTemperature;
	m_valeurPression = autreClasse.m_valeurPression;
	m_valeurHumidity = autreClasse.m_valeurHumidity;
	m_valeurLight = autreClasse.m_valeurLight;
	return* this;
}

/*
ACCESSEURS
*/

int Scheduler::getValeurTemperature()
{
	return m_valeurTemperature;
}

float Scheduler::getValeurPression()
{
	return m_valeurPression;
}

int Scheduler::getValeurHumidity()
{
	return m_valeurHumidity;
}

int Scheduler::getValeurLight()
{
	return m_valeurLight;
}
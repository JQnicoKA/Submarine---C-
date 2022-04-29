#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Humidity.hpp"
using namespace std;

/*
CONSTRUCTEURS
*/

/**
Définition de nos deux bornes m_min et m_max, envoyées
à la fonction aleaGenVal de int  pour l'obtention d'une 
valeur aléatoire entre cesdites bornes
*/
Humidity::Humidity()
{
	m_min = 60;
	m_max = 90;
	m_valeur = aleaGenVal(m_min, m_max);
}


Humidity::~Humidity()
{
    /* Rien à mettre ici car on ne fait pas d'allocation dynamique
    dans la classeHumidity. Le destructeur est donc inutile mais
    je le mets pour montrer à quoi cela ressemble.
    En temps normal, un destructeur fait souvent des delete et quelques
    autres vérifications si nécessaire avant la destruction de l'objet. */
}

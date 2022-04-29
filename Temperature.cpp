#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Temperature.hpp"
using namespace std;

/*
CONSTRUCTEURS
*/

/**
Définition de nos deux bornes m_min et m_max, envoyées
à la fonction aleaGenVal de int pour l'obtention d'une 
valeur aléatoire entre cesdites bornes
*/
Temperature::Temperature()
{
	m_min = 15;
	m_max = 25;
	m_valeur = aleaGenVal(m_min, m_max);
}


Temperature::~Temperature()
{

}

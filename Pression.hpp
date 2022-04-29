/**
* @author Lecas_Nicolas
* @file Pression.hpp
* @date 17/10/2021
* @brief Classe héritière de Sensor, c'est notre deuxième capteur précis, qui va définir
		 ses deux bornes pour obtenir un m_valeur cohérent
*/

#ifndef DEF_PRESSION
#define DEF_PRESSION

#include <iostream>
#include "Sensor.hpp"

//Ce capteur précis aura des attributs de type float
class Pression : public Sensor<float>
{
public:

    Pression();
    ~Pression();
};

#endif

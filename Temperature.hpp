/**
* @author Lecas_Nicolas
* @file Temperature.hpp
* @date 17/10/2021
* @brief Classe héritière de Sensor, c'est notre troisième capteur précis, qui va définir
		 ses deux bornes pour obtenir un m_valeur cohérent
*/

#ifndef DEF_TEMPERATURE
#define DEF_TEMPERATURE

#include <iostream>
#include "Sensor.hpp"

//Ce capteur précis aura des attributs de type int
class Temperature : public Sensor<int>
{
public:

    Temperature();
    ~Temperature();
};

#endif

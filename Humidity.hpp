/**
* @author Lecas_Nicolas
* @file Humidity.hpp
* @date 17/10/2021
* @brief Classe héritière de Sensor, c'est notre premier capteur précis, qui va définir
		 ses deux bornes pour obtenir un m_valeur cohérent
*/

#ifndef DEF_HUMIDITY
#define DEF_HUMIDITY

#include <iostream>
#include "Sensor.hpp"

//Ce capteur précis aura des attributs de type int
class Humidity : public Sensor<int>
{
public:

    Humidity();
    ~Humidity();
};

#endif

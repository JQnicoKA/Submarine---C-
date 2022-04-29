/**
* @author Lecas_Nicolas
* @file Light.hpp
* @date 17/10/2021
* @brief Classe héritière de Sensor, c'est notre dernier capteur précis, qui va définir
		 ses deux bornes pour obtenir un m_valeur cohérent
*/

#ifndef DEF_LIGHT
#define DEF_LIGHT

#include <iostream>
#include "Sensor.hpp"

//Ce capteur précis aura des attributs de type int
class Light : public Sensor<int>
{
public:

    Light();
    ~Light();
};

#endif

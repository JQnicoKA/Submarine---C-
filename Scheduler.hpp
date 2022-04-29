/**
* @author Lecas_Nicolas
* @file Scheduler.hpp
* @date 17/10/2021
* @brief Classe qui va, via son constructeur par défaut, créer nos 4 capteurs précis,
         et récupérer la valeur de ces capteurs pour en faire ses attributs. J'ai créé
         des accesseurs sur ces attributs pour que par la suite la classe Server y aie
         accès. J'ai d'abord pensé à créé une méthode de Server amie avec la classe
         Scheduler ou alors faire en sorte que l'entière classe Server soit amie avec
         Scheduler mais j'ai rencontré des problèmes d'ou ce choix d'accesseurs
*/

#ifndef DEF_SCHEDULER
#define DEF_SCHEDULER

#include <iostream>
#include "Sensor.hpp"
#include "Humidity.hpp"
#include "Pression.hpp"
#include "Light.hpp"
#include "Temperature.hpp"


class Scheduler
{
public:

	//Forme canonique
    Scheduler();
    ~Scheduler();
    Scheduler(const Scheduler& autreClasse);
    Scheduler& operator=(const Scheduler& autreClasse);

    //Accesseurs
    int getValeurTemperature();
    float getValeurPression();
    int getValeurHumidity();
    int getValeurLight();

private:

	//Attributs
    int m_valeurTemperature;
    float m_valeurPression;
    int m_valeurHumidity;
    int m_valeurLight;

};

#endif

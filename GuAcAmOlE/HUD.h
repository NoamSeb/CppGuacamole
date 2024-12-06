#pragma once
#include "SFML/Graphics.hpp"

class HUD
{
	public :
		//Get le singleton
		static HUD* getInstance() {
			if (!instance) {
				instance = new HUD;
				return instance;
			}
		}

		//Fonctions publiques
		void LoadFont();
		sf::Text CreateText(std::string text, sf::Color color = sf::Color::White);
		sf::Text CreateTimerText(float timeInSeconds);

	private :
		//pointeur vers le singleton
		static HUD* instance;

		//variables privées
		sf::Font arial;

		//Fonctions privées
		std::string FormatMyTimer(float timeInSeconds);
};


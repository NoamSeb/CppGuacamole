#pragma once
#include "SFML/Graphics.hpp"
#include "Main.h"

class HUD
{
	public :
		static HUD* getInstance() {
			static HUD instance; //init instance one time 
			return &instance;
		}

		//Fonctions publiques

		void InitGame();

		void LoadFont();
		sf::Text CreateText(
			// Create text  : string required, pos/size/color optional
			std::string text, 
			int size = 50,
			sf::Vector2f pos = sf::Vector2f(Main::widthEcran / 2.0f, 30.0f), // middle top of screen
			sf::Color color = sf::Color::Green
		);
		sf::Text CreateTimerText(float timeInSeconds);

	private :

		//variables privées
		sf::Font arial;

		//Fonctions privées
		std::string FormatMyTimer(float timeInSeconds);
};


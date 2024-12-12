#include "HUD.h"
#include "Object.h"
#include "Main.h"
#include "Player.h"
#include <iostream>


//initialisation du singleton
HUD* HUD::instance = nullptr;

class Player;

//GameLoop
void HUD::InitGame() {
    Main::InitAllObjects();
    Main::DeleteAllBlocks(); // delete all blocks
}


//Texts
void HUD::LoadFont() {
    // arial.loadFromFile("..\\external\\Fonts\\Arial.ttf");
}

sf::Text HUD::CreateText(std::string text, sf::Color color) {
    sf::Text myText;
    myText.setFont(arial);
    myText.setString(text);
    myText.setFillColor(color);
    myText.setPosition(Main::widthEcran/2.0f - 50, 10.0f);
    myText.setCharacterSize(50);

    return myText;
}

//Timer
sf::Text HUD::CreateTimerText(float timeInSeconds) {

    sf::Text myTimer;
    myTimer = HUD::CreateText(HUD::FormatMyTimer(timeInSeconds));

    return myTimer;
}

std::string HUD::FormatMyTimer(float timeInSeconds) {
        std::string formattedString;

        //get minutes && seconds
        int minutes = (int)(timeInSeconds / 60.0f);
        int seconds = (int)((int)timeInSeconds % 60);

        //Float to string
        std::string sec = std::to_string(seconds);
        std::string min = std::to_string(minutes);

        //Set le timer en format 00:00
        if (seconds < 10) {
            sec = "0" + sec;
        }
        if (minutes < 10) {
            min = "0" + min;
        }
        
        formattedString = min + " : " + sec;

        return formattedString;

}

//void HUD::InitTimer(float timeInSeconds) {
//    timeInSeconds = 0;
//}

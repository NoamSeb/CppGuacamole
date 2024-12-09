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
    //Main::DeleteAllEnemies();
    Main::InitAllObjects();
}


//Texts
void HUD::LoadFont() {
    arial.loadFromFile("..\\external\\Fonts\\Arial.ttf");
}

sf::Text HUD::CreateText(std::string text, sf::Color color) {
    sf::Text myText;
    myText.setFont(arial);
    myText.setString(text);
    //myText.setScale(400,1.5f);
    myText.setFillColor(color);
    myText.setPosition(350.0f, 5.0f);

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
        
        formattedString = "timer : " + min + " : " + sec;

        return formattedString;

}

//void HUD::InitTimer(float timeInSeconds) {
//    timeInSeconds = 0;
//}

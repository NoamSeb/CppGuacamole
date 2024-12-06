#include "HUD.h"
#include <iostream>

//initialisation du singleton
HUD* HUD::instance = nullptr;

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

//void SetText(sf::Text& myText, std::string text) {
//
//    sf::Font myFont;
//    myFont.loadFromFile("..\\external\\Fonts\\Arial.ttf");
//    std::cout << "jsuis fzheghgzhfghazgfhzgh";
//
//    myText.setFont(myFont);
//
//    std::cout << "jsuis loooooooooooooooooooooo";
//    myText.setString(text);
//    //myText.setScale(400,1.5f);
//    myText.setPosition(40.0f, 5.0f);
//
//    std::cout << "helllllllllllp";
//}


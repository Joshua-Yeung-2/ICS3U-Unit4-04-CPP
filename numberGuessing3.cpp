// copyright (c) 2020 Joshua Yeung All rights reserved

// Created by: Joshua Yeung
// Created on October 2021
// This program is to test the while loop

#include <random>
#include <iostream>
#include <string>

int main() {
    // this function is to guessing the number
    // a number between 1 and 100
    int someRandomNumber;


    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0 , 100);  // [0,100]
    someRandomNumber = idist(rgen);


    std::cout << someRandomNumber << std::endl;
    std::string userInputStr;
    int userInput;

    while (true) {
        // input
        std::cout << "Enter a random number from 1 to 100 here: ";
        std::cin >> userInputStr;
        std::cout << "" << std::endl;
        // process & output
        try {
            userInput = std::stoi(userInputStr);
            if (userInput == someRandomNumber) {
                std::cout << "congratulations, you got it!" << std::endl;
                break;
            } else if (userInput < someRandomNumber) {
                std::cout << "sorry, you got it wrong," <<
                "the number is a little bit higher" << std::endl;
            } else {
                std::cout << "sorry, you got it wrong," <<
                "the number is a little bit smaller" << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "That was not a valid integer" << std::endl;
        }
    }
    std::cout << "\nDone" << std::endl;
}

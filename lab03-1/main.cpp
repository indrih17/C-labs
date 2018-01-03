/**
    To write a program that waits for input letters and,
    depending on entered values, according to whether
    the letter is uppercase or lowercase.
*/

#include <iostream>
#include "math.h"

std::string checkCaseOfLetter(char letter) {
    switch(letter) {
        case 'a'...'z':
            return "Lowercase letter";
        case 'A'...'Z':
            return "Uppercase letter";
        default:
            return "The character is not a letter";
    }
}

int main() {
    std::cout << "Enter the letter of the English alphabet: ";
    char letter;
    std::cin >> letter;
    std::cout << checkCaseOfLetter(letter) << std::endl;
    
    return 0;
}

/**
    Reads text from a file and displays only bids consisting
    of a specified number of words.
*/

#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    std::ifstream textFile("text.txt");
    if (!textFile) {
        std::cerr << "File not found" << std::endl;
        return -1;
    }

    unsigned int wordsNumber, count = 0;
    std::cout << "Enter the number of words in the sentence: ";
    std::cin >> wordsNumber;

    std::string word, line;
    while (!textFile.eof()) {
        textFile >> word;
        line += word + " ";
        count++;

        if (word.find(".") != std::string::npos || 
            word.find("!") != std::string::npos)
        {
            if (count == wordsNumber) {
                std::cout << line << std::endl;
            }
            line = "";
            count = 0;
        }
    }
    return 0;
}
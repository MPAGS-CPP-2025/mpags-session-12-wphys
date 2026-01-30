#include "PlayfairCipher.hpp"

#include <algorithm>
#include <string>
#include <iostream>
/**
 * \file PlayfairCipher.cpp
 * \brief Contains the implementation of the PlayfairCipher class
 */

PlayfairCipher::PlayfairCipher(const std::string& key)
{
    this->setKey(key);
}

void PlayfairCipher::setKey(const std::string& key)
{
    // Store the original key
    key_ = key;

    // Append the alphabet to the key
    key_ += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Make sure the key is upper case
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);

    // Remove non-alphabet characters
    key_.erase(std::remove_if(key_.begin(), key_.end(), [](const char c) {
        return !std::isalpha(c);
    }), key_.end());

    
    // Change J -> I
    std::replace(key_.begin(), key_.end(), 'J', 'I');

    // Remove duplicated letters
    std::string encounteredLetters{""};
    key_.erase(std::remove_if(key_.begin(), key_.end(),
                   [&encounteredLetters](const char c) {
                       if (encounteredLetters.find(c) == std::string::npos) {
                           encounteredLetters += c;
                           return false;
                       }
                       return true;
                   }), key_.end());

    // Store the coordinates of each letter
    for (size_t i = 0; i < key_.size(); ++i)
    {
        const char c = key_[i];
        const int row = i / 5;
        const int col = i % 5;
        letterToCoords[c] = std::make_pair(row, col);
        coordsToLetter[std::make_pair(row, col)] = c;
    }
}

std::string PlayfairCipher::applyCipher(const std::string& inputText,
                                        const CipherMode /*cipherMode*/) const
{
    // Create the output string, initially a copy of the input text
    std::string outputText{inputText};

    // Change J -> I

    // Find repeated characters and add an X (or a Q for repeated X's)

    // If the size of the input is odd, add a trailing Z

    // Loop over the input bigrams

    // - Find the coordinates in the grid for each bigram

    // - Apply the rules to these coords to get new coords

    // - Find the letters associated with the new coords

    // - Make the replacements

    // Return the output text
    return outputText;
}

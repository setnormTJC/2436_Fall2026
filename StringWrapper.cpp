//
// Created by Work on 11/5/2026.
//

#include "StringWrapper.h"

#include<fstream>
#include<iostream>
#include <random>

// StringWrapper::StringWrapper(const std::string& baseString)
//     :
// mString(baseString)
// {
// }

std::string StringWrapper::encrypt() const
{
    std::mt19937 rng(std::random_device{}());

    // rand() %  26 //simpler alternative
    int minRandomNumber = 1;
    int maxRandomNumber = 26;

    std::uniform_int_distribution<int> distribution(minRandomNumber, maxRandomNumber);

    //int randomKey = distribution.operator()(rng); //the uniform_int_distribution class overloads ()
    int randomKey = distribution(rng);
    std::cout << "Random encryption key is: " << randomKey << std::endl;


    std::string encryptedText; //""  empty string initially

    for (int i = 0; i < mString.length(); ++i)
    {
        char encryptedChar = mString[i] + randomKey;
        encryptedText.push_back(encryptedChar);  //ex: if first letter is a and key is 3, this will push back 'd'
    }

    return encryptedText;//temporary crap
}

std::map<char, int> StringWrapper::getLetterFrequencyDistribution() const
{
    std::map<char, int> lettersToFrequencies =
    {
        {'a', 3},
        {'b', 3}
    };

    lettersToFrequencies['a']++;

    return lettersToFrequencies;
}

StringWrapper::StringWrapper() = default; //sets mString = ""

StringWrapper::StringWrapper(const std::string &filename)
{
    std::ifstream fin(filename);

    if (!fin)
    {
        std::cout << filename << " not found" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(fin, line))
    {
        mString += line;
    }

    fin.close();
}

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
    std::map<char, int> lettersToFrequencies;// =
    // {
    //     {'a', 3},
    //     {'b', 3}
    // };
    //
    // lettersToFrequencies['a']++;

    std::cout << "Number of characters in those 25K words is: " << mString.size() << std::endl;

    for (int i = 0; i < mString.size(); ++i)
    {
        char currentChar = mString[i];

        lettersToFrequencies[currentChar]++;
    }//end for

    return lettersToFrequencies;
}

void StringWrapper::printHistogram(const std::map<char, int> &letterFrequencyDistribution) const
{
    //asdfasdf
    for (const auto& currentPair : letterFrequencyDistribution)
    {
        std::cout << currentPair.first << " occurs this many times: " << currentPair.second << std::endl;
    }

    //scaling factor is to make sure the histogram formatting is "nice"
    int SCALING_FACTOR = INT_MAX; //I got this value just by scanning the particular 25K lexicon file!

    //SCALING_FACTOR = 1;

    //find MINIMUM key (pair.second) in the map
    for (const auto& currentPair : letterFrequencyDistribution)
    {
        if (currentPair.second < SCALING_FACTOR)
        {
            SCALING_FACTOR = currentPair.second;
        }
    }

    for (const auto& currentPair : letterFrequencyDistribution)
    {
        int scaledNumberOfOccurrences = currentPair.second/SCALING_FACTOR;
        std::cout << currentPair.first << ": ";
        //nested loop!
        for (int i = 0; i < scaledNumberOfOccurrences; ++i)
        {
            std::cout << "*";
        }
        std::cout << std::endl; //ex: a: 5 -> *****
    }
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

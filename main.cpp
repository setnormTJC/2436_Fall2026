#include <iostream>



#include"StringWrapper.h"

#include<queue>


std::map<char, int> getHistogram(const std::string& theString)
{
    std::map<char, int> histogram;

    for (int i = 0; i < theString.size(); ++i)
    {
        char currentCharacter = theString[i];
        histogram[currentCharacter]++; //adds one to the number of occurrences of the current character
    }


    return histogram;
}


int main()
{

    std::string filename ="../resources/prideAndPrejudiceSample.txt";
    //std::pair<std::string, int> personToAge = {"Chase", 28};

    filename = "../resources/25Klexicon.txt";

    StringWrapper stringWrapper(filename);

    // std::string cipherText = stringWrapper.encrypt(); //we'll continue this next time

    auto lettersToFrequencies = stringWrapper.getLetterFrequencyDistribution();

    //int dummyBreakPoint = 123;

    stringWrapper.printHistogram(lettersToFrequencies);
    //
    //std::string encryptedText = stringWrapper.encrypt();
    //
    //std::cout << encryptedText << std::endl;

    //auto histogram = getHistogram();

    //stringWrapper.printHistogram(histogram);

}

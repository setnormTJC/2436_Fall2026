#include <iostream>



#include"StringWrapper.h"

#include<queue>


int main()
{

    const std::string filename ="../resources/25Klexicon.txt";

    StringWrapper stringWrapper(filename);

    // std::string cipherText = stringWrapper.encrypt(); //we'll continue this next time

    auto lettersToFrequencies = stringWrapper.getLetterFrequencyDistribution();


}

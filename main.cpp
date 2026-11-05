#include <iostream>



#include"StringWrapper.h"

int main()
{
    // const std::string filename ="../resources/prideAndPrejudiceSample.txt";
    //
    // StringWrapper stringWrapper(filename);


    std::string plaintext = "aaabbb"; //we expect something like cccddd or zzz{{{

    StringWrapper stringWrapper(plaintext);

    std::string cipherText = stringWrapper.encrypt();

    //std::cout << "Ciphertext is: " << cipherText << std::endl;

    auto lettersToFrequencies = stringWrapper.getLetterFrequencyDistribution();





}

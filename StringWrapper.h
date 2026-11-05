//
// Created by Work on 11/5/2026.
//

#ifndef INC_2436_FALL2026_STRINGWRAPPER_H
#define INC_2436_FALL2026_STRINGWRAPPER_H

#include<map>
#include <string>

#include "matplot/util/concepts.h"


///@brief this class "wraps around" and extends the functionaltiy of std::string
class StringWrapper
{
private:
    ///@brief mString as in "member variable" string (this is called "Hungarian notation")
    std::string mString;

public:
    StringWrapper();

    //StringWrapper(const std::string& baseString);

    ///@param filename -> the file with which to construct the string <br>
    ///the private member variable <code>mString</code> gets filled with the content of the entire file
    StringWrapper(const std::string& filename);

    ///@brief takes the member variable <code> mString </code> and "Caesar shifts" it by a random number <br>
    ///between 1 and 26 (inclusive) with "wraparound" back to 'a' if the shift "exceeds" z
    std::string encrypt() const;

    std::map<char, int> getLetterFrequencyDistribution() const; //not going to modifiy mString
};


#endif //INC_2436_FALL2026_STRINGWRAPPER_H

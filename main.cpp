#include <iostream>

#include "MyStack.h"


int main()
{
    try
    {
        // int someArithmeticResult = (6 *7)/54;
        std::string someUnbalancedExpression = "((5 + 2)/4))";

        std::string theExpressionToCheckForBalance = someUnbalancedExpression;

        if (StackApplications::isBalanced(theExpressionToCheckForBalance))
        {
            std::cout << "The expression " << theExpressionToCheckForBalance << " IS balanced\n";
        }

        else
        {
            std::cout << theExpressionToCheckForBalance << " is NOT balanced :(\n";
        }



    }

    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

    return 0;
}

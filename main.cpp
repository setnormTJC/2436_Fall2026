#include <iostream>

#include "MyStack.h"


int main()
{
    try
    {
        // int someArithmeticResult = (6 *7)/54); //how is this checked?

        std::string unbalancedExpression1 = "((1 + 2)/3))"; //has an extra close )
        std::string unbalancedExpression2 = "((1 + 2)/3"; //has an extra open (
        std::string unbalancedExpression3 = "1 + 2)/3(";

        std::string balancedExpression1 =   "((1 + 2)/3)";
        std::string balancedExpression2 = "(1 + 2) * (3 + 4)";
        std::string balancedExpression3 = "";

        std::string theExpressionToCheckForBalance = unbalancedExpression3;

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

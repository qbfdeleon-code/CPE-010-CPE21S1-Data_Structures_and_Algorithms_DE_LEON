#include <iostream>
#include "ilo_c.h"

int main() {
    std::string expr;
    std::cout << "Enter an expression to check: ";
    std::getline(std::cin, expr);

    if (isBalanced(expr))
        std::cout << "The symbols are Balanced.\n";
    else
        std::cout << "The symbols are NOT Balanced.\n";

    return 0;
}
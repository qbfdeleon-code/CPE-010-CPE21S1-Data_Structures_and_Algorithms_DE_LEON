#ifndef STACK_STL_H
#define STACK_STL_H

#include <iostream>
#include <stack>

bool isOpening(char c) {
    return (c == '(' || c == '{' || c == '[');
}

bool isClosing(char c) {
    return (c == ')' || c == '}' || c == ']');
}

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool isBalanced(std::string expr) {
    std::stack<char> s; // Step 1

    for (int i = 0; i < expr.length(); i++) { // Step 2
        char c = expr[i];

        if (!isOpening(c) && !isClosing(c)) {
            continue; // a) ignore non-symbols
        }

        if (isOpening(c)) {
            s.push(c); // b) push opening symbol
        } else if (isClosing(c)) { // c) closing symbol
            if (s.empty()) {
                std::cout << "Error: Unmatched closing symbol '" << c << "'\n";
                return false;
            }
            char openChar = s.top();
            s.pop();
            if (!isMatchingPair(openChar, c)) {
                std::cout << "Error: Mismatched symbols '" << openChar
                          << "' and '" << c << "'\n";
                return false;
            }
        }
    }

    if (!s.empty()) { // Step 3
        std::cout << "Error: Unmatched opening symbol(s) remain\n";
        return false;
    }
    return true;
}

#endif
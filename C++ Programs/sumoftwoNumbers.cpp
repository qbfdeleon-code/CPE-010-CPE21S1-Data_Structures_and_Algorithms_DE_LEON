#include <iostream>

//function prototype.
int sumoftwoNumbers(int firstNum, int secondNum);

int main(){

    std:: cout << "The sum of 24 and 7 is " << sumoftwoNumbers(24, 7);

    return 0;
}

int sumoftwoNumbers(int firstNum, int secondNum){
    int total = firstNum + secondNum;
    return total;
}
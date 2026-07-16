#include <iostream>

void checkNum(int a, int b);

int main(){


   int num1; 
   int num2;

    for(int i=0; i<1; i++){
        std :: cout << "Enter a number: ";
        std:: cin >> num1;

        std :: cout << "Enter a number: ";
        std:: cin >> num2;

        checkNum(num1, num2);

    return 0;
}
   }



void checkNum(int a, int b){
    if (a < b){
        std:: cout << b << " is greater than " << a;
    }
    else if (a > b){
        std:: cout << a << " is greater than " << b;
    }
    else{
        std:: cout<< "Both numbers are equal.";
    }

}

#include <iostream>

//2.Create a C++ program that has a function to convert temperature in Kelvin to Fahrenheit. 
double kelvin_to_Fahrenheit(double K);

int main(){

    double K;

    std :: cout << "Enter Temperature (Kelvin): ";
    std :: cin >> K;

    kelvin_to_Fahrenheit(K);

    return 0;
}

double kelvin_to_Fahrenheit(double K){
    
    double fahrenheit = (K - 273.15) * 9/5 + 32;
    
    std:: cout << K << " in Kelvin is equal to " << fahrenheit << " Fahrenheit.\n";
    
    return fahrenheit;
}
#include <iostream>

bool display_logical_operators(bool a, bool b);  

int main(){

    bool a;
    bool b;    
      
    std:: cout << "Enter first boolean value(A): "; 
    std :: cin >> a;
    
    std :: cout << "Enter second boolean value(B): ";
    std:: cin >> b;    

    display_logical_operators(a, b);
    
    return 0;
}

bool display_logical_operators(bool a, bool b){

    std:: cout << "Logical AND: " << (a&&b);
    std:: cout << "\nLogical OR: " << (a||b);
    std:: cout << "\nLoogical NOT(A): " << (!a);
    std:: cout << "\nLoogical NOT(B): " << (!b);
    std:: cout << "\nLogical XOR: " << (a != b); 

    return true;

}


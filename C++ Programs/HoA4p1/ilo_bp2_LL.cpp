#include<iostream>
#include "ilo_bp2_LL.h"

int main(){

    std::cout<<"--- PUSHING 'c' 'p' 'e' ONTO THE STACK --- \n";

    push('c');
    push('p');
    push('e');
   
    displayAll<char>();
   
    Top<char>();

    std::cout<<"\n ------ Popping all the elements ------ \n";

    while(!isEmpty<char>()){
        std::cout<<"Popped: "<< pop<char>() <<std::endl;
    }

    std::cout<<"\n ----- Testing the Underflow ----- \n";
    pop<char>();

    return 0;
}

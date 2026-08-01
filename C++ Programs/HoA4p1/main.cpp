#include <iostream>>
#include <stack> // calling stack from the STL

int main(){
   //create an object for the stack
    std ::stack<int> newStack;

    std:: cout<<"Stack Empty? "<<newStack.empty()<<std:: endl;
    //push to the stack
    newStack.push(3);
    newStack.push(8);
    newStack.push(15);

    std:: cout<<"Stack Empty? "<<newStack.empty()<<std:: endl;
    std:: cout<< "The size if the stack: "<<newStack.size()<<std::endl;
    std:: cout << "The top of the element is: "<< newStack.top()<< std:: endl;
    std :: cout <<"Removing elements from the stack: \n";
    newStack.pop();
    std:: cout<< "The top of the element is: "<< newStack.top()<< std:: endl;
    newStack.pop();
    std:: cout<< "The top of the element is: "<< newStack.top()<< std:: endl;
    newStack.pop();
    std:: cout<<"Stack Empty? "<<newStack.empty()<<std:: endl;

    return 0;
}
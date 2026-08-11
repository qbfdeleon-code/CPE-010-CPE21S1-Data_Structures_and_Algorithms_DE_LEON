// ILO A: Create queue using C++ STL

#include <iostream>
#include <queue>

//prototype
void display(std::queue<char> r);

int main(){

    std::queue<char> q;
    
    //push
    q.push('c'); // front
    q.push('p');
    q.push('e');
    q.push('0');
    q.push('1');
    q.push('0'); // rear

    

    //empty()
    std::cout<<"Is the queue empty: " << q.empty()<<std::endl;

    //size
    std::cout<<"Size of the queue: "<< q.size()<<std::endl;

    //front
    std::cout<< "Front of the queue: "<<q.front()<<std::endl; // front
    
    //back
    std::cout<<"Back of the queue: "<<q.back()<<std::endl;

    //pop
    std::cout<<"Pop: ";
    q.pop();

    //push another element
    std::cout<< "Push another element: ";
    q.push('b'); 
    
    //dislpay
    std::cout<<"Displaying element/s: ";
    display(q);

    //delete the queue
    while(!q.empty()){
        q.pop();
    }

}


void display(std::queue<char> r){
    // crete a copy of the queue
    std::queue<char> c = r;

    while(!c.empty()){
        std::cout << " "<<c.front();
        c.pop();
    }
    std::cout<<"\n";
}
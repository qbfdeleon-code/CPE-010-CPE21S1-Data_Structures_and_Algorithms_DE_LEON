#include <iostream>
#include <cmath>

//3.Create a C++ program that has a function that will calculate the distance between two points
double distance(double x1, double y1, double x2, double y2);

int main(){

    std::cout << "The distance is: " << distance(5, 23, 9, 5) << "\n";

    return 0;
}

double distance(double x1, double y1, double x2, double y2){
    double dx = x2 - x1;
    double dy = y2 - y1;
    
    return sqrt(dx*dx + dy*dy);
}
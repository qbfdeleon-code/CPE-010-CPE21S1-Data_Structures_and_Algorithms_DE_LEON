#include <iostream>
#include <cmath> 

//class name should follow PascalCase
class Triangle{
    private:
        double totalAngle, angleA, angleB, angleC;
    public:
    //constructor
        Triangle(double A, double B, double C);

    //methods
        void setAngles(double A, double B, double C);

    //validation
    const bool validateTriangle();

    double computePerimeter();
    double computeArea();
    std::string determineAngleType();
};

int main(){

    //driver code
    Triangle set1(40, 30, 110); 
    if(set1.validateTriangle()){
        std:: cout << "The shape is a valid triangle" << std:: endl;
        
        std:: cout << "Perimeter (scaled): " << set1.computePerimeter() << std:: endl;
        std:: cout << "Area (scaled): " << set1.computeArea() << std:: endl;
        std:: cout << "Triangle Type: " << set1.determineAngleType() << std:: endl;
    }else{
        std:: cout <<"The shape  is NOT a valid triangle. \n";
    }

    return 0;
}

Triangle:: Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}

const bool Triangle::validateTriangle() {
    return (totalAngle == 180 && angleA > 0 && angleB > 0 && angleC > 0);
}

double Triangle::computePerimeter() {
    double radA = angleA * M_PI / 180.0;
    double radB = angleB * M_PI / 180.0;
    double radC = angleC * M_PI / 180.0;

    double sideA = std::sin(radA);
    double sideB = std::sin(radB);
    double sideC = std::sin(radC);

    return sideA + sideB + sideC;
}

double Triangle::computeArea() {
    double radA = angleA * M_PI / 180.0;
    double radB = angleB * M_PI / 180.0;
    double radC = angleC * M_PI / 180.0;

    double sideA = std::sin(radA);
    double sideB = std::sin(radB);

    return 0.5 * sideA * sideB * std::sin(radC);
}

std::string Triangle::determineAngleType() {
    if (angleA > 90 || angleB > 90 || angleC > 90) {
        return "Obtuse-angled";
    }
    else if (angleA == 90 || angleB == 90 || angleC == 90) {
        return "Others (Right-angled)";
    }
    else {
        return "Acute-angled";
    }
}
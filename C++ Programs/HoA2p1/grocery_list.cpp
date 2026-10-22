#include <iostream>
#include <string>

// Fruit class
class Fruit {
public: 
    std::string name;
    double price;      // (PHP)
    int quantity;

    // Constructor
    Fruit(std::string n = "", double p = 0.0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
        std::cout << "Fruit created: " << name << std::endl;
    }

    // Copy Constructor
    Fruit(const Fruit &other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
        std::cout << "Fruit Copied: " << name << std::endl;
    }

    // Copy Assignment Operator
    Fruit& operator=(const Fruit &other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
            std::cout << "Fruit assigned: " << name << std::endl;
        }
        return *this;
    }

    // Destructor
    ~Fruit() {
        std::cout << "Fruit deleted: " << name << std::endl;
    }

    double calculateSum() {
        return price * quantity;
    }

    void display() {
        std::cout << "  [Fruit] " << name
             << " | Price: PHP " << price
             << " | Qty: " << quantity
             << " | Subtotal: PHP " << calculateSum() << std::endl;
    }
};

// Vegetable class
class Vegetable {
public:
    std::string name;
    double price;
    int quantity;

    // Constructor
    Vegetable(std::string n = "", double p = 0.0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
        std::cout << "Vegetable created: " << name << std::endl;
    }

    // Copy Constructor
    Vegetable(const Vegetable &other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
        std::cout << "Vegetable copied: " << name << std::endl;
    }

    // Copy Assignment Operator
    Vegetable& operator=(const Vegetable &other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
            std::cout << "Vegetable assigned: " << name << std::endl;
        }
        return *this;
    }

    // Destructor
    ~Vegetable() {
        std::cout << "Vegetable deleted: " << name << std::endl;
    }

    double calculateSum() {
        return price * quantity;
    }

    void display() {
        std::cout << "  [Vegetable] " << name
             << " | Price: PHP " << price
             << " | Qty: " << quantity
             << " | Subtotal: PHP " << calculateSum() << std::endl;
    }
};

// Total sum calculation helper
double Total_sum(Fruit* fruitList[], int fruitSize, Vegetable* vegList[], int vegSize) {
    double total = 0.0;

    for (int i = 0; i < fruitSize; i++) {
        if (fruitList[i] != nullptr) {
            total += fruitList[i]->calculateSum();
        }
    }

    for (int i = 0; i < vegSize; i++) {
        if (vegList[i] != nullptr) {
            total += vegList[i]->calculateSum();
        }
    }

    return total;
}

int main() {
    // Allocation
    Fruit* fruitList[2];
    fruitList[0] = new Fruit("Apple", 10, 7);
    fruitList[1] = new Fruit("Banana", 10, 8);

    Vegetable* vegList[2];
    vegList[0] = new Vegetable("Broccoli", 60, 12);
    vegList[1] = new Vegetable("Lettuce", 50, 10);

    // Initial Display
    std::cout << "\nJenna's Grocery List:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (fruitList[i] != nullptr) fruitList[i]->display();
    }
    for (int i = 0; i < 2; i++) {
        if (vegList[i] != nullptr) vegList[i]->display();
    }

    std::cout << "\nTotal: PHP " << Total_sum(fruitList, 2, vegList, 2) << std::endl;

    // Delete Lettuce from list and safely de-allocate memory
    std::cout << "\nRemoving Lettuce:" << std::endl;
    delete vegList[1];       
    vegList[1] = nullptr;    

    // Display list after removal
    std::cout << "\nJenna's Grocery List (Updated):" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (fruitList[i] != nullptr) fruitList[i]->display();
    }
    for (int i = 0; i < 2; i++) {
        if (vegList[i] != nullptr) vegList[i]->display();
    }

    std::cout << "\nTotal (after removing Lettuce): PHP " << Total_sum(fruitList, 2, vegList, 2) << std::endl;

    //Memory de-allocation.
    std::cout << "\nProgram terminating. Cleaning remaining memory:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (fruitList[i] != nullptr) {
            delete fruitList[i];
            fruitList[i] = nullptr;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (vegList[i] != nullptr) {
            delete vegList[i];
            vegList[i] = nullptr;
        }
    }


    return 0;
}

#include <iostream>
#include <string>
using namespace std;

// Component
class Coffee {
public:
    virtual string getDescription() = 0;
    virtual double getCost() = 0;
    virtual ~Coffee() {}
};

// Concrete Component
class SimpleCoffee : public Coffee {
public:
    string getDescription() override { return "Simple Coffee"; }
    double getCost() override { return 5.0; }
};

// Base Decorator
class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;
public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}
};

// Concrete Decorators
class Milk : public CoffeeDecorator {
public:
    Milk(Coffee* c) : CoffeeDecorator(c) {}
    string getDescription() override { return coffee->getDescription() + ", Milk"; }
    double getCost() override { return coffee->getCost() + 1.5; }
};

class Sugar : public CoffeeDecorator {
public:
    Sugar(Coffee* c) : CoffeeDecorator(c) {}
    string getDescription() override { return coffee->getDescription() + ", Sugar"; }
    double getCost() override { return coffee->getCost() + 0.5; }
};

// Client
int main() {
    Coffee* myCoffee = new SimpleCoffee();
    cout << myCoffee->getDescription() << " $" << myCoffee->getCost() << endl;

    myCoffee = new Milk(myCoffee);
    myCoffee = new Sugar(myCoffee);

    cout << myCoffee->getDescription() << " $" << myCoffee->getCost() << endl;

    delete myCoffee;
    return 0;
}

// Output:
// Simple Coffee $5
// Simple Coffee, Milk, Sugar $7


// Problems with this approach:

// Code duplication everywhere (each new class repeats base logic).

// Explosion of subclasses — for n toppings you need 2^n classes.
// 3 toppings → 8 classes (like above).
// 5 toppings → 32 classes.
// 10 toppings → 1024 classes.

// Hard to maintain: if you change base price, you must update every subclass.
// Not flexible: you can’t decide toppings at runtime.

#include <iostream>
#include <string>
using namespace std;

// ---------------- Base Coffee ----------------
class SimpleCoffee {
public:
    string getDescription() { return "Simple Coffee"; }
    double getCost() { return 5.0; }
};

// ---------------- Single Add-ons ----------------
class MilkCoffee : public SimpleCoffee {
public:
    string getDescription() { return "Simple Coffee + Milk"; }
    double getCost() { return 6.5; }   // 5.0 + 1.5
};

class SugarCoffee : public SimpleCoffee {
public:
    string getDescription() { return "Simple Coffee + Sugar"; }
    double getCost() { return 5.5; }   // 5.0 + 0.5
};

class WhippedCreamCoffee : public SimpleCoffee {
public:
    string getDescription() { return "Simple Coffee + Whipped Cream"; }
    double getCost() { return 6.0; }   // 5.0 + 1.0
};

// ---------------- Double Add-ons ----------------
class MilkSugarCoffee : public SimpleCoffee {
public:
    string getDescription() { return "Simple Coffee + Milk + Sugar"; }
    double getCost() { return 7.0; }   // 5.0 + 1.5 + 0.5
};

class MilkWhippedCreamCoffee : public SimpleCoffee {
public:
    string getDescription() { return "Simple Coffee + Milk + Whipped Cream"; }
    double getCost() { return 7.5; }   // 5.0 + 1.5 + 1.0
};

class SugarWhippedCreamCoffee : public SimpleCoffee {
public:
    string getDescription() { return "Simple Coffee + Sugar + Whipped Cream"; }
    double getCost() { return 6.5; }   // 5.0 + 0.5 + 1.0
};

// ---------------- Triple Add-ons ----------------
class MilkSugarWhippedCreamCoffee : public SimpleCoffee {
public:
    string getDescription() { return "Simple Coffee + Milk + Sugar + Whipped Cream"; }
    double getCost() { return 8.0; }   // 5.0 + 1.5 + 0.5 + 1.0
};

// ---------------- Main ----------------
int main() {
    SimpleCoffee base;
    cout << base.getDescription() << " $" << base.getCost() << endl;

    MilkCoffee milk;
    cout << milk.getDescription() << " $" << milk.getCost() << endl;

    SugarCoffee sugar;
    cout << sugar.getDescription() << " $" << sugar.getCost() << endl;

    WhippedCreamCoffee cream;
    cout << cream.getDescription() << " $" << cream.getCost() << endl;

    MilkSugarCoffee milkSugar;
    cout << milkSugar.getDescription() << " $" << milkSugar.getCost() << endl;

    MilkWhippedCreamCoffee milkCream;
    cout << milkCream.getDescription() << " $" << milkCream.getCost() << endl;

    SugarWhippedCreamCoffee sugarCream;
    cout << sugarCream.getDescription() << " $" << sugarCream.getCost() << endl;

    MilkSugarWhippedCreamCoffee combo;
    cout << combo.getDescription() << " $" << combo.getCost() << endl;

    return 0;
}

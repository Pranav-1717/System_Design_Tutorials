#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Product Interface
class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

// Concrete Products
class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Burger with bun and patty." << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce." << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Burger with gourmet bun, double patty, and special sauce." << endl;
    }
};

// Simple Factory
class BurgerFactory {
public:
    static unique_ptr<Burger> createBurger(const string& type) {
        if (type == "Basic") return make_unique<BasicBurger>();
        if (type == "Standard") return make_unique<StandardBurger>();
        if (type == "Premium") return make_unique<PremiumBurger>();
        throw invalid_argument("Invalid burger type");
    }
};

// Client Code
int main() {
    auto burger = BurgerFactory::createBurger("Standard");
    burger->prepare();
}
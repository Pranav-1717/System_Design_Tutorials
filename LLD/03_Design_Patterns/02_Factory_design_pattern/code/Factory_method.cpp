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

// Normal Burgers
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

// Wheat Burgers
class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Wheat Burger with whole wheat bun and patty." << endl;
    }
};

class StandardWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Wheat Burger with whole wheat bun, patty, cheese, and lettuce." << endl;
    }
};

// Abstract Factory
class BurgerFactory {
public:
    virtual unique_ptr<Burger> createBurger(const string& type) = 0;
    virtual ~BurgerFactory() = default;
};

// Concrete Factory 1: SyncBurger
class SyncBurgerFactory : public BurgerFactory {
public:
    unique_ptr<Burger> createBurger(const string& type) override {
        if (type == "Basic") return make_unique<BasicBurger>();
        if (type == "Standard") return make_unique<StandardBurger>();
        throw invalid_argument("Invalid burger type for SyncBurger");
    }
};

// Concrete Factory 2: KingBurger
class KingBurgerFactory : public BurgerFactory {
public:
    unique_ptr<Burger> createBurger(const string& type) override {
        if (type == "Basic") return make_unique<BasicWheatBurger>();
        if (type == "Standard") return make_unique<StandardWheatBurger>();
        throw invalid_argument("Invalid burger type for KingBurger");
    }
};

// Client Code
int main() {
    unique_ptr<BurgerFactory> factory = make_unique<KingBurgerFactory>();
    auto burger = factory->createBurger("Basic");
    burger->prepare();
}

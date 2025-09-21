#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Product Interfaces
class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

class GarlicBread {
public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() = default;
};

// Concrete Burgers
class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Burger with bun and patty." << endl;
    }
};

class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Wheat Burger with whole wheat bun and patty." << endl;
    }
};

// Concrete Garlic Breads
class BasicGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Basic Garlic Bread." << endl;
    }
};

class BasicWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Basic Wheat Garlic Bread." << endl;
    }
};

// Abstract Meal Factory
class MealFactory {
public:
    virtual unique_ptr<Burger> createBurger() = 0;
    virtual unique_ptr<GarlicBread> createGarlicBread() = 0;
    virtual ~MealFactory() = default;
};

// Concrete Factory 1: SyncBurger
class SyncMealFactory : public MealFactory {
public:
    unique_ptr<Burger> createBurger() override {
        return make_unique<BasicBurger>();
    }
    unique_ptr<GarlicBread> createGarlicBread() override {
        return make_unique<BasicGarlicBread>();
    }
};

// Concrete Factory 2: KingBurger
class KingMealFactory : public MealFactory {
public:
    unique_ptr<Burger> createBurger() override {
        return make_unique<BasicWheatBurger>();
    }
    unique_ptr<GarlicBread> createGarlicBread() override {
        return make_unique<BasicWheatGarlicBread>();
    }
};

// Client Code
int main() {
    unique_ptr<MealFactory> factory = make_unique<KingMealFactory>();
    auto burger = factory->createBurger();
    auto bread = factory->createGarlicBread();

    burger->prepare();
    bread->prepare();
}

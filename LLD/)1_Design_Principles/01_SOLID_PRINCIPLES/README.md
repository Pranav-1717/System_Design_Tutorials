# SOLID Principles in Object-Oriented Design
The SOLID principles are five fundamental guidelines in object-oriented design that help make code maintainable, scalable, and flexible. They reduce tight coupling between classes, making your code easier to test and reuse.

- **S** -> Single Responsibility Principle (SRP)
- **O** -> Open/Close principle (OCP)
- **L** -> Liskov's Substitution Principle (LSP)
- **I** -> Interface Segregation Principle (ISP)
- **D** -> Dependency Inversion Principle (DIP)

## Why SOLID Principles?
- **Maintainability**: Easier to locate and modify code without affecting unrelated parts.  
- **Extensibility**: Add new features without changing existing code.  
- **Flexibility**: Swap components easily by depending on abstractions.  
- **Reusability**: Loosely coupled classes can be reused in other projects or modules.  

## 1. Single Responsibility Principle (SRP)
**A class should have only one reason to change.**<br>

**Example** :
A baker should focus only on baking bread. Tasks like managing inventory, serving customers, or cleaning the bakery should be handled by separate roles.

```c++
#include <iostream>

class BreadBaker {
public:
    void bakeBread() { std::cout << "Baking bread...\n"; }
};

class InventoryManager {
public:
    void manageInventory() { std::cout << "Managing inventory...\n"; }
};

class CustomerService {
public:
    void serveCustomer() { std::cout << "Serving customer...\n"; }
};

int main() {
    BreadBaker baker;
    InventoryManager inventory;
    CustomerService service;

    baker.bakeBread();
    inventory.manageInventory();
    service.serveCustomer();

    return 0;
}
```
Explanation of the Code:

BreadBaker Class: Handles only baking bread. Adheres to SRP by having a single responsibility.

InventoryManager Class: Manages inventory independently, so changes in inventory logic do not affect baking logic.

CustomerService Class: Handles customer interactions separately.

Main Function: Demonstrates that each class focuses on its specific responsibility without overlap.

## 2. Open/Closed Principle (OCP)
**Software entities should be open for extension but closed for modification.**

A payment system initially supports only credit cards. Later, PayPal support can be added by extending the system without modifying existing code.

```c++
#include <iostream>

class PaymentProcessor {
public:
    virtual void processPayment(double amount) = 0;
};

class CreditCardProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        std::cout << "Processing credit card payment: $" << amount << "\n";
    }
};

class PayPalProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override {
        std::cout << "Processing PayPal payment: $" << amount << "\n";
    }
};

void makePayment(PaymentProcessor* processor, double amount) {
    processor->processPayment(amount);
}

int main() {
    CreditCardProcessor cc;
    PayPalProcessor pp;

    makePayment(&cc, 100.0);
    makePayment(&pp, 150.0);

    return 0;
}
```
Explanation of the Code:

PaymentProcessor Class: Abstract base class providing a common interface for all payment processors.

CreditCardProcessor Class: Implements credit card payments.

PayPalProcessor Class: Extends functionality without modifying the base class, adhering to OCP.

makePayment Function: Accepts any PaymentProcessor object, demonstrating that new processors can be added without modifying existing code.

## 3. Liskov Substitution Principle (LSP)
**Subtypes must be substitutable for their base types without altering expected behavior.**

A rectangle can have independent width and height. A square is a rectangle with equal sides. Using a square in place of a rectangle can break code that expects width and height to be independent.

```c++
#include <iostream>

class Rectangle {
protected:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    virtual double area() const { return width * height; }
    virtual void setWidth(double w) { width = w; }
    virtual void setHeight(double h) { height = h; }
};

class Square : public Rectangle {
public:
    Square(double size) : Rectangle(size, size) {}
    void setWidth(double w) override { width = height = w; }
    void setHeight(double h) override { width = height = h; }
};
```
Explanation of the Code:

Rectangle Class: Base class with width, height, and area calculation. Allows independent changes to width and height.

Square Class: Inherits from Rectangle but overrides setters to keep width and height equal.

LSP Violation Risk: If a Square is used where a Rectangle is expected, modifying width or height independently may produce unexpected behavior.

## 4. Interface Segregation Principle (ISP)
**Do not force classes to depend on interfaces they do not use.**

A vegetarian customer should receive only a vegetarian menu, not non-vegetarian items.

```c++
#include <iostream>
#include <vector>
#include <string>

class IVegetarianMenu {
public:
    virtual std::vector<std::string> getVegetarianItems() = 0;
};

class INonVegetarianMenu {
public:
    virtual std::vector<std::string> getNonVegetarianItems() = 0;
};

class VegetarianMenu : public IVegetarianMenu {
public:
    std::vector<std::string> getVegetarianItems() override {
        return {"Paneer Curry", "Veg Sandwich"};
    }
};

class NonVegetarianMenu : public INonVegetarianMenu {
public:
    std::vector<std::string> getNonVegetarianItems() override {
        return {"Chicken Curry", "Fish Fry"};
    }
};

void showVegetarianMenu(IVegetarianMenu* menu) {
    for (auto &item : menu->getVegetarianItems())
        std::cout << "- " << item << "\n";
}
```

## 5. Dependency Inversion Principle (DIP)
**High-level modules should depend on abstractions, not concrete implementations.**

Developers rely on an abstract version control system rather than knowing the details of Git.

```c++
#include <iostream>
#include <string>

class IVersionControl {
public:
    virtual void commit(const std::string& msg) = 0;
};

class Git : public IVersionControl {
public:
    void commit(const std::string& msg) override {
        std::cout << "Git commit: " << msg << "\n";
    }
};

class Developer {
    IVersionControl* vcs;
public:
    Developer(IVersionControl* v) : vcs(v) {}
    void makeCommit(const std::string& msg) { vcs->commit(msg); }
};

int main() {
    Git git;
    Developer dev(&git);
    dev.makeCommit("Initial commit");
    return 0;
} 
```

Explanation of the Code:

IVersionControl Interface: Provides an abstraction for version control operations.

Git Class: Concrete implementation of version control.

Developer Class: Depends on the interface (IVersionControl) rather than the concrete Git class.

Main Function: Demonstrates that the developer can work with any version control system implementing the interface.



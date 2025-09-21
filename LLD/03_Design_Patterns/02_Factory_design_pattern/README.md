# Factory Design Pattern
The **Factory Design Pattern** provides a dedicated **factory class** whose job is to create objects.  
Think of it like a real factory that produces different products — in software, the factory produces different objects.

### Why use it?
- Your code doesn’t need to know **how** an object is created, only that it can **request** one from the factory.
- It separates **business logic** from **object creation logic**.
- This makes your code **cleaner, modular, and easier to maintain**.

---
### The Three Flavors of Factory
The Factory Design Pattern isn't a one-size-fits-all solution; it comes in three main variations, each addressing different levels of complexity and abstraction:
- Simple Factory
- Factory Method
- Abstract Factory Method

---
### 1. Simple factory:
The Simple Factory is the most straightforward implementation. It involves a single factory class that decides which concrete class to instantiate based on a given type or parameter.

**Real-World Scenario:** The Burger Shop
Consider a burger shop that offers different types of burgers: Basic, Standard, and Premium . Instead of the customer (client) directly creating each burger type, a BurgerFactory handles the creation process.


![Simple factory](./assests/Simple%20Factory%20Burger%20Creation.png)

In this setup, the BurgerFactory has a createBurger method that takes a type (e.g., "Basic", "Standard", "Premium") and returns the corresponding Burger object. The client doesn't need to know the new keyword or the specific class names; it just asks the factory for a burger of a certain type.

---
### 2. Factory method
While the Simple Factory is useful, it can become rigid if the object creation logic itself needs to vary. The Factory Method pattern addresses this by defining an interface for creating objects, but allowing subclasses to decide which class to instantiate. This introduces an abstraction layer on the factory side, similar to the abstraction on the product side.

Real-World Scenario: Expanding the Burger Empire with Franchises
Imagine our burger shop expands into two distinct franchises: SyncBurger and KingBurger.
- SyncBurger makes normal burgers (Basic, Standard, Premium) .
- KingBurger specializes in healthier, wheat-based burgers (Basic Wheat, Standard Wheat, Premium Wheat).

Here, BurgerFactory becomes an abstract class with an abstract createBurger method. Both SyncBurger and KingBurger are concrete factory subclasses that override createBurger to produce their specific types of burgers.


![Factory method](./assests/Factory%20Method%20Burger%20Creation.png)

The client now decides which factory to use (e.g., new KingBurger()) and then calls its createBurger method. This allows for dynamic, polymorphic object creation based on the chosen factory.

---

### 3. Abstract Factory Method:
The Abstract Factory Method takes abstraction a step further. It provides an interface for creating families of related objects without specifying their concrete classes. This means a single factory can be responsible for creating multiple types of products.

Real-World Scenario: The Full Meal Deal
What if our SyncBurger and KingBurger franchises don't just sell burgers, but also offer garlic bread? Now, each factory needs to create both a burger and a garlic bread, potentially in different styles (normal vs. wheat-based).

Our MealFactory (which is abstract) would now have two abstract methods: createBurger and createGarlicBread s . The concrete factories (SyncBurger and KingBurger) would implement both methods, ensuring that if you choose KingBurger, you get a wheat-based burger and wheat-based garlic bread.

![Factory method](./assests/Abstract%20Factory%20Meal%20Creation.png)

This pattern is incredibly useful when you need to ensure that all products created by a particular factory belong to a consistent "family" or theme.

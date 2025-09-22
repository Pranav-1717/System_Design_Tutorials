# Strategy Design Pattern

Imagine you're building an application, and like any good software, it's going to evolve.  
New features will pop up, and existing ones might need to change.  

The key to surviving this constant change is **flexibility in your code design**.  
That's exactly what the **Strategy Design Pattern** helps you achieve.

---

## What is Strategy Design Pattern?

At its core, the Strategy Design Pattern is about:

- Defining a **family of algorithms**
- Encapsulating each one
- Making them **interchangeable**

This means you can swap out different behaviors at runtime,  
giving your application incredible adaptability.

---

## The Problem: When Inheritance Becomes a Trap
You're building a robot simulation. All robots can walk() and talk(), but some can also fly(). Naturally, your first thought might be to use inheritance:
```bash
Robot
├── CompanionRobot (walk, talk)
└── SparrowRobot (walk, talk, fly)
```

Looks good, right? But then, requirements change. Now you have CrowRobot (also flies with wings) and JetRobot (flies with jets). If you keep adding flyWithWings() and flyWithJet() methods directly into subclasses, you'll quickly run into problems:

1. Code Duplication (DRY Violation)
   - The code for `flyWithWings()` would be identical in **SparrowRobot** and **CrowRobot**.
   - This breaks the **Do Not Repeat Yourself (DRY)** principle.

2. Exploding Class Hierarchy
   - To avoid duplication, you might create more layers of inheritance:
     - `FlyableRobot`
     - `FlyWithWingsRobot`
     - `FlyWithJetRobot`
   - Now imagine also adding "non-walkable" or "non-talkable" behaviors…
     Your inheritance tree quickly becomes a **nightmare of permutations and combinations**.



3.  Breaking the Open/Closed Principle
Every time you introduce a new flying method or behavior:
    - You must **modify existing classes**, or  
    - Add **new ones deep in the hierarchy**.  

    This violates the **Open/Closed Principle**:  
    > Code should be **open for extension but closed for modification**.

---
## How strategy design pattern solve problem
It tells us to **"favor composition over inheritance"**<br>
Instead of inheriting behaviors, an object has behaviors.

### 1. Identify What Changes: 
The walk, talk, and fly behaviors are what change from robot to robot. The projection (how a robot looks) is unique to each robot type but doesn't change its behavior in the same way.

### 2. Create Strategy Interfaces: 
We define interfaces (or abstract classes) for each varying behavior. These are our "strategies".
- Talkable (with a talk() method)
- Walkable (with a walk() method)
- Flyable (with a fly() method)

### 3. Implement Concrete Strategies: 
For each interface, we create concrete classes that implement the specific ways a behavior can be performed.
- For Talkable: NormalTalk, NoTalk.
- For Walkable: NormalWalk, NoWalk.
- For Flyable: NormalFly, NoFly, FlyWithJet (for our new jet-powered robots!).

### 4. The Context (Robot) Class: 
Our Robot class now becomes the "context." It doesn't know how to talk, walk, or fly itself. Instead, it holds references to objects of type Talkable, Walkable, and Flyable.


``` 
          <<interface>>                 <<interface>>                 <<interface>>
          WalkableRobot                TalkableRobot                 FlyableRobot
          + walk() : void               + talk() : void              + fly() : void
                ^                            ^                          ^
                |                            |                          |
        -----------------            -----------------            -----------------
        |               |            |               |            |               |
    NormalWalk        NoWalk     NormalTalk        NoTalk     NormalFly          NoFly
    + walk()           + walk()    + talk()         + talk()    + fly()           + fly()

                                -------------------
                                |      Robot       |
                                -------------------
                                - walkBehavior : WalkableRobot*
                                - talkBehavior : TalkableRobot*
                                - flyBehavior  : FlyableRobot*
                                -------------------
                                + Robot(w,t,f)
                                + walk() : void
                                + talk() : void
                                + fly() : void
                                + projection() : void <<abstract>>
                                        ^
                                        |
                         ------------------------------
                         |                            |
                 CompanionRobot                 WorkerRobot
                 + projection()                 + projection()

```

---

## Standard UML Diagram For Strategy Design Pattern

![Strategy design pattern](./assests/Strategy%20Design%20Pattern%20UML.png)

--- 
## Strategy Pattern Examples

###  Payment Gateways
 
An e-commerce site needs to support various payment methods like:

- Credit Card  
- PayPal  
- Apple Pay  
- UPI  

Each method has its own processing logic.

**How:**  
- Create a `PaymentProcessor` class (Context)  
- Define a `PaymentStrategy` interface  
- Implement concrete strategies: `CreditCardPaymentStrategy`, `UpiPaymentStrategy`, etc.  
- When a user selects a payment method, the `PaymentProcessor` is configured with the corresponding strategy, making payment processing flexible and interchangeable.

---
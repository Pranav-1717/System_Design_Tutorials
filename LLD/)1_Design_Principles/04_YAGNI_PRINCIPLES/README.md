# YAGNI Principle — You Aren’t Gonna Need It

“Don’t build a parachute when you’re just riding a bicycle.”

The YAGNI principle says:<br>
Only build what you need right now.<br>
Don’t waste time coding “future features” that might be useful someday.

Your team is asked to build a basic calculator with add and subtract.
But your brain goes:

“Hmm, what if tomorrow they want square roots, logs, trigonometry, matrix operations, and a spaceship control panel? I should prepare!”

So you write this monster:
```c++
#include <iostream>
#include <cmath>
using namespace std;

class Calculator {
public:
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }

    // Not required but “future-proofing”
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) { return b != 0 ? a / b : 0; }
    double sqrtVal(double a) { return sqrt(a); }
    double logVal(double a) { return log(a); }
    double sinVal(double a) { return sin(a); }
    double cosVal(double a) { return cos(a); }
    // and so on...
};
```


Half of that code may never get used, but will still:<br>
    Waste time writing & testing<br>
    Add bugs to maintain<br>
    Confuse future developers<br>

## YAGNI Approach

Build only what’s needed today:
```c++
#include <iostream>
using namespace std;

class Calculator {
public:
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
};
```
Done. Ship it. 
If one day your boss actually asks for sqrt(), add it then — not before.

## How to Apply YAGNI

- Focus on current requirements only

- Say “no” to “nice-to-haves” unless critical

- Build small, extend later if needed

- Keep the codebase clean and focused
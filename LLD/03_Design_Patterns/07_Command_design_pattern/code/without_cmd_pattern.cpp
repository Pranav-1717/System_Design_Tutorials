#include <iostream>
#include <string>
using namespace std;

// Receiver classes (actual devices)
class Light {
public:
    void on() { cout << "Light is ON\n"; }
    void off() { cout << "Light is OFF\n"; }
};

class TV {
public:
    void on() { cout << "TV is ON\n"; }
    void off() { cout << "TV is OFF\n"; }
};

// Invoker class (Remote)
class RemoteControl {
public:
    void pressButton(string device, string action) {
        if (device == "light") {
            if (action == "on") light.on();
            else if (action == "off") light.off();
        } else if (device == "tv") {
            if (action == "on") tv.on();
            else if (action == "off") tv.off();
        }
    }

private:
    Light light;
    TV tv;
};

int main() {
    RemoteControl remote;
    remote.pressButton("light", "on");
    remote.pressButton("tv", "off");
    return 0;
}


// Output:
// Light is ON
// TV is OFF


// ---Limitations:---
// 1. Adding new devices requires modifying the RemoteControl class.
// 2. Adding new actions (like dimming the light) requires modifying the RemoteControl class.
// 3. The RemoteControl class becomes bloated with if-else statements as more devices and actions are added.
// 4. No support for undo/redo functionality.
// 5. Violates the Open/Closed Principle (OCP) of SOLID principles.
// 6. Difficult to extend and maintain as the system grows.
// 7. Tight coupling between the invoker and receiver classes.
// 8. No support for queuing or scheduling commands.
// 9. Hard to implement logging or auditing of actions.
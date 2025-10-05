#include <iostream>
#include <stack>
using namespace std;


// --- Receiver classes (actual devices) ---
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

// --- Command interface ---
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() {}
};

// --- Concrete Command classes ---
class LightOnCommand : public Command {
    Light* light;
public:
    LightOnCommand(Light* l) : light(l) {}
    void execute() override { light->on(); }
    void undo() override { light->off(); }
};

class LightOffCommand : public Command {
    Light* light;
public:
    LightOffCommand(Light* l) : light(l) {}
    void execute() override { light->off(); }
    void undo() override { light->on(); }
};

class TVOnCommand : public Command {
    TV* tv;
public:
    TVOnCommand(TV* t) : tv(t) {}
    void execute() override { tv->on(); }
    void undo() override { tv->off(); }
};

class TVOffCommand : public Command {
    TV* tv;
public:
    TVOffCommand(TV* t) : tv(t) {}
    void execute() override { tv->off(); }
    void undo() override { tv->on(); }
};


// --- Invoker class (Remote) ---
class RemoteControl {
    Command* command;
    stack<Command*> history;
public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void pressButton() {
        command->execute();
        history.push(command);
    }

    void pressUndo() {
        if (!history.empty()) {
            Command* lastCommand = history.top();
            history.pop();
            lastCommand->undo();
        }
    }
};

// --- Client code ---
int main() {
    Light light;
    TV tv;

    LightOnCommand lightOn(&light);
    LightOffCommand lightOff(&light);
    TVOnCommand tvOn(&tv);
    TVOffCommand tvOff(&tv);

    RemoteControl remote;

    // Turn ON the light
    remote.setCommand(&lightOn);
    remote.pressButton();

    // Turn OFF the TV
    remote.setCommand(&tvOff);
    remote.pressButton();

    // Undo last action
    remote.pressUndo();

    // Turn OFF the light
    remote.setCommand(&lightOff);
    remote.pressButton();

    // Undo light OFF (turn ON again)
    remote.pressUndo();

    return 0;
}

// Output:
// Light is ON 
// TV is OFF
// TV is ON
// Light is OFF
// Light is ON

// ---Advantages:---
// 1. Decouples the invoker (RemoteControl) from the receiver (Light, TV).
// 2. Easy to add new devices and commands without modifying existing code.
// 3. Supports undo functionality.
// 4. Adheres to the Open/Closed Principle (OCP) of SOLID principles.
// 5. Commands can be queued, logged, or scheduled.
// 6. Enhances maintainability and scalability of the system.
// 7. Promotes single responsibility principle by separating command logic from device logic.
// 8. Facilitates testing by allowing commands to be tested in isolation.


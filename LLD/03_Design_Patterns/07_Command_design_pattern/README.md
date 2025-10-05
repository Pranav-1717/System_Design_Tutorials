# Command Design Pattern
The Command pattern turns a request (an action) into a standalone object, so that we can store, pass, undo, or queue those actions easily — without the caller (like a Remote) knowing how the action actually happens.

## Problem Without Command Pattern
Let’s imagine a Smart Remote Control that can control multiple devices:

- A Light
- A TV
- A Fan

We’ll first see the bad design (without using Command pattern), understand its limitations, and then we’ll apply the Command pattern to fix it

**[Code Without Command design pattern](./code/without_cmd_pattern.cpp)**

### 1. Remote knows too much
The RemoteControl class knows about every device (`Light`, `TV`, etc.)
and how to operate them (`on()`, `off()`).

If we add a new device (say, Fan), we must open and modify the RemoteControl class.
This breaks a very important principle in software design:
- Open–Closed Principle:
A class should be open for extension, but closed for modification.

So every time we add or change devices, we must modify RemoteControl.
This is bad — tightly coupled code, hard to maintain, and error-prone.

### 2. Can’t support Undo
What if you press “Light ON” by mistake?
You can’t easily “undo” it, because the remote doesn’t remember what action it performed.

### 3. Can’t queue, log, or schedule actions

What if you want to:
- Save all actions to a file?
- Schedule an action (“turn on light after 10 seconds”)?
- Send a batch of commands (“turn off everything”)?

You can’t, because there’s no object representing a single action.Each action is just a hard-coded `if/else` call.

### 4: Hard to test or extend

What if tomorrow, you want to control:
- Fan speed
- AC temperature
- Music volume

Every time, you’ll add more and more `if/else` inside `pressButton()`.Soon your code becomes a spaghetti monster.

## How Command Pattern Solve the Problem
We will separate the request (the action) from the receiver (the device that performs it).

1. **A Command Interface** — declares an `execute()` and `undo()` method.

2. **Concrete Commands** — one per action (like `LightOnCommand`, `TVOffCommand`), that know which device they control.

3. **A Receiver** — the real device (like `Light`, `TV`).

4. **An Invoker** — the `RemoteControl` that calls `execute()` on commands.

5. **A Client** — creates the commands and connects them to the invoker.

**[Code with Command design pattern](./code/with_cmd_pattern.cpp)**

1. You call `remote.setCommand(&lightOn)`.
    -  Remote now holds a reference to a LightOnCommand.

2. You call `remote.pressButton()`.
    -  Remote doesn’t know what “light” is or how to turn it on.
    -  It simply says: `command->execute();`
    -  That goes inside `LightOnCommand::execute()`
    -  Which calls `light->on();`
    -  Output: “Light is ON”

3. Remote also stores this command in a stack, so it can later call undo().

4. When you press undo, it pops the last command and calls undo().

---


| Feature                             | Without Command                     | With Command                          |
| ----------------------------------- | ----------------------------------- | ------------------------------------- |
| **Device knowledge**                | Remote must know about every device | Remote knows only “Command” interface |
| **Adding new device**               | Modify `RemoteControl` class        | Just create new Command class         |
| **Undo/Redo**                       | Impossible                          | Built-in via `undo()`                 |
| **Logging / Queueing / Scheduling** | Hard or impossible                  | Easy, since commands are objects      |
| **Code maintenance**                | Tight coupling                      | Loose coupling                        |
| **Reusability**                     | Poor                                | Very high                             |

---
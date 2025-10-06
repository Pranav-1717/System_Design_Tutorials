# Facade Design Pattern

Ever tried to use a library or system with so many classes, configurations, and objects.You just wanted to “get it working,” but instead you’re lost in a maze of dependencies and method calls.

That’s exactly where the Facade Design Pattern steps in — acting as your friendly front desk to a complex system. Instead of juggling dozens of components, you interact with one simple, unified interface that takes care of the details for you.

The Facade Pattern provides a unified interface to a set of interfaces in a subsystem. It defines a higher-level interface that makes the subsystem easier to use.

## Why Do We Need the Facade Pattern?
Lets understand problem first

Imagine you’re building a Home Theater System in code.
Without any pattern, you might have:
- `DVDPlayer`
- `Projector`
- `Amplifier`
- `Lights`
- `Screen`
- `PopcornMaker`

```c++
public class HomeTheaterTest {
    public static void main(String[] args) {
        DVDPlayer dvd = new DVDPlayer();
        Projector projector = new Projector();
        Amplifier amp = new Amplifier();
        Lights lights = new Lights();
        Screen screen = new Screen();
        PopcornMaker popcorn = new PopcornMaker();

        popcorn.on();
        popcorn.pop();
        lights.dim(10);
        screen.down();
        projector.on();
        projector.setInput(dvd);
        amp.on();
        amp.setSource(dvd);
        amp.setVolume(5);
        dvd.on();
        dvd.play("Inception");
    }
}
```

every time you want to watch a movie, you must remember exactly what to turn on, in what order, and how to configure them.


The code is:
- Tightly coupled (your main class depends on every subsystem)
- Hard to maintain (adding or changing a component affects multiple places)
- Difficult to reuse (you can’t easily use this setup elsewhere)


## The Solution: Introduce a Facade
Let’s add a Facade that knows how to talk to all these subsystems.

We’ll create a single class — HomeTheaterFacade — that wraps all the subsystem complexities inside it.

**[Code With Facade Design Pattern](./code/with_facade.cpp)**

The Facade (HomeTheaterFacade) encapsulates all the complex interactions.
From the client’s perspective, the system now has just two simple methods:
- `watchMovie(String movie)`
- `endMovie()`

### Benefits of Using Facade
- Simplified Interface — clients interact with one class instead of many.
- Reduced Coupling — the client no longer depends directly on subsystems.
- Easier Maintenance — changes in subsystems rarely affect the client.

#### Real World Use Cases

| System                | Facade Example                                                                   |
| --------------------- | -------------------------------------------------------------------------------- |
| **Java**              | `java.net.URL` hides complex network protocols                                   |
| **Frontend**          | Frameworks like React’s API often act as a facade over complex DOM manipulations |
| **Operating Systems** | File Explorer or Finder act as a UI facade over file system operations           |


#### Don’t use Facade:

- If your subsystem is already simple.
- If clients actually need deep access to subsystem details.
- When you want to extend, not hide, functionality (Adapter or Proxy might fit better).
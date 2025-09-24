# Adapter Design Pattern

The Adapter Design Pattern is a structural design pattern that allows objects with incompatible interfaces to collaborate. It acts as a wrapper between two objects, converting the interface of one class into another interface that clients expect.

This pattern is highly useful when integrating existing code with new systems or third-party libraries that have different interface requirements.

## Real-World Examples to Understand the Concept
To grasp the concept of an adapter, consider these everyday examples:
Power Adapters: Imagine you're in a hotel room with US-type power sockets, but your charger is designed for Indian sockets. An international adapter acts as a bridge, allowing your Indian charger to plug into the US socket.<br>
USB Adapters: If your mobile phone charges with a Type-C cable, but your power adapter only accepts Type-B, you'd use an adapter to convert the Type-C connection to Type-B, enabling your phone to charge.

In programming, an adapter serves the same purpose: it enables two completely different interfaces or classes to communicate, even if they normally couldn't interact directly.

## Why Use an Adapter?
The Adapter pattern addresses common challenges in software development:
- **Integrating Third-Party Libraries:** When incorporating external libraries or vendor code into your application, their interfaces might not align with your existing codebase. An adapter prevents tight coupling between your application and the third-party library, making it easier to swap out libraries in the future without extensive code changes.
- **Working with Legacy Code:** Modern applications often need to interact with older, "legacy" codebases that might use outdated methods or different data formats. An adapter can translate calls from your modern application to the legacy code's interface, allowing them to work together seamlessly.
- **Incompatible Interfaces:** When you have two distinct interfaces that need to interact but have different method signatures or data expectations, an adapter can bridge this gap by converting one interface into another that the client expects
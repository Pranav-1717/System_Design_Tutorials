# Singleton Design Pattern

The **Singleton Design Pattern** ensures that a class has **only one instance** and provides a **global access point** to it.  

### What is a Singleton?
A Singleton class is a special type of class that allows for the creation of only one object or instance. If you try to create another instance, it will simply return the already existing one. The core idea is to restrict the instantiation of a class to a single object.
Let's look at a basic class without the Singleton pattern:
```c++
lass MyClass {
public:
    MyClass() {
        // Constructor logic
        // This will be called every time a new object is created
        std::cout << "MyClass object created!" << std::endl;
    }
};

// In main or another function:
MyClass* obj1 = new MyClass(); // Output: MyClass object created!
MyClass* obj2 = new MyClass(); // Output: MyClass object created!
// obj1 and obj2 are different objects
```
In the example above, obj1 and obj2 are two distinct objects. The Singleton pattern aims to prevent this, ensuring that obj1 and obj2 would point to the same single instance.

## Implementation of Singleton
### 1. Restricting Object Creation: The Private Constructor
Normally, we create objects using the new keyword, which calls the class's constructor. To prevent multiple objects from being created, the first step is to make the class's constructor private.
```c++
class Singleton {
private:
    // Private constructor to prevent direct instantiation
    Singleton() {
        std::cout << "Singleton Constructor Called: New object created!" << std::endl;
    }

public:
    // Other methods and members will go here
};

// Attempting to create an object directly will result in a compile-time error:
// Singleton* s1 = new Singleton(); // ERROR: constructor is private
```

### 2. Providing a Single Access Point: The getInstance Method
Since we can't directly create objects, we need a public method to provide access to the single instance. This is typically named getInstance. This method must be static because it needs to be called without an existing object of the class.
```c++
class Singleton {
private:
    Singleton() {
        std::cout << "Singleton Constructor Called: New object created!" << std::endl;
    }

public:
    // Static method to get the single instance
    static Singleton* getInstance() {
        // Logic to create and return the instance will go here
        // For now, let's just return a new one (we'll fix this)
        return new Singleton(); // This is NOT the final Singleton pattern!
    }
};

// In main:
// Singleton* s1 = Singleton::getInstance(); // Creates an object
// Singleton* s2 = Singleton::getInstance(); // Creates another object
// s1 and s2 would still be different. We need to store the instance.
```

### 3. Storing the Instance: A Static Member Variable
Inside the class, a static private member variable (e.g., instance) of the Singleton type is used to hold the single object. This variable is initialized to nullptr (in C++) outside the class definition.

```c++
class Singleton {
private:
    static Singleton* instance; // Declare a static pointer to hold the instance

    // Private constructor
    Singleton() {
        std::cout << "Singleton Constructor Called: New object created!" << std::endl;
    }

public:
    static Singleton* getInstance() {
        if (instance == nullptr) { // Check if an instance already exists
            instance = new Singleton(); // If not, create one
        }
        return instance; // Return the existing or newly created instance
    }
};

// Initialize the static member outside the class
Singleton* Singleton::instance = nullptr;

// In main:
// Singleton* s1 = Singleton::getInstance(); // Output: Singleton Constructor Called: New object created!
// Singleton* s2 = Singleton::getInstance(); // No output from constructor
// std::cout << (s1 == s2) << std::endl; // Output: 1 (True), meaning they are the same object!
```
## Ensuring Thread Safety
The basic Singleton implementation above isn't thread-safe. In a multi-threaded environment, multiple threads could simultaneously check if instance is nullptr and then proceed to create multiple objects, violating the Singleton principle.

### 1. Double-Checked Locking (DCL)
Locking is an expensive operation. To optimize, we can use double-checked locking. This involves checking for nullptr twice: once before acquiring a lock and once inside the locked section.

```c++
#include <iostream>
#include <mutex> // For std::mutex

class Singleton {
private:
    static Singleton* instance;
    static std::mutex mtx; // Mutex for thread safety

    Singleton() {
        std::cout << "Singleton Constructor Called: New object created!" << std::endl;
    }

public:
      // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        if (instance == nullptr) { // First check (without lock)
            std::lock_guard<std::mutex> lock(mtx); // Acquire lock
            if (instance == nullptr) { // Second check (inside lock)
                instance = new Singleton();
            }
        }
        return instance;
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

// In a multi-threaded main function, this would ensure only one object is created.
```
### 2. Eager Initialization
A simpler, inherently thread-safe approach that avoids explicit locks is eager initialization. The single instance is created at the time of declaration of the static member variable, even before the main function runs.

```c++
class Singleton {
private:
    // Eagerly create the instance at program startup
    static Singleton* instance;

    Singleton() {
        std::cout << "Singleton Constructor Called: New object created (Eager)!" << std::endl;
    }

public:

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        return instance; // Simply return the already created instance
    }
};

// Initialize the static member eagerly
Singleton* Singleton::instance = new Singleton();

// In main:
// Singleton* s1 = Singleton::getInstance(); // No constructor output here, it was called at startup
// Singleton* s2 = Singleton::getInstance();
// std::cout << (s1 == s2) << std::endl; // Output: 1 (True)
```
- **Advantage:** Simple and inherently thread-safe as the object is created once and for all.
- **Disadvantage:** If the Singleton object is expensive to create (e.g., consumes a lot of memory or resources) and is never actually used, it leads to wasted resources. This is only practical for lightweight objects.

## Real-World Use Cases for Singleton
### 1. Logging System
Imagine a large application where various components need to write messages to a log file. If each component created its own logger object, you could end up with:
- Multiple log files.
- Inconsistent logging formats.
- Race conditions when multiple loggers try to write to the same file simultaneously, leading to corrupted or out-of-order logs .<br>

A Singleton Logger ensures that all parts of the application use the same logger instance, centralizing log management.

```c++
// Example of a Singleton Logger
class Logger {
private:
    static Logger* instance;
    std::ofstream logFile; // Output file stream for logging

    Logger() {
        logFile.open("application.log", std::ios::app); // Open log file in append mode
        std::cout << "Logger instance created." << std::endl;
    }

public:
    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void writeLog(const std::string& message) {
        logFile << message << std::endl;
    }

    // Prevent copy and assignment
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

Logger* Logger::instance = nullptr;

// In different parts of your application:
// Logger::getInstance()->writeLog("User logged in.");
// Logger::getInstance()->writeLog("Database query executed.");
```

### 2. Database Connection Pool
Establishing a database connection is an expensive operation in terms of memory and resources. If every time a user or a service needs to interact with the database, a new connection is opened, it would quickly exhaust system resources and degrade performance.<br>
A Singleton Database Connection Manager (or a connection pool manager) ensures that only one connection object (or a pool of managed connections) is created and shared across the entire application.

```c++
// Example of a Singleton Database Connection
class DBConnection {
private:
    static DBConnection* instance;
    // Simulate a database connection
    std::string connectionString;

    DBConnection() {
        connectionString = "Connected to MySQL:user@password/mydb";
        std::cout << "Database connection established: " << connectionString << std::endl;
    }

public:
    static DBConnection* getInstance() {
        if (instance == nullptr) {
            instance = new DBConnection();
        }
        return instance;
    }

    void executeQuery(const std::string& query) {
        std::cout << "Executing query: " << query << " using " << connectionString << std::endl;
    }

    // Prevent copy and assignment
    DBConnection(const DBConnection&) = delete;
    DBConnection& operator=(const DBConnection&) = delete;
};

DBConnection* DBConnection::instance = nullptr;

// In different services of your application:
// DBConnection::getInstance()->executeQuery("SELECT * FROM Users");
// DBConnection::getInstance()->executeQuery("INSERT INTO Products VALUES (...)");
```
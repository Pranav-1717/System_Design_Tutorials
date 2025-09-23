#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* ==========================================================
   OBSERVER DESIGN PATTERN - STOCK MARKET EXAMPLE
   ----------------------------------------------------------
   
   Example:
   - StockMarket (Subject) publishes stock price changes.
   - Multiple apps/services (Observers) like MobileApp,
     DesktopApp, NewsAgency want real-time updates.
   ========================================================== */

// ---------------- Observer Interface -----------------
class Observer {
public:
    virtual void update(const string& stockName, float price) = 0; // must be implemented
    virtual ~Observer() {}
};

// ---------------- Subject Interface -----------------
class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(const string& stockName, float price) = 0;
    virtual ~Subject() {}
};

// ---------------- Concrete Subject: StockMarket -----------------
class StockMarket : public Subject {
private:
    vector<Observer*> observers;  // list of subscribers (observers)

public:
    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // Notify all observers about stock price change
    void notifyObservers(const string& stockName, float price) override {
        for (Observer* obs : observers) {
            obs->update(stockName, price);
        }
    }

    // Change stock price and broadcast to observers
    void setStockPrice(const string& stockName, float price) {
        cout << "\n[StockMarket] " << stockName 
             << " new price: $" << price << endl;
        notifyObservers(stockName, price);
    }
};

// ---------------- Concrete Observers -----------------

// Observer #1: Mobile App
class MobileApp : public Observer {
private:
    string owner;
public:
    MobileApp(string name) : owner(name) {}

    void update(const string& stockName, float price) override {
        cout << "[MobileApp - " << owner << "] "
             << stockName << " updated price: $" << price << endl;
    }
};

// Observer #2: Desktop Application
class DesktopApp : public Observer {
public:
    void update(const string& stockName, float price) override {
        cout << "[DesktopApp] Displaying " 
             << stockName << " price: $" << price << endl;
    }
};

// Observer #3: News Agency
class NewsAgency : public Observer {
public:
    void update(const string& stockName, float price) override {
        cout << "[NewsAgency] Breaking news: "
             << stockName << " hits $" << price << endl;
    }
};

// ---------------- Client Code -----------------
int main() {
    // Create StockMarket (Subject)
    StockMarket market;

    // Create Observers
    MobileApp mobile1("Alice");
    MobileApp mobile2("Bob");
    DesktopApp desktop;
    NewsAgency reuters;

    // Register observers
    market.addObserver(&mobile1);
    market.addObserver(&mobile2);
    market.addObserver(&desktop);
    market.addObserver(&reuters);

    // Simulate stock price updates
    market.setStockPrice("AAPL", 150.5f);
    market.setStockPrice("GOOGL", 2800.75f);

    // Unsubscribe one observer
    market.removeObserver(&mobile2);
    cout << "\n[StockMarket] Bob unsubscribed from updates.\n";

    // More updates
    market.setStockPrice("TSLA", 720.25f);

    return 0;
}

/* ==========================================================
   SAMPLE OUTPUT
   ----------------------------------------------------------
   [StockMarket] AAPL new price: $150.5
   [MobileApp - Alice] AAPL updated price: $150.5
   [MobileApp - Bob] AAPL updated price: $150.5
   [DesktopApp] Displaying AAPL price: $150.5
   [NewsAgency] Breaking news: AAPL hits $150.5

   [StockMarket] GOOGL new price: $2800.75
   [MobileApp - Alice] GOOGL updated price: $2800.75
   [MobileApp - Bob] GOOGL updated price: $2800.75
   [DesktopApp] Displaying GOOGL price: $2800.75
   [NewsAgency] Breaking news: GOOGL hits $2800.75

   [StockMarket] Bob unsubscribed from updates.

   [StockMarket] TSLA new price: $720.25
   [MobileApp - Alice] TSLA updated price: $720.25
   [DesktopApp] Displaying TSLA price: $720.25
   [NewsAgency] Breaking news: TSLA hits $720.25
   ========================================================== */

#include <iostream>
#include <string>
using namespace std;

// --- Subsystem Classes ---

class DVDPlayer {
public:
    void on() { cout << "DVD Player ON\n"; }
    void play(const string& movie) { cout << "Playing movie: " << movie << endl; }
    void stop() { cout << "Stopping DVD\n"; }
    void off() { cout << "DVD Player OFF\n"; }
};

class Projector {
public:
    void on() { cout << "Projector ON\n"; }
    void setInput(DVDPlayer* dvd) { cout << "Projector set to DVD input\n"; }
    void off() { cout << "Projector OFF\n"; }
};

class Amplifier {
public:
    void on() { cout << "Amplifier ON\n"; }
    void setSource(DVDPlayer* dvd) { cout << "Amplifier source set to DVD\n"; }
    void setVolume(int level) { cout << "Volume set to " << level << endl; }
    void off() { cout << "Amplifier OFF\n"; }
};

class Lights {
public:
    void dim(int level) { cout << "Lights dimmed to " << level << "%\n"; }
    void on() { cout << "Lights ON\n"; }
};

class Screen {
public:
    void down() { cout << "Screen going down\n"; }
    void up() { cout << "Screen going up\n"; }
};

class PopcornMaker {
public:
    void on() { cout << "Popcorn Maker ON\n"; }
    void pop() { cout << "Popping popcorn...\n"; }
    void off() { cout << "Popcorn Maker OFF\n"; }
};

// --- Client code without Facade ---
int main() {
    cout << "=== Without Facade ===\n\n";

    DVDPlayer dvd;
    Projector projector;
    Amplifier amp;
    Lights lights;
    Screen screen;
    PopcornMaker popcorn;

    cout << "Get ready to watch a movie...\n";

    popcorn.on();
    popcorn.pop();
    lights.dim(10);
    screen.down();
    projector.on();
    projector.setInput(&dvd);
    amp.on();
    amp.setSource(&dvd);
    amp.setVolume(5);
    dvd.on();
    dvd.play("Inception");

    cout << "\nNow ending the movie...\n";
    popcorn.off();
    lights.on();
    screen.up();
    projector.off();
    amp.off();
    dvd.stop();
    dvd.off();

    return 0;
}

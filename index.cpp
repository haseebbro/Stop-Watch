1
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    char choice;
    bool running = false;
    auto startTime = chrono::steady_clock::now();
    auto elapsedTime = chrono::duration<double>::zero();

    cout << "Welcome to the Simple Stopwatch!" << endl;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Start Stopwatch" << endl;
        cout << "2. Stop Stopwatch" << endl;
        cout << "3. Reset Stopwatch" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                if (!running) {
                    running = true;
                    startTime = chrono::steady_clock::now();
                    cout << "Stopwatch started!" << endl;
                } else {
                    cout << "Stopwatch is already running." << endl;
                }
                break;

            case '2':
                if (running) {
                    elapsedTime += chrono::steady_clock::now() - startTime;
                    running = false;
                    cout << "Stopwatch stopped!" << endl;
                    cout << "Elapsed time: " << elapsedTime.count() << " seconds." << endl;
                } else {
                    cout << "Stopwatch is not running." << endl;
                }
                break;

            case '3':
                running = false;
                elapsedTime = chrono::duration<double>::zero();
                cout << "Stopwatch reset!" << endl;
                break;

            case '4':
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}
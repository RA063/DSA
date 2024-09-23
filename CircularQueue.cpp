#include <iostream>
using namespace std;

class Circular_Queue {
    #define max 10
private:
    int r = -1;
    int f = -1;
public:
    int arr[max];

    bool IsEmpty() {
        return r == -1 && f == -1;
    }

    bool IsFull() {
        return (r + 1) % max == f;
    }

    void enqueue(int value) {
        if (IsFull()) {
            cout << "THE QUEUE IS FULL !!!" << endl;
            return;
        }
        if (IsEmpty()) {
            f = 0;
            r = 0;
        } else {
            r = (r + 1) % max;
        }
        arr[r] = value;
        cout << "The enqueued value is: " << value << endl;
    }

    void dequeue() {
        if (IsEmpty()) {
            cout << "THE QUEUE IS EMPTY !!!" << endl;
        } else if (r == f) {
            cout << "The dequeued element is: " << arr[f] << endl;
            r = f = -1;
        } else {
            cout << "The dequeued element is: " << arr[f] << endl;
            f = (f + 1) % max;
        }
    }

    void display() {
        if (IsEmpty()) {
            cout << "THE QUEUE IS EMPTY !!!" << endl;
            return;
        }
        cout << "Circular Queue: ";
        for (int i = f; i != r; i = (i + 1) % max) {
            cout << arr[i] << " ";
        }
        cout << arr[r] << endl;
    }
};

int main() {
    Circular_Queue queue;
    int choice, value;

    do {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;

            case 2:
                queue.dequeue();
                break;

            case 3:
                queue.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


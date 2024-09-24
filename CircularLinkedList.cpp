#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

class Circular_Link_list {
public:
    node *head;
    node *tail;

    // Constructor
    Circular_Link_list() {
        head = NULL;
        tail = NULL;
    }

    // Insert at head
    void insert_head(int val) {
        node *temp = new node(val);
        if (head == NULL) {
            head = tail = temp;
            tail->next = head;
        } else {
            temp->next = head;
            head = temp;
            tail->next = head;
        }
    }

    // Insert at tail
    void insert_tail(int val) {
        node *temp = new node(val);
        if (head == NULL) {
            head = tail = temp;
            tail->next = head;
        } else {
            temp->next = head;
            tail->next = temp;
            tail = temp;
        }
    }

    // Insert at a specific position
    void insert_pos(int pos, int val) {
        node *pos_node = new node(val);
        int L = len();
        if (pos == 1) {
            insert_head(val);
            return;
        }
        if (pos > L) {
            insert_tail(val);
            return;
        }
        int count = 1;
        node *temp = head;
        while (count < pos - 1) {
            count++;
            temp = temp->next;
        }
        pos_node->next = temp->next;
        temp->next = pos_node;
    }

    // Delete from head
    void delete_head() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        node *temp = head;
        if (head == tail) { // Only one node in the list
            head = tail = NULL;
        } else {
            head = head->next;
            tail->next = head;
        }
        delete temp;
    }

    // Delete from tail
    void delete_tail() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head == tail) { // Only one node in the list
            delete head;
            head = tail = NULL;
            return;
        }
        node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = head;
    }

    // Delete from a specific position
    void delete_pos(int pos) {
        int L = len();
        if (pos == 1) {
            delete_head();
            return;
        }
        if (pos >= L) {
            delete_tail();
            return;
        }
        node *prev = head;
        node *cur = head->next;
        int count = 1;
        while (count < pos - 1) {
            count++;
            prev = prev->next;
            cur = cur->next;
        }
        prev->next = cur->next;
        delete cur;
    }

    // Display the circular linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Calculate length of the circular linked list
    int len() {
        if (head == NULL) {
            return 0;
        }
        int n = 0;
        node *temp = head;
        do {
            n++;
            temp = temp->next;
        } while (temp != head);
        return n;
    }
};

// Main function for testing
int main() {
    Circular_Link_list list;
    int choice, val, pos;

    do {
        cout << "\nCircular Linked List Operations:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Head\n";
        cout << "5. Delete from Tail\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> val;
            list.insert_head(val);
            break;

        case 2:
            cout << "Enter value to insert at tail: ";
            cin >> val;
            list.insert_tail(val);
            break;

        case 3:
            cout << "Enter position to insert at: ";
            cin >> pos;
            cout << "Enter value to insert: ";
            cin >> val;
            list.insert_pos(pos, val);
            break;

        case 4:
            list.delete_head();
            break;

        case 5:
            list.delete_tail();
            break;

        case 6:
            cout << "Enter position to delete: ";
            cin >> pos;
            list.delete_pos(pos);
            break;

        case 7:
            list.display();
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}


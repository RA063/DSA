#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

class Single_link_list {
public:
    node* head;
    node* tail;

    // Constructor
    Single_link_list() {
        head = NULL;
        tail = NULL;
    }

    // Insert at the head
    void insert_head(int val) {
        node* temp = new node(val);
        temp->next = head;
        head = temp;
        if (tail == NULL) {
            tail = temp;
        }
    }

    // Insert at the tail
    void insert_tail(int val) {
        node* temp = new node(val);
        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Insert at a specific position
    void insert_pos(int pos, int val) {
        node* pos_node = new node(val);
        node* prev = head;
        int count = 1;

        if (pos == 1) {
            insert_head(val);
            return;
        }

        while (count < pos - 1 && prev != NULL) {
            prev = prev->next;
            count++;
        }

        // If position is at the end
        if (prev == NULL || prev->next == NULL) {
            insert_tail(val);
            return;
        }

        pos_node->next = prev->next;
        prev->next = pos_node;
    }

    // Delete from the head
    void delete_head() {
        node* temp = head;
        if (temp == NULL) {
            cout << "EMPTY ..." << endl;
            tail = NULL;
            return;
        }
        head = head->next;
        delete temp;
    }

    // Delete from the tail
    void delete_tail() {
        if (head == NULL) {
            cout << "EMPTY..." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        node* temp = head;
        node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
        tail = prev;
    }

    // Find length of the list
    int len() {
        int n = 0;
        node* temp = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        return n;
    }

    // Delete from a specific position
    void delete_pos(int pos) {
        if (head == NULL) {
            cout << "EMPTY...." << endl;
            return;
        }
        if (pos == 1) {
            delete_head();
            return;
        }

        int l = len();
        if (pos >= l) {
            delete_tail();
            return;
        }

        node* prev = head;
        node* cur = head->next;
        int count = 2;

        while (count < pos) {
            prev = prev->next;
            cur = cur->next;
            count++;
        }

        prev->next = cur->next;
        delete cur;
    }

    // Display the linked list
    void display() {
        node* temp = head;
        if (temp == NULL) {
            cout << "EMPTY ...." << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Single_link_list list;
    int choice, val, pos;

    do {
        cout << "\nLinked List Operations:\n";
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


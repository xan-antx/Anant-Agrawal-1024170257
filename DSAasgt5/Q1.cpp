#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

Node* makeNode(int val) {
    Node* n = new Node;
    n->data = val;
    n->next = nullptr;
    return n;
}


void pushFront(int val) {
    Node* n = makeNode(val);
    n->next = head;
    head = n;
    cout << "Node inserted at front\n";
}


void pushBack(int val) {
    Node* n = makeNode(val);
    if (!head) {
        head = n;
    } else {
        Node* p = head;
        while (p->next) p = p->next;
        p->next = n;
    }
    cout << "Node inserted at back\n";
}


void insertAt(int pos, int val) {
    if (pos <= 1) {
        pushFront(val);
        return;
    }
    Node* n = makeNode(val);
    Node* p = head;
    for (int i = 1; i < pos - 1 && p; i++) {
        p = p->next;
    }
    if (!p) {
        cout << "Invalid position\n";
        delete n;
        return;
    }
    n->next = p->next;
    p->next = n;
    cout << "Node inserted at position " << pos << "\n";
}


void popFront() {
    if (!head) {
        cout << "List empty\n";
        return;
    }
    Node* tmp = head;
    head = head->next;
    delete tmp;
    cout << "Deleted first node\n";
}

void popBack() {
    if (!head) {
        cout << "List empty\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        cout << "Deleted last node\n";
        return;
    }
    Node* p = head;
    while (p->next->next) p = p->next;
    delete p->next;
    p->next = nullptr;
    cout << "Deleted last node\n";
}


void eraseAt(int pos) {
    if (!head) {
        cout << "List empty\n";
        return;
    }
    if (pos == 1) {
        popFront();
        return;
    }
    Node* p = head;
    for (int i = 1; i < pos - 1 && p; i++) {
        p = p->next;
    }
    if (!p || !p->next) {
        cout << "Invalid position\n";
        return;
    }
    Node* tmp = p->next;
    p->next = tmp->next;
    delete tmp;
    cout << "Node deleted at position " << pos << "\n";
}

void findVal(int val) {
    Node* p = head;
    int idx = 1;
    while (p) {
        if (p->data == val) {
            cout << "Element found at index " << idx << "\n";
            return;
        }
        p = p->next;
        idx++;
    }
    cout << "Element not found\n";
}

void show() {
    if (!head) {
        cout << "List empty\n";
        return;
    }
    cout << "List: ";
    for (Node* p = head; p; p = p->next) {
        cout << p->data << " ";
    }
    cout << "\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete at position\n";
        cout << "7. Search for value\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter option: ";
        cin >> choice;

        int pos, val;
        switch (choice) {
            case 1: cout << "Value: "; cin >> val; pushFront(val); break;
            case 2: cout << "Value: "; cin >> val; pushBack(val); break;
            case 3: cout << "Position: "; cin >> pos; cout << "Value: "; cin >> val; insertAt(pos, val); break;
            case 4: popFront(); break;
            case 5: popBack(); break;
            case 6: cout << "Position: "; cin >> pos; eraseAt(pos); break;
            case 7: cout << "Value: "; cin >> val; findVal(val); break;
            case 8: show(); break;
            case 9: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option\n";
        }
    } while (choice != 9);

    return 0;
}

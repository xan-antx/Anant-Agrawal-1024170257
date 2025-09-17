#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

Node* start = nullptr;

void append(int v) {
    Node* fresh = new Node;
    fresh->val = v;
    fresh->next = nullptr;

    if (!start) {
        start = fresh;
        return;
    }
    Node* walk = start;
    while (walk->next) {
        walk = walk->next;
    }
    walk->next = fresh;
}

int frequency(int k) {
    int cnt = 0;
    for (Node* ptr = start; ptr; ptr = ptr->next) {
        if (ptr->val == k) cnt++;
    }
    return cnt;
}

void removeKey(int k) {
    while (start && start->val == k) {
        Node* gone = start;
        start = start->next;
        delete gone;
    }

    Node* prev = nullptr;
    Node* curr = start;

    while (curr) {
        if (curr->val == k) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void display() {
    Node* ptr = start;
    while (ptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}

int main() {
    int n, x, key;
    cout << "Enter list size: ";
    cin >> n;

    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        append(x);
    }

    cout << "Value to remove: ";
    cin >> key;

    cout << "Occurrences: " << frequency(key) << endl;
    removeKey(key);

    cout << "List after deletion: ";
    display();

    return 0;
}

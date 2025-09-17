#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* link;
};

Node* start = nullptr;

void addNode(int x) {
    Node* fresh = new Node;
    fresh->val = x;
    fresh->link = nullptr;

    if (start == nullptr) {
        start = fresh;
        return;
    }
    Node* walk = start;
    while (walk->link) {
        walk = walk->link;
    }
    walk->link = fresh;
}

Node* invert(Node* headRef) {
    Node* prev = nullptr;
    Node* curr = headRef;
    while (curr) {
        Node* nxt = curr->link;
        curr->link = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
void show(Node* ptr) {
    while (ptr) {
        cout << ptr->val << " -> ";
        ptr = ptr->link;
    }
    cout << "NULL\n";
}

int main() {
    int n, x;
    cout << "How many nodes? ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        addNode(x);
    }

    start = invert(start);

    cout << "Reversed list: ";
    show(start);

    return 0;
}

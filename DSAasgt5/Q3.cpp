#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

class LinkedList {
private:
    Node* start;
public:
    LinkedList() : start(nullptr) {}

    void append(int v) {
        Node* node = new Node(v);
        if (!start) {
            start = node;
            return;
        }
        Node* cur = start;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = node;
    }

    void displayMiddle() {
        if (!start) {
            cout << "List is empty\n";
            return;
        }
        Node* hare = start;
        Node* tortoise = start;

        while (hare && hare->next) {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        cout << "Middle element: " << tortoise->value << endl;
    }
};

int main() {
    LinkedList list;
    int n, x;
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        list.append(x);
    }
    list.displayMiddle();
    return 0;
}

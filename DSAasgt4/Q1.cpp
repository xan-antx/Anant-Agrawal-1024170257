#include <iostream>
using namespace std;

int cap = 5;
int frontIdx = -1, rearIdx = -1;
int q[5];

bool emptyQ() {
    return (frontIdx == -1);
}

bool fullQ() {
    return (rearIdx == cap - 1);
}

void pushQ(int v) {
    if (fullQ()) {
        cout << "Queue full\n";
        return;
    }
    if (emptyQ()) {
        frontIdx = rearIdx = 0;
        q[0] = v;
    } else {
        q[++rearIdx] = v;
    }
    cout << "Added\n";
}

void popQ() {
    if (emptyQ()) {
        cout << "Queue empty\n";
        return;
    }
    frontIdx++;
    if (frontIdx > rearIdx) frontIdx = rearIdx = -1;
    cout << "Removed\n";
}

void frontQ() {
    if (emptyQ()) {
        cout << "Queue empty\n";
        return;
    }
    cout << "Front: " << q[frontIdx] << "\n";
}

void showQ() {
    if (emptyQ()) {
        cout << "Queue empty\n";
        return;
    }
    for (int i = frontIdx; i <= rearIdx; i++) cout << q[i] << " ";
    cout << "\n";
}

int main() {
    int ch;
    cout << "1.Enqueue\n2.Dequeue\n3.Check empty\n4.Check full\n5.Display\n6.Front\n7.Exit\n";
    do {
        cout << "Choice: ";
        cin >> ch;
        int v;
        switch (ch) {
            case 1: cout << "Val: "; cin >> v; pushQ(v); break;
            case 2: popQ(); break;
            case 3: cout << (emptyQ() ? "Empty\n" : "Not empty\n"); break;
            case 4: cout << (fullQ() ? "Full\n" : "Not full\n"); break;
            case 5: showQ(); break;
            case 6: frontQ(); break;
            case 7: cout << "Bye\n"; break;
            default: cout << "Invalid\n";
        }
    } while (ch != 7);
}

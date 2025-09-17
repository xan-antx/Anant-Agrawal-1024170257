#include <iostream>
using namespace std;

const int MAXN = 5;
int frontPos = -1, rearPos = -1;
int q[MAXN];

bool emptyQ() {
    return (frontPos == -1);
}

bool fullQ() {
    return ((rearPos + 1) % MAXN == frontPos);
}

void pushQ(int val) {
    if (fullQ()) {
        cout << "Overflow\n";
        return;
    }
    if (emptyQ()) {
        frontPos = rearPos = 0;
    } else {
        rearPos = (rearPos + 1) % MAXN;
    }
    q[rearPos] = val;
    cout << "Added\n";
}

void popQ() {
    if (emptyQ()) {
        cout << "Underflow\n";
        return;
    }
    if (frontPos == rearPos) {
        frontPos = rearPos = -1;
    } else {
        frontPos = (frontPos + 1) % MAXN;
    }
    cout << "Deleted\n";
}

void frontQ() {
    if (emptyQ()) {
        cout << "Queue empty\n";
        return;
    }
    cout << "Front: " << q[frontPos] << "\n";
}

void printQ() {
    if (emptyQ()) {
        cout << "Queue empty\n";
        return;
    }
    cout << "Data: ";
    int i = frontPos;
    while (true) {
        cout << q[i] << " ";
        if (i == rearPos) break;
        i = (i + 1) % MAXN;
    }
    cout << "\n";
}

int main() {
    int ch;
    cout << "1.Push\n2.Pop\n3.Empty?\n4.Full?\n5.Show\n6.Front\n7.Exit\n";
    do {
        cout << "Choice: ";
        cin >> ch;
        int val;
        switch (ch) {
            case 1: cout << "Enter: "; cin >> val; pushQ(val); break;
            case 2: popQ(); break;
            case 3: cout << (emptyQ() ? "Yes\n" : "No\n"); break;
            case 4: cout << (fullQ() ? "Yes\n" : "No\n"); break;
            case 5: printQ(); break;
            case 6: frontQ(); break;
            case 7: cout << "End\n"; break;
            default: cout << "Invalid\n";
        }
    } while (ch != 7);
    return 0;
}

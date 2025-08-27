#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array length: ";
    cin >> n;

    int arr[1000]; 
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;
        
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            distinctCount++;
        }
    }

    cout << "Total distinct elements: " << distinctCount << endl;

    return 0;
}  
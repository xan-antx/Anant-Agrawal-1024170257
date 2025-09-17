#include <iostream>
#include <string>
using namespace std;

char uniqueChar(string s) {
    int count[26] = {0};
    for (char c : s) count[c - 'a']++;
    for (char c : s) {
        if (count[c - 'a'] == 1) return c;
    }
    return 0;
}

int main() {
    string s;
    cout << "Input lowercase word: ";
    cin >> s;
    char res = uniqueChar(s);
    if (res == 0)
        cout << "No unique character\n";
    else
        cout << "First unique: " << res << "\n";
}

#include <iostream>   
#include <stack>      
#include <cctype>     
using namespace std;
int main() {
    string postf;    
    stack<int> stk;     
    cout << "enter postfix: ";
    cin >> postfix;    
    for (int i = 0; i < postf.length(); i++) {
        char ch = postf[i];   
        if (isdigit(ch)) {
            stk.push(ch - '0'); 
        }
        else {
            int v2 = stk.top(); stk.pop(); 
            int v1 = stk.top(); stk.pop();  
            switch (ch) {
                case '+': stk.push(v1 + v2); break;
                case '-': stk.push(v1 - v2); break;
                case '*': stk.push(v1 * v2); break;
                case '/': stk.push(v1 / v2); break;
            }
        }
    }
    cout << "resullt is; " << stk.top() << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; if(!(cin>>n)) return 0;
  
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
  
    vector<int> target = A;
    sort(target.begin(), target.end());

    stack<int> st;
    int idx = 0;
  
    int i = 0;
    while(i < n){
      
        st.push(A[i]);
        i++;
        while(!st.empty() && st.top() == target[idx]){
            st.pop();
            idx++;
            if(idx >= n) break;
        }
    }
    while(!st.empty() && idx < n){
        if(st.top() == target[idx]){
          
            st.pop(); idx++;
        } else break;
    }
    return 0;
}

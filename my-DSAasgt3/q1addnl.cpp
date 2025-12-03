#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if(!(cin>>n)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<long long> ans(n);
  
    stack<long long> st;
  
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top() >= a[i]) st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(a[i]);}
    for(int i=0;i<n;i++){
        if(i) cout<<" ";
      
        cout<<ans[i];
       }
    return 0;
}

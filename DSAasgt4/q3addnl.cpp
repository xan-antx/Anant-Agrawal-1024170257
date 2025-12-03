
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if(!(cin>>n)) return 0;
    queue<int> in;
    for(int i=0;i<n;i++){ int x; cin>>x; in.push(x); }
  
    stack<int> st;
    int need = 1;

    while(!in.empty() || !st.empty()){
      
        if(!st.empty() && st.top() == need){
            st.pop();
            need++;
        } else if(!in.empty()){
          
            int v = in.front(); in.pop();
          
            if(v == need){
                need++;
} else {
                st.push(v);
            }
 } else {
            break;
 }
    }
    if(need == n+1) cout<<"Yes\n"; else cout<<"No\n";
  
    return 0;
}

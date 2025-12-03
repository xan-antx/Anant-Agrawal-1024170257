#include <bits/stdc++.h>


using namespace std;
int main(){
  
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; if(!(cin>>n)) return 0;
  
    vector<int> t(n);
    for(int i=0;i<n;i++) cin>>t[i];
  

    vector<int> ans(n,0);
    stack<int> st;
  
    for(int i=0;i<n;i++){
        while(!st.empty() && t[i] > t[st.top()]){
          
            int idx = st.top(); st.pop();
          
            ans[idx] = i - idx;
        }
        st.push(i);
    }
    for(int i=0;i<n;i++){
      
        if(i) cout<<" ";
        cout<<ans[i];
      
    }
    cout<<"\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
  
    cin.tie(NULL);

    int abc,def;
    if(!(cin>>abc>>def)) return 0;
    vector<vector<int>> g(abc);
  
    for(int i=0;i<def;i++){
        int u,v; cin>>u>>v;
      
        if(u>=0 && u<abc && v>=0 && v<abc){
            g[u].push_back(v);
            g[v].push_back(u);
           }}

    vector<int> vis(abc,0);

    int comps = 0;
    for(int i=0;i<abc;i++){
        if(vis[i]) continue;
        comps++;
      
        stack<int> st;
        st.push(i); vis[i]=1;
      
        while(!st.empty()){
            int x = st.top(); st.pop();
          
            for(int nb: g[x]){
                if(!vis[nb]) { vis[nb]=1; st.push(nb); }}
        }
    }
    cout<<comps<< endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if(!(cin>>n)) return 0;
    queue<int> Q;
    for(int i=0;i<n;i++){ int x; cin>>x; Q.push(x); }

    for(int pass=0; pass<n; ++pass){
        int m = n - pass; 

        int mn = INT_MAX;
      
        for(int i=0;i<m;i++){
            int v = Q.front(); Q.pop();
          
            if(v < mn) mn = v;
            Q.push(v);
        }
        bool removed = false;
      
        for(int i=0;i<m;i++){
            int v = Q.front(); Q.pop();
          
            if(!removed && v == mn){
                removed = true;
                continue;
 } else {
                Q.push(v);
            } }
        Q.push(mn);  }

    bool first=true;
    while(!Q.empty()){
        if(!first) cout<<" ";
      
        cout<<Q.front();
        Q.pop();
        first=false;
      
    }
    return 0;
}

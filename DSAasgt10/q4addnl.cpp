#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
  
    cin.tie(NULL);

    int n; if(!(cin>>n)) return 0;
  
    vector<long long> A(n), B(n);
    for(int i=0;i<n;i++) cin>>A[i];
  
    for(int i=0;i<n;i++) cin>>B[i];

    unordered_map<long long,int> m;
    for(auto &x: A) m[x]++;
    for(auto &y: B){
      
        if(m.find(y)==m.end() || m[y]==0){
          
            cout<<"false\n"; return 0;
        }
        m[y]--;
    }
    for(auto &p: m) if(p.second!=0){ cout<<"false\n"; return 0; }
    cout<<"true\n";
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; long long target;
    if(!(cin>>n>>target)) return 0;
  
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    unordered_set<long long> seen;
    bool ok=false;
  
    for(int i=0;i<n;i++){
        long long need = target - a[i];
      
        if(seen.find(need) != seen.end()){
          
            ok = true; break;
        }
        seen.insert(a[i]);
    }
  
    cout<<(ok? "true":"false")<<"\n";
    return 0;
}

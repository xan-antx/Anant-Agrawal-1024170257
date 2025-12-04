
#include <bits/stdc++.h>
using namespace std;
int main(){

  
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; if(!(cin>>n)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    unordered_map<long long,int> cnt;
  
    for(auto &x: a) cnt[x]++;

    long long ans = LLONG_MIN;
    int best = 0;
    for(auto &p: cnt){
        long long val = p.first;
      
        int f = p.second;
        if(f > best){
            best = f; ans = val;
          
        } else if(f == best){
            if(val > ans) ans = val;
        }
    }
    cout<<ans<<"\n";
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; long long k;
  
    if(!(cin>>n>>k)) return 0;
  
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    unordered_map<long long,long long> freq; 
  
    for(auto &x: a) freq[x]++;

    long long ans=0;
    if(k==0){
        for(auto &p: freq){
            long long f = p.second;
          
            ans += (f*(f-1))/2;
        }
    } else {
        for(auto &p: freq){
            long long val = p.first; 
            if(freq.find(val + k) != freq.end()){
                ans += p.second * freq[val + k];
            }     } }
    cout<<ans<<"\n";
    return 0;
}

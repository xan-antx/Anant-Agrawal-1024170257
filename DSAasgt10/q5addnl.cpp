#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n;
    if(!(cin>>m>>n)) return 0;


  
    vector<long long> A(m), B(n);
    for(int i=0;i<m;i++) cin>>A[i];


  
    for(int j=0;j<n;j++) cin>>B[j];

    unordered_set<long long> s1, s2;
    for(auto &x: A) s1.insert(x);
  
    for(auto &x: B) s2.insert(x);
    vector<long long> uni;
    for(auto &x: s1) uni.push_back(x);
  
    for(auto &x: s2) if(s1.find(x)==s1.end()) uni.push_back(x);

    vector<long long> inter;
  
    for(auto &x: s1) if(s2.find(x) != s2.end()) inter.push_back(x);


    for(size_t i=0;i<uni.size();++i){
        if(i) cout<<" ";
        cout<<uni[i];
    }
    for(size_t i=0;i<inter.size();++i){
        if(i) cout<<" ";
        cout<<inter[i];
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1,s2;
    if(!(cin>>s1>>s2)) return 0;
  
    if(s1.size() != s2.size()){
        cout<<"NO\n"; return 0;
    }
    vector<int> cnt(26,0);
    for(char c: s1) cnt[c-'a']++;
  
    for(char c: s2) cnt[c-'a']--;
  
    bool ok = true;
    for(int x: cnt) if(x!=0) { ok=false; break; }
  
    return 0;
}

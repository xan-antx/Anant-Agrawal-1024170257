#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
  
    cin.tie(NULL);

    int n;
    if(!(cin>>n)) return 0;
  
    queue<string> q;
    q.push("1");
    vector<string> out;
    for(int i=1;i<=n;i++){
      
        string s = q.front(); q.pop();
        out.push_back(s);
        // generate next two
        string s0 = s + "0";
        string s1 = s + "1";
      
        q.push(s0);
        q.push(s1);
      
    }
    for(int i=0;i<out.size();i++){
        if(i) cout<<", ";
      
        cout<<out[i];
    }
    return 0;
}

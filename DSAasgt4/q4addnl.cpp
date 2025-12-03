#include <bits/stdc++.h>

using namespace std;
int main(){
  
    ios::sync_with_stdio(false);
  
    cin.tie(NULL);

    int s;
    if(!(cin>>s)) return 0;
    vector<int> students(s);
    for(int i=0;i<s;i++) cin>>students[i];

  
    vector<int> sandwiches(s);
  
    for(int i=0;i<s;i++) cin>>sandwiches[i];

    int cnt0 = 0, cnt1 = 0;
    for(int x: students){
        if(x==0) cnt0++; else cnt1++;
      
    }
    int idx = 0;
    for(; idx < s; ++idx){
      
        int top = sandwiches[idx];
        if(top==0){
            if(cnt0>0){ cnt0--; } else break;
          
        } else {
            if(cnt1>0){ cnt1--; } else break;
        }
    }
    int unable = cnt0 + cnt1;
  

    return 0;
}

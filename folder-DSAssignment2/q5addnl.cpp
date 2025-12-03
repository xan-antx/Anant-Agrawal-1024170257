#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; if(!(cin>>n)) return 0;
  
    vector<int> a(n);
  
    for(int i=0;i<n;i++) cin>>a[i];
    int twos = 0;
    for(int i=0;i<n;i++) if(a[i]==2) twos++;
  

    int i = n-1;
    int write = n-1 + twos; 
  
    while(i>=0){
        if(write <= n-1){
            a[write] = a[i]; }
        if(a[i] == 2){ 
          
            write--;
            if(write <= n-1){
                a[write] = 2;}  }
      
        i--; write--; }
    for(int k=0;k<n;k++){
      
        if(k) cout<<" ";
        cout<<a[k];
    }
    return 0;

  
}

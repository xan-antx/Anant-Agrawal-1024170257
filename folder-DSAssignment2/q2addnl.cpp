#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if(!(cin>>s)) return 0;
  
    int n = s.size(); 
  
    bool ok = false;
    for(int i=1;i<=n-2 && !ok;i++){
      
        for(int j=i+1;j<=n-1 && !ok;j++){ 
          
            string x = s.substr(0,i);
            string y = s.substr(i,j-i);
          
            string z = s.substr(j);
            if( y.find(x) != string::npos && z.find(x) != string::npos ) ok = true;
              
            else if( x.find(y) != string::npos && z.find(y) != string::npos ) ok = true;
              
            else if( x.find(z) != string::npos && y.find(z) != string::npos ) ok = true;
        }
    }
    cout << (ok? "YES":"NO") << "\n";
    return 0;
}

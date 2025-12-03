#include <bits/stdc++.h>
using namespace std;
int main(){

  
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; if(!(cin>>n)) return 0;
  
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int low=0, mid=0, high=n-1; 
  
    while(mid<=high){
        if(a[mid]==0){
            swap(a[low], a[mid]);
          
            low++; mid++;} else if(a[mid]==1){
          
            mid++;  } else { 
            swap(a[mid], a[high]);
            high--;}
    }
    for(int i=0;i<n;i++){
        if(i) cout<<" ";
        cout<<a[i];
    }
    return 0;

  
}

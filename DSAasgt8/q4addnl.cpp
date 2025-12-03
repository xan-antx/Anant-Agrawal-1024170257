#include <bits/stdc++.h>
using namespace std;

struct Nod{ int v; Nod* l; Nod* r; Nod(int x): v(x), l(NULL), r(NULL) {} };
Nod* build(vector<int>& arr){
    if(arr.empty()) return NULL;
  
    if(arr[0]==-1) return NULL;
  
    Nod* root = new Nod(arr[0]);
    queue<Nod*> q; q.push(root);
    int i=1;
  
    while(!q.empty() && i < (int)arr.size()){
        Nod* cur = q.front(); q.pop();
      
        if(i < (int)arr.size()){
          
            if(arr[i] != -1){ cur->l = new Nod(arr[i]); q.push(cur->l); }
            i++;  }
        if(i < (int)arr.size()){
          
            if(arr[i] != -1){ cur->r = new Nod(arr[i]); q.push(cur->r); }
            i++; }
    }
  
    return root;
}


vector<int> rightView(Nod* root){
    vector<int> ans;
    if(!root) return ans;
    queue<Nod*> q; q.push(root);
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            Nod* cur = q.front(); q.pop();
            if(i == sz-1) ans.push_back(cur->v);
            if(cur->l) q.push(cur->l);
            if(cur->r) q.push(cur->r);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; if(!(cin>>T)) return 0;
  
    while(T--){
        int n; cin>>n;
        vector<int> arr; arr.reserve(n);
        for(int i=0;i<n;i++){ int x; cin>>x; arr.push_back(x); }
        Nod* root = build(arr);
        vector<int> v = rightView(root);
        if(v.empty()){ cout<<"\n"; continue; }
        for(size_t i=0;i<v.size();++i){
            if(i) cout<<" ";
            cout<<v[i];  }
        cout<<"\n";
    }
    return 0;}

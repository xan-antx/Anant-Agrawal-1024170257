#include <bits/stdc++.h>
using namespace std;

struct N{ int v; N* l; N* r; N(int x): v(x), l(NULL), r(NULL) {} };
N* build(vector<int>& arr){
    if(arr.empty()) return NULL;
    if(arr[0]==-1) return NULL;
    N* root = new N(arr[0]);
    queue<N*> q;
    q.push(root);
    int i=1;
    while(!q.empty() && i < (int)arr.size()){
        N* cur = q.front(); q.pop();
        if(i < (int)arr.size()){
            if(arr[i] != -1){
                cur->l = new N(arr[i]); q.push(cur->l); }
            i++;}
        if(i < (int)arr.size()){
            if(arr[i] != -1){
                cur->r = new N(arr[i]); q.push(cur->r);
            }
            i++;  }
    }
    return root;
}



int maxDepth(N* r){
    if(!r) return 0;
    int L = maxDepth(r->l);
    int R = maxDepth(r->r);
    return max(L,R) + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; if(!(cin>>T)) return 0;
    while(T--){
        int n; cin>>n;
        vector<int> arr;
        arr.reserve(n);
        for(int i=0;i<n;i++){ int x; cin>>x; arr.push_back(x); }
        N* root = build(arr);
        int ans = maxDepth(root);
        cout<<ans<< endl;
    }
    return 0;
}

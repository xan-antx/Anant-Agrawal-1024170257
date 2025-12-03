#include <bits/stdc++.h>
using namespace std;

struct T{
    int v; T* l; T* r;
    T(int x): v(x), l(NULL), r(NULL) {}};
vector<T*> gen(int L,int R){
    vector<T*> res;
    if(L>R){
        res.push_back(NULL);
        return res; }

  
    for(int root=L; root<=R; ++root){
        vector<T*> lefts = gen(L, root-1);
        vector<T*> rights = gen(root+1, R);
        for(auto Lx: lefts){
            for(auto Rx: rights){
                T* nroot = new T(root);
                nroot->l = Lx;
                nroot->r = Rx;
                res.push_back(nroot);
            }     }
   }
    return res;
}

vector<int> serialize(T* root){
    vector<int> out;
    if(!root) { out.push_back(-1); return out; }
    queue<T*> q;
    q.push(root);
    while(!q.empty()){
        T* cur = q.front(); q.pop();
        if(cur){
            out.push_back(cur->v);
            q.push(cur->l);
            q.push(cur->r);
        } else {
            out.push_back(-1);
        }
    }
    while(!out.empty() && out.back()==-1) out.pop_back();
    if(out.empty()) out.push_back(-1);
    return out;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin>>n)) return 0;
    if(n<=0){
        cout<<"[]\n";
        return 0;
    }
    vector<T*> all = gen(1,n);
    for(auto root: all){
        vector<int> v = serialize(root);
        cout<<"[";
        for(size_t i=0;i<v.size();++i){
            cout<<v[i];
            if(i+1<v.size()) cout<<",";
        }
        cout<<"]\n";
    }
    return 0;
}

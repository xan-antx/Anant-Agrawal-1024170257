
#include <bits/stdc++.h>
using namespace std;
struct T{ int c; int p; T* n; T(int cc,int pp):c(cc),p(pp),n(NULL){} };

T* makePoly(vector<pair<int,int>>& v){
    if(v.empty()) return NULL;
    T* h = new T(v[0].first, v[0].second);
  
    T* cur = h;
    for(size_t i=1;i<v.size();++i){ cur->n = new T(v[i].first, v[i].second); cur = cur->n; }
    return h;
}
int main(){
  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
  
    int t1; if(!(cin>>t1)) return 0;
    vector<pair<int,int>> a(t1);
    for(int i=0;i<t1;i++) cin>>a[i].first>>a[i].second;
  
    int t2; cin>>t2;
    vector<pair<int,int>> b(t2);
    for(int i=0;i<t2;i++) cin>>b[i].first>>b[i].second;

    T* A = makePoly(a);
    T* B = makePoly(b);
    T dummy(0,0);
  
    T* R = &dummy;
    T* p=A; T* q=B;
    while(p && q){
        if(p->p == q->p){
          
            int s = p->c + q->c;
            if(s != 0) { R->n = new T(s, p->p); R = R->n; }
            p = p->n; q = q->n;
          
        } else if(p->p > q->p){
            R->n = new T(p->c, p->p); R = R->n; p = p->n;
        } else {
          
            R->n = new T(q->c, q->p); R = R->n; q = q->n;
        }
    }
    while(p){ R->n = new T(p->c, p->p); R=R->n; p=p->n; }
    while(q){ R->n = new T(q->c, q->p); R=R->n; q=q->n; }
    T* cur = dummy.n;
    if(!cur){ cout<<"0 0\n"; return 0; }
    bool first=true;
    while(cur){
        if(!first) cout<<" ";
      
        cout<<cur->c<<" "<<cur->p;
        first=false;
      
        cur=cur->n;}
    return 0;}

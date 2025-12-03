#include <bits/stdc++.h>
using namespace std;


struct N{ int v; N* n; N(int x):v(x),n(NULL){} };

N* make(vector<int>& a){ if(a.empty()) return NULL; N* h=new N(a[0]); N* c=h; for(size_t i=1;i<a.size();++i){ c->n=new N(a[i]); c=c->n;} return h; }

N* revK(N* head,int k){
    if(!head || k<=1) return head;
    N dummy(0);
    dummy.n = head;
  
    N* prev = &dummy;
    while(true){
      
        N* kth = prev;
      
        for(int i=0;i<k && kth;i++) kth = kth->n;
        if(!kth) break;
        N* cur = prev->n;
      
        N* next = cur->n;
        for(int i=1;i<k;i++){
            N* tmp = next->n;
            next->n = prev->n;
          
            prev->n = next;
            cur->n = tmp;
          
            next = tmp;
        }
        prev = cur;
    }
    return dummy.n;
}

int main(){

  
    ios::sync_with_stdio(false);
  
    cin.tie(NULL);
    int n; if(!(cin>>n)) return 0;
  
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int k; cin>>k;
    N* h = make(a);
    h = revK(h,k);
  
    bool first=true;
    for(N* p=h;p;p=p->n){
        if(!first) cout<<" ";
        cout<<p->v; first=false;
      
    }
    return 0;


  
}

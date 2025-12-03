#include <bits/stdc++.h>
using namespace std;
struct Node{ int v; Node* n; Node(int x):v(x),n(NULL){} };

Node* make(vector<int>& a){ if(a.empty()) return NULL; Node* h=new Node(a[0]); Node* c=h; for(size_t i=1;i<a.size();++i){ c->n=new Node(a[i]); c=c->n;} return h; }

int main(){
  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; if(!(cin>>n)) return 0;
  
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    long long k; cin>>k;
  
    if(n==0){ cout<<"\n"; return 0;}
    k = k % n;
    if(k==0){
        for(int i=0;i<n;i++){ if(i) cout<<" "; cout<<a[i]; } cout<<"\n"; return 0;
    }
    Node* head = make(a);
    Node* tail = head;
  
    while(tail->n) tail = tail->n;
    Node* cur = head;
    for(int i=1;i<k;i++) cur = cur->n;
  
    Node* newh = cur->n;
    cur->n = NULL;
    tail->n = head;
    bool first=true;
  
    Node* p=newh;
    while(p){
        if(!first) cout<<" ";
        cout<<p->v; first=false;
      
        p=p->n;
    }
    cout<<"\n";
    return 0;
}

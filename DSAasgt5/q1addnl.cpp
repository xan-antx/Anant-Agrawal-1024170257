#include <bits/stdc++.h>
using namespace std;
struct Node{ int v; Node* n; Node(int x):v(x),n(NULL){} };

Node* makeList(vector<int>& a){
    if(a.empty()) return NULL;
    Node* h = new Node(a[0]);
  
    Node* cur = h;
    for(size_t i=1;i<a.size();++i){ cur->n = new Node(a[i]); cur = cur->n; }
  
    return h;
}

int len(Node* h){ int c=0; while(h){ c++; h=h->n;} return c; }

int main(){

  
    ios::sync_with_stdio(false);
  
    cin.tie(NULL);
    int m,n;
    if(!(cin>>m>>n)) return 0;
  
    vector<int> A(m), B(n);
    for(int i=0;i<m;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];
  
    int pos; cin>>pos;
    Node* headA = makeList(A);
  
    Node* headB = makeList(B);
    if(pos>0){
        Node* t = headA;
        int cnt=1;
        while(t && cnt<pos){ t=t->n; cnt++; }
        if(t){
            if(headB==NULL){
                headB = t;  } else {
                Node* cur = headB;
                while(cur->n) cur=cur->n;
              
                cur->n = t;   } }
    }
    int la = len(headA), lb = len(headB);
  
    Node* pa = headA; Node* pb = headB;
  
    if(la>lb){
        int diff = la-lb;
        while(diff--) pa = pa->n;
      
    } else {
        int diff = lb-la;
        while(diff--) pb = pb->n;
      
    }
    int ans = -1;
    while(pa && pb){
        if(pa == pb){ ans = pa->v; break; }
        pa = pa->n; pb = pb->n;
    }
    return 0;
}

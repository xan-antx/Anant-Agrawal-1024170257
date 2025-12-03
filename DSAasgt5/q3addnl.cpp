#include <bits/stdc++.h>
using namespace std;

struct Node{ int v; Node* n; Node(int x):v(x),n(NULL){} };
Node* make(vector<int>& a){
    if(a.empty()) return NULL;
  
    Node* h=new Node(a[0]); Node* cur=h;
  
    for(size_t i=1;i<a.size();++i){ cur->n=new Node(a[i]); cur=cur->n;}
    return h;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; if(!(cin>>n)) return 0;
  
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
  
    int pos; cin>>pos;
    Node* head = make(a);
    if(pos>0){
        Node* tail=head; while(tail && tail->n) tail=tail->n;
      
        Node* target=head; int cnt=1;
        while(target && cnt<pos){ target=target->n; cnt++; }
      
        if(tail && target) tail->n = target;
    }
    // detect loop
    Node* slow=head; Node* fast=head;
    bool found=false;
    while(fast && fast->n){
        slow=slow->n;
        fast=fast->n->n;
        if(slow==fast){ found=true; break; }
    }
    if(!found){
        cout<<0<<"\n";
    } else {
        slow = head;
        if(slow==fast){
            while(fast->n != slow) fast = fast->n;
          
            fast->n = NULL;
        } else {
            while(slow->n != fast->n){
                slow = slow->n;
              
                fast = fast->n;
            }
            fast->n = NULL;
        }
        cout<<1<<"\n";
    }
    Node* cur = head;
    bool first=true;
  
    int limit=1000000;
    while(cur && limit--){
        if(!first) cout<<" ";
      
        cout<<cur->v; first=false;
        cur=cur->n;
    }
  
  return 0;
}

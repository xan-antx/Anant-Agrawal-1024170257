#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v; Node* l; Node* r;
    Node(int x): v(x), l(NULL), r(NULL) {}
};

Node* build(vector<int>& arr){
    if(arr.size()==0) return NULL;
    if(arr[0]==-1) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i=1;
    while(!q.empty() && i < (int)arr.size()){
        Node* cur = q.front(); q.pop();
        // left
        if(i < (int)arr.size()){
            if(arr[i] != -1){
                cur->l = new Node(arr[i]);
                q.push(cur->l);
            }
            i++;
        }
        // right
        if(i < (int)arr.size()){
            if(arr[i] != -1){
                cur->r = new Node(arr[i]);
                q.push(cur->r);
            }
            i++;
        }
    }
    return root;
}

int sumLeftLeaves(Node* r){
    if(!r) return 0;
    int sum = 0;
    if(r->l){
        if(!r->l->l && !r->l->r) sum += r->l->v;
        else sum += sumLeftLeaves(r->l);
    }
    if(r->r) sum += sumLeftLeaves(r->r);
    return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin>>n)) return 0;
    vector<int> a;
    a.reserve(n);
    for(int i=0;i<n;i++){ int x; cin>>x; a.push_back(x); }
    Node* root = build(a);
    int ans = sumLeftLeaves(root);
    cout<<ans<< endl;
    return 0;
}

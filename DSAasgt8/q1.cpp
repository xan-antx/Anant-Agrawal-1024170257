#include <iostream>
using namespace std;
struct nd{
    int v;
    nd *l,*r;
    nd(int x){ v=x; l=r=NULL; }
};
nd* newNode(int x){
    nd* t=new nd(x);
    return t;
}

void preTrav(nd* rt){
    if(rt==NULL) return;
    cout<<rt->v<<" ";
    preTrav(rt->l);
    preTrav(rt->r);
}

// in = left root right
void inTrav(nd* rt){
    if(rt==NULL) return;
    inTrav(rt->l);
    cout<<rt->v<<" ";
    inTrav(rt->r);
}

void postTrav(nd* rt){
    if(rt==NULL) return;
    postTrav(rt->l);
    postTrav(rt->r);
    cout<<rt->v<<" ";
}

int main(){
    nd* root = newNode(1);
    root->l = newNode(2);
    root->r = newNode(3);
    root->l->l = newNode(4);
    root->l->r = newNode(5);

    cout<<"Pre: ";
    preTrav(root);
    cout<<"\nIn: ";
    inTrav(root);
    cout<<"\nPost: ";
    postTrav(root);
    cout<<"\n";
    return 0;
}

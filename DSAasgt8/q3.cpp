#include <iostream>
using namespace std;

struct xyz{
    int k;
    xyz *l,*r;
    xyz(int x){ k=x; l=r=NULL; }
};

xyz* insertBST(xyz* rt,int x){
    if(rt==NULL) return new xyz(x);
    if(x<rt->k) rt->l = insertBST(rt->l,x);
    else if(x>rt->k) rt->r = insertBST(rt->r,x);
    return rt;
}
xyz* findMin(xyz* rt){
    while(rt && rt->l) rt=rt->l;
    return rt;
}
xyz* deleteBST(xyz* rt,int x){
    if(rt==NULL) return rt;
    if(x<rt->k) rt->l =deleteBST(rt->l,x);
    else if(x>rt->k) rt->r= deleteBST(rt->r,x);
    else{
        if(rt->l==NULL && rt->r==NULL){
            delete rt;
            return NULL;
        } else if(rt->l==NULL){
            xyz* t=rt->r;
            delete rt;
            return t;
        } else if(rt->r==NULL){
            xyz* t=rt->l;
            delete rt;
            return t;
        } else{
            xyz* t = findMin(rt->r);
            rt->k = t->k;
            rt->r = deleteBST(rt->r,t->k);
        }
    }
    return rt;
}

int maxDepth(xyz* rt){
    if(rt==NULL) return 0;
    int l = maxDepth(rt->l);
    int r = maxDepth(rt->r);
    return (l>r?l:r)+1;
}
int minDepth(xyz* rt){
    if(rt==NULL) return 0;
    if(rt->l==NULL && rt->r==NULL) return 1;
    if(rt->l==NULL) return minDepth(rt->r)+1;
    if(rt->r==NULL) return minDepth(rt->l)+1;
    int l = minDepth(rt->l);
    int r = minDepth(rt->r);
    return (l<r?l:r)+1;
}

void inorder(xyz* rt){
    if(!rt) return;
    inorder(rt->l);
    cout<<rt->k<<" ";
    inorder(rt->r);
}
int main(){
    xyz* root=NULL;
    int ch,x;
    while(1){
        cout<<"\n1 ins 2 del 3 inorder 4 maxDepth 5 minDepth 0 exit: ";
        cin>>ch;
        if(ch==0) break;
        if(ch==1){ cin>>x; root=insertBST(root,x); }
        else if(ch==2){ cin>>x; root=deleteBST(root,x); }
        else if(ch==3){ inorder(root); cout<<"\n"; }
        else if(ch==4){ cout<<"maxDepth="<<maxDepth(root)<<"\n"; }
        else if(ch==5){ cout<<"minDepth="<<minDepth(root)<<"\n"; }
    }
    return 0;
}


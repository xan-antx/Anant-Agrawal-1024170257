#include <iostream>
#include <limits.h>
using namespace std;

struct treecheck{
    int check;
    treecheck *l,*r;
    treecheck(int x){ check=x; l=r=NULL; }
};
treecheck* newN(int x){ return new treecheck(x); }
int isBSTutil(treecheck* rt,long long min,long long max){
    if(rt==NULL) return 1;
    if(rt->check <= min || rt->check >= max) return 0;
    return isBSTutil(rt->l,min,rt->check) && isBSTutil(rt->r,rt->check,max);
}
int isBST(treecheck* rt){
    return isBSTutil(rt, LLONG_MIN, LLONG_MAX);
}
int main(){  

  
    treecheck* roots = newN(10);
    roots->l = newN(5);
    roots->r = newN(15);
    roots->l->l = newN(2);
    roots->l->r = newN(7);
    if(isBST(roots)) cout<<"BST";
    else cout<<"Not BST";
    return 0;  

  
}

#include <iostream>
using namespace std;

struct bn{
    int k;
    bn *l,*r;
    bn(int x){ k=x; l=r=NULL; }
};
bn* ins(bn* rt,int x){
    if(rt==NULL) return new bn(x);
    if(x<rt->k) rt->l=ins(rt->l,x);
    else if(x>rt->k) rt->r=ins(rt->r,x);
    return rt;
}

bn* searchR(bn* rt,int x){
    if(rt==NULL || rt->k==x) return rt;
    if(x<rt->k) return searchR(rt->l,x);
    return searchR(rt->r,x);
}

bn* searchNR(bn* rt,int x){
    bn* t=rt;
    while(t!=NULL){
        if(x==t->k) return t;
        else if(x<t->k) t=t->l;
        else t=t->r;
    }
    return NULL;
}
bn* findMin(bn* rt){
    if(rt==NULL) return NULL;
    while(rt->l) rt=rt->l;
    return rt;
}

bn* findMax(bn* rt){
    if(rt==NULL) return NULL;
    while(rt->r) rt=rt->r;
    return rt;
}
bn* inorderSucc(bn* root,int x){
    bn* cur = root;
    bn* target = NULL;
    while(cur){
        if(x==cur->k){ target=cur; break; }
        else if(x<cur->k) cur=cur->l;
        else cur=cur->r;
    }
    if(target==NULL) return NULL;

    if(target->r) return findMin(target->r);

    bn* succ = NULL;
    bn* anc = root;
    while(anc!=target){
        if(target->k < anc->k){
            succ = anc;
            anc = anc->l;
        } else {
            anc = anc->r;
        }
    }
    return succ;
}

bn* inorderPred(bn* root,int x){
    bn* cur=root;
    bn* target=NULL;
    while(cur){
        if(x==cur->k){ target=cur; break; }
        else if(x<cur->k) cur=cur->l;
        else cur=cur->r;
    }
    if(target==NULL) return NULL;
    if(target->l) return findMax(target->l);
    bn* pred=NULL;
    bn* anc=root;
    while(anc!=target){
        if(target->k > anc->k){
            pred=anc;
            anc=anc->r;
        } else {
            anc=anc->l;
        }
    }
    return pred;
}

int main(){
    bn* rt=NULL;
    int a[]={20,10,30,5,15,25,35};
    for(int i=0;i<7;i++) rt=ins(rt,a[i]);
    int x;
    cout<<"enter key: ";
    cin>>x;

    bn* s1 = searchR(rt,x);
    bn* s2 = searchNR(rt,x);

    cout<<"Rec search: "<<(s1?"Found":"Not")<<"\n";
    cout<<"NonRec search: "<<(s2?"Found":"Not")<<"\n";
    bn* mx = findMax(rt);
    bn* mn = findMin(rt);
    if(mn) cout<<"Min: "<<mn->k<<"\n";
    if(mx) cout<<"Max: "<<mx->k<<"\n";
    bn* su = inorderSucc(rt,x);
    bn* pr = inorderPred(rt,x);
    if(su) cout<<"Succ: "<<su->k<<"\n";
    else cout<<"Succ: none\n";
    if(pr) cout<<"Pred: "<<pr->k<<"\n";
    else cout<<"Pred: none\n";

    return 0;
}

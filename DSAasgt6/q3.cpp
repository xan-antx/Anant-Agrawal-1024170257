#include <iostream>
using namespace std;

struct Dn{
    int d;
    Dn *p,*n;
    Dn(int x){ d=x; p=n=NULL; }
};
Dn* dh=NULL;
int sizeDLL(){
    int c=0;
    Dn* t=dh;
    while(t){
        c++;
        t=t->n;
    }
    return c;
}

struct Cn{
    int d;
    Cn* n;
    Cn(int x){ d=x; n=NULL; }
};

Cn* ch=NULL;

int sizeCLL(){
    if(ch==NULL) return 0;
    int c=0;
    Cn* t=ch;
    do{
        c++;
        t=t->n;
    }while(t!=ch);
    return c;
}

int main(){
    dh=new Dn(10);
    dh->n=new Dn(20);
    dh->n->p=dh;
    ch=new Cn(5);
    ch->n=ch;
    cout<<"DLL size= "<<sizeDLL();
    cout << endl;
    cout<<"CLL size= "<<sizeCLL();
}


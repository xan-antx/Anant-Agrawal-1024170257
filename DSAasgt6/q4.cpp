#include <iostream>
using namespace std;
struct Nd{
    char c;
    Nd* p;
    Nd* n;
    Nd(char x){ c=x; p=n=NULL; }
};
Nd* h=NULL;

void put(char x){
    Nd* t=new Nd(x);
    if(h==NULL){ h=t; return; }
    Nd* c=h;
    while(c->n) c=c->n;
    c->n=t;
    t->p=c;
}
int palin(){
    if(h==NULL) return 1;
    Nd* L=h;
    Nd* R=h;

    while(R->n) R=R->n;
    while(L!=R && L->p!=R){
        if(L->c!=R->c) return 0;
        L=L->n;
        R=R->p;
    }
    return 1;
}

int main(){
    string s;
    cin>>s;
    for(char x:s) put(x);
    if{(palin()) 
        cout<<"it is palindrone";
      }
    else cout<<"not a palindrome";
}

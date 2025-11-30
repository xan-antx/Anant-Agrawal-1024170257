#include <iostream>
using namespace std;
struct Node{
    int d;
    Node* n;
    Node(int x){ d=x; n=NULL; }
};
Node* h=NULL;

void addEnd(int v){
    Node* t=new Node(v);
    if(h==NULL){
        h=t; h->n=h;
        return;
    }
    Node* c=h;
    while(c->n!=h) c=c->n;
    c->n=t;
    t->n=h;
}
void printRepeat(){
    if(h==NULL) return;
    Node* c=h;
    cout<<c->d<<" ";
    c=c->n;
    while(c!=h){
        cout<<c->d<<" ";
        c=c->n;
    }
    cout<<h->d;
}

int main(){
    addEnd(20);
    addEnd(100);
    addEnd(40);
    addEnd(80);
    addEnd(60);
    printRepeat();
}

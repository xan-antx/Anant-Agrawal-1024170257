#include <iostream>
using namespace std;

struct Dnode{
    int d;
    Dnode *p,*n;
    Dnode(int x){
        d=x;
        p=NULL;
        n=NULL;
    }
};
Dnode *dh = NULL;  
void insFrontD(int v){
    Dnode* t=new Dnode(v);
    if(dh==NULL){
        dh=t;
    } else {
        t->n = dh;
        dh->p = t;
        dh = t;
    }
}

void insEndD(int v){
    Dnode* t=new Dnode(v);
    if(dh==NULL){
        dh=t; return;
    }
    Dnode* c=dh;
    while(c->n!=NULL) c=c->n;
    c->n=t;
    t->p=c;
}

int insAfterD(int key,int v){
    Dnode *c=dh;
    while(c!=NULL){
        if(c->d==key){
            Dnode* t=new Dnode(v);
            t->n = c->n;
            if(c->n) c->n->p = t;
            t->p = c;
            c->n=t;
            return 1;
        }
        c=c->n;
    }
    return 0;
}

int insBeforeD(int key,int v){
    if(dh==NULL) return 0;
    if(dh->d==key){
        insFrontD(v);
        return 1;
    }
    Dnode *c=dh;
    while(c!=NULL){
        if(c->d==key){
            Dnode *t=new Dnode(v);
            t->n=c;
            t->p=c->p;
            c->p->n=t;
            c->p=t;
            return 1;
        }
        c=c->n;
    }
    return 0;
}

int delD(int key){
    Dnode* c=dh;
    while(c){
        if(c->d==key){
            if(c==dh){
                dh = dh->n;
                if(dh) dh->p=NULL;
            } else {
                c->p->n = c->n;
                if(c->n) c->n->p = c->p;
            }
            delete c;
            return 1;
        }
        c=c->n;
    }
    return 0;
}

void printD(){
    cout<<"DLL: ";
    Dnode* c=dh;
    while(c){
        cout<<c->d<<" ";
        c=c->n;
    }
    cout<<"\n";
}

Dnode* findD(int key){
    Dnode* c=dh;
    while(c){
        if(c->d==key) return c;
        c=c->n;
    }
    return NULL;
}

struct Cnode{
    int d;
    Cnode* n;
    Cnode(int x){ d=x; n=NULL; }
};

Cnode* ch=NULL; // circular head

void insFrontC(int v){
    Cnode* t=new Cnode(v);
    if(ch==NULL){
        ch=t; t->n=t;
    } else{
        Cnode *c=ch;
        while(c->n!=ch) c=c->n;
        t->n=ch;
        c->n=t;
        ch=t;
    }
}

void insEndC(int v){
    Cnode *t=new Cnode(v);
    if(ch==NULL){
        ch=t; t->n=t; return;
    }
    Cnode *c=ch;
    while(c->n!=ch) c=c->n;
    c->n=t;
    t->n=ch;
}

int insAfterC(int key,int v){
    if(ch==NULL) return 0;
    Cnode* c=ch;
    do{
        if(c->d==key){
            Cnode* t=new Cnode(v);
            t->n=c->n;
            c->n=t;
            return 1;
        }
        c=c->n;
    }while(c!=ch);
    return 0;
}

int insBeforeC(int key,int v){
    if(ch==NULL) return 0;
    if(ch->d==key){
        insFrontC(v);
        return 1;
    }
    Cnode* c=ch;
    do{
        if(c->n->d==key){
            Cnode* t=new Cnode(v);
            t->n=c->n;
            c->n=t;
            return 1;
        }
        c=c->n;
    }while(c!=ch);
    return 0;
}

int delC(int key){
    if(ch==NULL) return 0;

    if(ch->d==key && ch->n==ch){
        delete ch; ch=NULL; return 1;
    }

    Cnode *c=ch, *p=NULL;
    do{
        if(c->d==key){
            if(c==ch){
                Cnode* last=ch;
                while(last->n!=ch) last=last->n;
                ch=ch->n;
                last->n=ch;
            } else {
                p->n = c->n;
            }
            delete c;
            return 1;
        }
        p=c;
        c=c->n;
    }while(c!=ch);

    return 0;
}

void printC(){
    if(ch==NULL){
        cout<<"CLL empty\n";
        return;
    }
    cout<<"CLL: ";
    Cnode* c=ch;
    do{
        cout<<c->d<<" ";
        c=c->n;
    }while(c!=ch);
    cout<<"\n";
}

Cnode* findC(int key){
    if(ch==NULL) return NULL;
    Cnode* c=ch;
    do{
        if(c->d==key) return c;
        c=c->n;
    }while(c!=ch);
    return NULL;
}
int main(){
    int listChoice, opt, a,b;

    while(1){
        cout<<"\n1-DLL 2-CLL 0-exit : ";
        cin>>listChoice;
        if(listChoice==0) break;

        if(listChoice==1){
            cout<<"1 IF 2 IE 3 IA 4 IB 5 DEL 6 SEARCH 7 PRINT: ";
            cin>>opt;
            if(opt==1){ cin>>a; insFrontD(a); }
            else if(opt==2){ cin>>a; insEndD(a); }
            else if(opt==3){ cin>>a>>b; insAfterD(a,b); }
            else if(opt==4){ cin>>a>>b; insBeforeD(a,b); }
            else if(opt==5){ cin>>a; delD(a); }
            else if(opt==6){ cin>>a; cout<<(findD(a)?"Found\n":"NF\n"); }
            else if(opt==7){ printD(); }
        }
        else if(listChoice==2){
            cout<<"1 IF 2 IE 3 IA 4 IB 5 DEL 6 SEARCH 7 PRINT: ";
            cin>>opt;
            if(opt==1){ cin>>a; insFrontC(a); }
            else if(opt==2){ cin>>a; insEndC(a); }
            else if(opt==3){ cin>>a>>b; insAfterC(a,b); }
            else if(opt==4){ cin>>a>>b; insBeforeC(a,b); }
            else if(opt==5){ cin>>a; delC(a); }
            else if(opt==6){ cin>>a; cout<<(findC(a)?"Found\n":"NF\n"); }
            else if(opt==7){ printC(); }
        }
    }
}

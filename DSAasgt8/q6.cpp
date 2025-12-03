#include <iostream>
using namespace std;

struct heap{
    int *arr;
    int sz;
    int cap;
};

heap* formheap(int c){
    heap* h=new heap;
    h->arr=new int[c];
    h->sz=0;
    h->cap=c;
    return h;
}

void swapinteger(int &x,int &y){ int t=x;x=y;y=t; }

void upHeap(heap* h,int i){
    while(i>0){
        int p=(i-1)/2;
        if(h->arr[p] < h->arr[i]){
            swapinteger(h->arr[p],h->arr[i]);
            i=p;
        } else break;
    }
}

void downHeap(heap* h,int i){
    while(true){
        int l=2*i+1, r=2*i+2, big=i;
        if(l<h->sz && h->arr[l]>h->arr[big]) big=l;
        if(r<h->sz && h->arr[r]>h->arr[big]) big=r;
        if(big!=i){
            swapinteger(h->arr[i],h->arr[big]);
            i=big;
        } else break;
    }}

void push(heap* h,int x){
    if(h->sz==h->cap){
        cout<<"full" << endl;
        return;
    }
    h->arr[h->sz]=x;
    h->sz++;
    upHeap(h,h->sz-1);}

int top(heap* h){
    if(h->sz==0) return -1;
    return h->arr[0];
}


int pop(heap* h){
    if(h->sz==0) return -1;
    int ans=h->arr[0];
    h->arr[0]=h->arr[h->sz-1];
    h->sz--;
    downHeap(h,0);
    return ans;
}


int main(){
    heap* h = formheap(100);
    int ch,x;
    while(1){
        cin>>ch;
        if(ch==0) break;
        if(ch==1){
            cin>>x;
            push(h,x);
        } else if(ch==2){
            int y=pop(h);
            if(y==-1) cout <<"empty\n";
            else cout <<"popped "<<y<< endl;
        } else if(ch==3){
            cout <<"top=" <<top(h)<< endl;
        } else if(ch==4){
            cout<<"size="<< h->sz<< endl;
        }
    }
    return 0;
}

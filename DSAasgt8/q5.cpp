#include <iostream>
using namespace std;
void heapmax(int a[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i){
        int t=a[i]; a[i]=a[largest]; a[largest]=t;
        heapmax(a,n,largest);
    }
}
void heapmin(int a[],int n,int i){
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]<a[smallest]) smallest=l;
    if(r<n && a[r]<a[smallest]) smallest=r;
    if(smallest!=i){
        int t=a[i]; a[i]=a[smallest]; a[smallest]=t;
        heapmin(a,n,smallest); }
}

void heapincsort(int a[],int n){
    for(int i=n/2-1;i>=0;i--) heapmax(a,n,i);
    for(int i=n-1;i>0;i--){
        int t=a[0]; a[0]=a[i]; a[i]=t;
        heapmax(a,i,0);   }}

void heapdecsort(int a[],int n){
    for(int i=n/2-1;i>=0;i--) heapmin(a,n,i);
    for(int i=n-1;i>0;i--){
        int t=a[0]; a[0]=a[i]; a[i]=t;
        heapmin(a,i,0);
    }
}

void printA(int a[],int n){
    for(int i=0;i<n;i++) {cout<<a[i]<<" ";}
    cout<< endl;}

int main(){
    int n; 
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++) {cin>>a[i];}
    int ch;
    cout<<"1-inc 2-dec : ";
    cin>>ch;
    if(ch==1){
        heapincsort(a,n);
    }else{
        heapdecsort(a,n);}

    printA(a,n);
    delete []a;
    return 0;

  
}

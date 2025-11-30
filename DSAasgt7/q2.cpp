
#include <iostream>
using namespace std;
void printArr(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i<n-1) cout<<" ";
    }
}
void improvedSelection(int a[], int n){
    int l = 0, r = n-1;
    while(l < r){
        int minindex = l;
        int maxindex = l;
        for(int k=l+1; k<=r; k++){
            if(a[k] < a[minindex]) minindex = k;
            if(a[k] > a[maxindex]) maxindex = k;
        }
        if(minindex != l){
            int t = a[l]; a[l] = a[minindex]; a[minindex] = t;
            if(maxindex == l) maxindex = minindex;
        }
        if(minindex != r){
            int t = a[r]; a[r] = a[maxindex]; a[maxindex] = t;
        }
        l++; r--;
    }
}
int main(){
    int n;
    cout<<"enter n: ";
    if(!(cin>>n)) return 0;
    int *a = new int[n];
    cout<<"enter "<<n<<" elements: ";
    for(int i=0;i<n;i++) cin>>a[i];
    improvedSelection(a,n);
    printArr(a,n);
    delete [] a;
    return 0;
}

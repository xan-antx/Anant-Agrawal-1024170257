#include<iostream>
using namespace std;
void print(int*arr,int n){
    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}
void bubblesort(int*arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    print(arr,n);
}
int main(){
    int arr[7]={64,34,25,12,22,11,90};
    bubblesort(arr,7);
    return 0;
}
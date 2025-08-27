#include<iostream>
#include<algorithm>
using namespace std;
int binarysearch(int *arr,int l,int n,int key){
int s=l;
int e=n-1;

while(s<=e){
    int mid=s+(e-s)/2;
    
    if(arr[mid]==key){
        return mid;

    }
    else if(arr[mid]<key){
        s=mid+1;
    }
    else{
        e=mid-1;

    }
    
}

return-1;
}
int main(){
    int arr[10]={1,3,7,5,8,9,4,2,6,10};
    sort(arr,arr+10);
    for(int i=0;i<=9;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int index=binarysearch(arr,0,10,5);
    if(index==-1){
    cout << "Element is not found" << endl;

   }
   else{
    cout << "Element is found at index: " << index << endl;
   }
    return 0;
}

























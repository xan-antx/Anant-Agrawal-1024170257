#include<iostream>
using namespace std;
int merge(int*arr,int s,int e){
    int mid=s+(e-s)/2;
    int l1=mid-s+1;
    int l2=e-mid;
    int*first=new int[l1];
    int*second=new int[l2];
    int mainarrayindex=s;
    for(int i=0;i<l1;i++){
        first[i]=arr[mainarrayindex++];
    }
    for(int i=0;i<l2;i++){
        second[i]=arr[mainarrayindex++];
    }
    int index1=0;
    int index2=0;
    int count=0;
    mainarrayindex=s;
    while(index1<l1 && index2<l2){
       if(first[index1]<=second[index2]){
        arr[mainarrayindex++]=first[index1++];
       }
       else{
        arr[mainarrayindex++]=second[index2++];
         count += l1 - index1; 

       }
    }
    while(index1<l1){
        arr[mainarrayindex++]=first[index1++];

    }
    while(index2<l2){
        arr[mainarrayindex++]=second[index2++];

    }
    delete[] first;
    delete[] second;
    return count;
}
int mergesort(int *arr,int s,int e){
     
    if(s>=e){
        return 0;
    }
    int mid=s+(e-s)/2;
    int count=0;
   
    count+=mergesort(arr,s,mid);
    count+=mergesort(arr,mid+1,e);
    count+=merge(arr,s,e);
    return count;

}
int main (){
    int arr[5]={2,5,1,6,9};
    int n=5;
   int inversion= mergesort(arr,0,n-1);
   cout << "Sorted array is: " << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << inversion << endl;
    
    return 0;
}
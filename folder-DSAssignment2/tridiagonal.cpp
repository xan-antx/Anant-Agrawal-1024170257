#include<iostream>
using namespace std;
int main(){
    int arr1[4][4]={{2,1,0,0},{3,1,3,0},{0,5,2,7},{0,0,9,0}};
    int arr2[10];
    int k=0;
    for(int i=0;i<4;i++){
     for(int j=0;j<4;j++){
        if(i-j==1 || i-j==0 || i-j==-1){
        arr2[k++]=arr1[i][j];
        }
     }
    }
    for(int i=0;i<10;i++){
        cout << arr2[i] << " ";
    }
    return 0;
}
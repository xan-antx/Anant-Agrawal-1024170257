#include<iostream>
using namespace std;
int main(){
    int arr1[4]={1,2,3,4};
    int arr2[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==j){
                arr2[i][j]=arr1[i];
            }
            else{
                arr2[i][j]=0;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
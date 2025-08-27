#include<iostream>
using namespace std;
int main(){
    int arr1[10]={1,2,3,4,5,6,7,8,9,0};
    int arr2[4][4];
    int k=0;
    for(int i = 0; i < 4; i++) {
        arr2[i][i] = 0;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<i;j++){
            arr2[i][j]=arr1[k++];

        }
    }
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            arr2[i][j]=arr2[j][i];
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
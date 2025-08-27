Lower traingular matrix
#include<iostream>
using namespace std;
int main(){
    int arr1[10]={2,5,1,0,3,1,4,2,7,0};
    int arr2[4][4];
    int k=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i>=j){
                arr2[i][j]=arr1[k++];
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

#include<iostream>
using namespace std;
int missingnumber(int*arr,int n){
    int sumofn_naturalno=n*(n+1)/2;
    int sumofarrayelement=0;
    for(int i=0;i<n;i++){
        sumofarrayelement+=arr[i];
    }
    int missingno=sumofn_naturalno-sumofarrayelement;
    return missingno;

}
int main(){
    int arr[5]={1,2,3,5};
    int element=missingnumber(arr,5);
    cout << element << endl;
    return 0;
}
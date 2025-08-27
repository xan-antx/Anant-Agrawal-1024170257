#include<iostream>
#include<cstring>
using namespace std;
void sortthesstring(char str[],int n){
for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
        if(str[j]>str[j+1]){
            swap(str[j],str[j+1]);
        }
    }
}
}
int main(){
    char str[10]="yash";
    int n=strlen(str);
    sortthesstring(str,n);
    cout << str << endl;
    return 0;
}
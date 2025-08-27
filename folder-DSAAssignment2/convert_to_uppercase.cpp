#include<iostream>
#include<cstring>
using namespace std;
void  convertuppercasetolowercase(char str1[],int n){
     strupr(str1);
}
int main(){
    char str1[10]="YAsh";
    int n=strlen(str1);
    convertuppercasetolowercase(str1,n);
    cout << str1<< endl;
    return 0;
}
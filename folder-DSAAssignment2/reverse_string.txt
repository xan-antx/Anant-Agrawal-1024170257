#include<iostream>
#include<cstring>
using namespace std;
void reversestring(char string1[],int n){
  int s=0;
  int e=n-1;
  while(s<e){
    swap(string1[s],string1[e]);
    s++;
    e--;
  }
  
}
int main(){
    char string1[10]="Yash";
    int len=strlen(string1);
   reversestring(string1,len);
   cout << string1 << endl;

    return 0;
}
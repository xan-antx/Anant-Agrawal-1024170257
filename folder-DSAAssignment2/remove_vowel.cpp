#include<iostream>
#include<cstring>
using namespace std;
bool isVowel(char ch){
 if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
        ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return true;
        }
        return false;

}
void removevowel(char str[]){
    int i=0;
    int j=0;
    while(str[i]!='\0'){
        if(!isVowel(str[i])){
            str[j]=str[i];
            j++;

        }
        i++;
    }
    str[j]='\0';

}
int main(){
 char str[10]="Beautiful";
 removevowel(str);
 cout << str << endl;
    return 0;
}
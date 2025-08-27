#include<iostream>
#include<cstring>
using namespace std;
void concatenate(char first_name[],char last_name[],char full_name[]){
strcpy(full_name,first_name);
strcat(full_name," ");
strcat(full_name,last_name);



}

int main(){
    char first_name[10]="Yash";
    char last_name[10]="Bhardwaj";
    char full_name[20];
    concatenate(first_name,last_name,full_name);
    cout << full_name << endl;

    return 0;
}
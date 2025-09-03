#include<iostream>
#include<string>
using namespace std;
#define MAX 50
class Anant{
    int arr[MAX];
    int top;
    public:
    Anant(){
        top=-1;
    }
    void push(int x)
{
    if(top==MAX-1){
        cout<<"stack is full"<<x<<endl;
    }
    else{
        arr[++top]=x;
    }
}
char pop(){
    if(top==-1){
        cout<<"stack is empty"<<endl;
    }
    else{
        return arr[top--];
    }
}
void display(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
        }
        else{
            cout<<"elements are :";
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    void reversestring(char s[]){
        int n=0;
        while(s[n]!='\0'){
            n++;
        }
        for(int i =0 ;i<n;i++){
           push(s[i]);
        }
        for(int i=0;i<n;i++){
            s[i]=pop();
        }
        cout<<"reversed string"<<s<<endl;
    }
};
int main(){
    Anant a;
    int choice;
    char vi[MAX];
    while(true){
        cout<<"1. Enter a string and reverse it\n";
        cout<<"2. Display current stack\n";
        cout<<"3. Exit\n";
        cout<<"Enter your choice ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"enter a string\n";
            cin>>vi;
            a.reversestring(vi);
            break;
            case 2:
            a.display();
            break;
            case 3:
            exit(0);
            default:
            cout<<"invalid choice";
        }
}
return 0;
}

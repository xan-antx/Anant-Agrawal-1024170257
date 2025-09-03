#include<iostream>
using namespace std;
#define MAX 100
class anant{
    int arr[MAX];
    int top;
    public:
    anant(){
        top=-1;
    }
    void push(int x){
        if(top==MAX-1){
            cout<<"stack is full"<<x<<endl;
        }
        else{
            arr[++top]=x;
            cout<<x<<"pushed in stack"<<endl;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
        }
        else{
            cout<<arr[top--];
            cout<<"popped from stack"<<endl;
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
    void peek(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
        }
        else{
            cout<<"top element is:"<<arr[top]<<endl;
        }
    }
};
int main(){
    anant a;
    int choice,value;
    while(true){
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Display\n";
        cout<<"5. Exit\n";
        cout<<"enter your choice";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"enter value to push";
            cin>>value;
            a.push(value);
            break;
            case 2:
            a.pop();
            break;
            case 3 :
            a.peek();
            case 4:
            a.display();
            break;
            case 5:
            exit(0);
            default:
            cout<<"invalid choice" << endl;
        }
    }
    return 0;
}

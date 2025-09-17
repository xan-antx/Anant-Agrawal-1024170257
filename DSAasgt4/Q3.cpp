#include <iostream>
#include <queue>
using namespace std;
void interleave(queue<int>& q) 
{
    int n=q.size();
    int half = n/2;
    queue<int>first;
    for (int i=0;i<half;i++) 
    {
        first.push(q.front());
        q.pop();
    }
    while (!first.empty()) 
    {
        q.push(first.front()); 
        first.pop();

        q.push(q.front()); 
        q.pop();
    }
}
int main() 
{
    queue<int> q;
    q.push(4); 
    q.push(7); 
    q.push(11); 
    q.push(20); 
    q.push(5); 
    q.push(9);

    interleave(q);

    cout<<"Output Queue:";
    while(!q.empty()) 
    {
        cout <<q.front()<<" ";
        q.pop();
    }
    return 0;
}

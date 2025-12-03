#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if(!(cin>>q)) return 0;
    string cmd;
    long long x;
    stack<long long> st;
    long long mn=0;
    bool has = false;
    while(q--){
        cin>>cmd;
        if(cmd=="push"){
            cin>>x;
            if(!has){
                st.push(x);
                mn = x;
                has = true;
            } else {
                if(x >= mn){
                    st.push(x);
                } else {
                    long long enc = 2*x - mn;
                    st.push(enc);
                    mn = x;
                }
            }
            cout<<"PUSH_OK\n";
        } else if(cmd=="pop"){
            if(!has || st.empty()){
                cout<<"EMPTY\n";
            } else {
                long long topv = st.top(); st.pop();
                if(topv < mn){
                    // encoded, recover old min
                    long long prevMin = 2*mn - topv;
                    // popped value was mn
                    mn = prevMin;
                }
                if(st.empty()) has = false;
                cout<<"POP_OK\n";
            }
        } else if(cmd=="top"){
            if(!has || st.empty()){
                cout<<"EMPTY\n";
            } else {
                long long t = st.top();
                if(t < mn){
                    cout<<mn<<"\n";
                } else cout<<t<<"\n";
            }
        } else if(cmd=="getMin"){
            if(!has || st.empty()){ cout<<"EMPTY\n"; }
            else cout<<mn<<"\n";
        } else {
            string rest;
            getline(cin,rest);
        }
    }
    return 0;
}

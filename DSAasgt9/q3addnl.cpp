#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,E;
    if(!(cin>>N>>E)) return 0;
    vector<vector<pair<int,int>>> adj(N+1);
    for(int i=0;i<E;i++){
        int u,v,w; cin>>u>>v>>w;
        if(u>=1 && u<=N && v>=1 && v<=N) adj[u].push_back({v,w});
    }
    int K; cin>>K;

    const ll INF = (1LL<<60);
    vector<ll> dist(N+1, INF);
    dist[K] = 0;
  
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
  
    pq.push({0, K});
    while(!pq.empty()){
        auto p=pq.top(); pq.pop();
        ll d = p.first; int u = p.second;
      
        if(d != dist[u]) continue;
      
        for(auto &ed : adj[u]){
            int v = ed.first; int w = ed.second;
          
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    ll mx = 0;
    for(int i=1;i<=N;i++){
        if(dist[i] == INF){ cout<<-1<<"\n"; return 0; }
        mx = max(mx, dist[i]);
    }
    cout<<mx<< endl;
    return 0;
  
}

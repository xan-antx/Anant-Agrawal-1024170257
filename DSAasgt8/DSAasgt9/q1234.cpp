#include <bits/stdc++.h>
using namespace std;
int Nnodes=0, Medges=0;

vector<vector<pair<int,int>>> adj;

vector<tuple<int,int,int>> edgesList;

void bfs(int src){
    vector<int> vis(Nnodes+1,0);
    queue<int> q;
    q.push(src);
    vis[src]=1;

    cout<<"bfs order: ";
    while(!q.empty()){
        int x=q.front(); q.pop();

        cout<<x<<" ";
        for(auto &p: adj[x]){
            int y=p.first;

            if(!vis[y]){

                vis[y]=1;
                q.push(y);
            }
         } }
    cout<< endl;
}

void dfsRecUtil(int u, vector<int>& vis){
    vis[u]=1;
    cout<<u<<"    ";
    for(auto &pp: adj[u]){
        int v=pp.first;
        if(!vis[v]) dfsRecUtil(v,vis);
    }}

void DFS(int src){
    vector<int> vis(Nnodes+1,0);
    cout<<"DFS order: ";
    dfsRecUtil(src,vis);
    cout<<"\n";
}

struct dsu {
    vector<int> p; vector<int> r;
    dsu(int n){ p.resize(n+1); r.resize(n+1,0); for(int i=0;i<=n;i++) p[i]=i; }
    int findp(int x){ if(p[x]==x) return x; return p[x]=findp(p[x]); }
    bool unite(int a,int b){
        a=findp(a); b=findp(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

void Kruskal(){
    vector<tuple<int,int,int>> E = edgesList;
    sort(E.begin(), E.end(), [](const tuple<int,int,int>& a, const tuple<int,int,int>& b){
        return get<2>(a) < get<2>(b);
    });
    dsu dsu(Nnodes);
    long long total=0;
    vector<tuple<int,int,int>> picked;
    for(auto &t: E){
        int u=get<0>(t);
        int v=get<1>(t);
        int w=get<2>(t);
        if(dsu.unite(u,v)){
            picked.push_back(t);
            total += w;
        }
    }
    cout<<"Kruskal MST edges (u v w):\n";
    for(auto &t: picked){
        cout<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<"\n";
    }
    cout<<"Total weight: "<<total<<"\n";
}

void Prim(){

    vector<int> used(Nnodes+1,0);
    long long tot=0;
    vector<tuple<int,int,int>> out;
    for(int start=1; start<=Nnodes; ++start){
        if(used[start]) continue;
        priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;
        pq.push(make_tuple(0, start, -1));
        while(!pq.empty()){
            auto t = pq.top(); pq.pop();
            int w = get<0>(t);
            int u = get<1>(t);
            int par = get<2>(t);
            if(used[u]) continue;
            used[u]=1;
            if(par != -1){
                out.push_back(make_tuple(par, u, w));
                tot += w;
            }
            for(auto &pp: adj[u]){
                int v = pp.first; int ww = pp.second;
                if(!used[v]) pq.push(make_tuple(ww, v, u));
            }
        }
    }
    cout<<"Prim MST edges (u v w): ";
    for(auto &t: out) cout<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<"\n";
    cout<<"Total weight: "<<tot<<  endl;
}

void Dijkstra(int src){
    const long long INF = (1LL<<60);
    vector<long long> dist(Nnodes+1, INF);
    vector<int> parent(Nnodes+1, -1);
    dist[src]=0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto pr = pq.top(); pq.pop();
        long long d = pr.first; int u = pr.second;
        if(d != dist[u]) continue;
        for(auto &pp: adj[u]){
            int v = pp.first; int w = pp.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    cout<<"Distances from "<<src<< endl;

    for(int i=1;i<=Nnodes;i++){

        if(dist[i]==INF) cout<<i<<": INF\n"; else cout<<i<<": "<<dist[i]<< endl;
    }

    int t; cin>>t;
    if(t>=1 && t<=Nnodes){
        if(dist[t]==INF){ cout<<"No path\n"; return; }
        vector<int> path;
        int cur=t;
        while(cur!=-1){
            path.push_back(cur);

            cur=parent[cur];
        }
        reverse(path.begin(), path.end());

        cout<<"Path: ";
        for(size_t i=0;i<path.size(); ++i){

            if(i) cout<<"->";
            cout<<path[i];
        }
        cout<<"\n";
    }
}


void readGraph(){
    cin>>Nnodes>>Medges;

    adj.assign(Nnodes+1, vector<pair<int,int>>()); 

    edgesList.clear();
    for(int i=0;i<Medges;i++){

        int u,v,w; cin>>u>>v>>w;
        if(u<1 || u> Nnodes || v<1 || v> Nnodes) {
            continue;
        }
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

        edgesList.push_back(make_tuple(u,v,w));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    readGraph();

    while(true){
        int ch; if(!(cin>>ch)) break;
        if(ch==0) break;
        if(ch==1){
            cout<<"source: "; int s; cin>>s;

            if(s<1 || s> Nnodes) cout<<"bad src\n"; else bfs(s);
        } else if(ch==2){

            cout<<"source: "; int s; cin>>s;
            if(s<1 || s> Nnodes) cout<<"bad src\n"; else DFS(s);
        } else if(ch==3){
            Kruskal();

        } else if(ch==4){
            Prim();
        } else if(ch==5){

            cout<<"source: "; int s; cin>>s;

            if(s<1 || s> Nnodes) cout<<"bad src\n"; else Dijkstra(s);
        } else {
            cout<<"Invalid\n";
        }
    }
    return 0;
}

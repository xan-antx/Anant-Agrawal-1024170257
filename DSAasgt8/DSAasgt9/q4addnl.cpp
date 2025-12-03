#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int bye,hi; if(!(cin >> bye>>hi)) return 0;

    vector<vector<int>> g(bye, vector<int>(hi));
    for(int i=0;i< bye;i++){

        for(int j=0;j<hi;j++) cin>>g[i][j];
    }
    vector<vector<int>> vis(bye, vector<int>(hi,0));

    int countt=0;
    int dr[4]={1,-1,0,0}, dc[4]={0,0,1,-1};

    for(int i=0;i<bye;i++){
        for(int j=0;j<hi;j++){
            if(vis[i][j] || g[i][j]==0) continue;

            countt++;
            queue<pair<int,int>> q; q.push({i,j}); vis[i][j] = 1;
            while(!q.empty() ){
                auto p = q.front(); q.pop();
                int r=p.first, c=p.second;

                for(int k=0;k<4;k++){
                    int nr=r+dr[k], nc=c+dc[k];

                    if(nr<0||nr>=bye||nc<0||nc>=hi) continue;

                    if( !vis[nr][nc] && g[nr][nc]==1){
                        vis[nr][nc] =1;
                        q.push({nr,nc});
                    }            }
            }       }    }
    return 0;
}

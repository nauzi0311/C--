#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > make_adjl();
void bfs(vector<vector<int> > G,queue<int>& q,vector<int>& dist);

int main(int argc, char const *argv[])
{
    vector<vector<int> > G = make_adjl();
    vector<int> dist(G.size(),-1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    bfs(G,q,dist);

    for (int v = 0; v < G.size(); ++v){
      cout << v+1 << " " << dist[v] << endl;  
    } 
    return 0;
}

void bfs(vector<vector<int> > G,queue<int>& q,vector<int>& dist){
   while (!q.empty())
   {
       int node = q.front();
       q.pop();
       for(int i = 0;i < G[0].size();i++){
           if(G[node][i] == 1){
               if(dist[i] != -1) continue;
               dist[i] = dist[node] + 1;
               q.push(i);
           }
       }
   }
}

vector<vector<int> > make_adjl(){
    int n;
    cin >> n;
    vector<vector<int> > G(n,vector<int>(n,0));
    for(int i = 0;i < n;i++){
        int u,k;
        cin >> u;
        cin >> k;
        for(int j = 0;j < k;j++){
            int v;
            cin >> v;
            G[u-1][v-1] = 1;
        }
    }
    return G;
}
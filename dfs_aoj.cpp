#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > make_adjl();
int dfs(vector<vector<int> > G,int node,int time,vector<vector<int> >& stamp);

int main(int argc, char const *argv[])
{
    vector<vector<int> > G = make_adjl();
    vector<vector<int> > stamp(2,vector<int>(G.size(),0));
    int time;
    time = dfs(G,0,1,stamp);
    for(int i = 0;i < G.size();i++){
        if(stamp[0][i] == 0) {
            time = dfs(G,i,time,stamp);
            i = 0;
        }
    }
    for(int i = 0;i < G.size();i++){
        cout << i+1 << " " <<stamp[0][i] << " " << stamp[1][i] << endl;
    }
    return 0;
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

int dfs(vector<vector<int> > G,int node,int time,vector<vector<int> >& stamp){
    vector<int> list = G[node];
    int size = list.size();
    stamp[0][node] = time++;
    for(int i = 0;i < size;i++){
        if(list[i] == 1){
            if(stamp[0][i] == 0){
                time = dfs(G,i,time,stamp);
            }
        }
    }
    stamp[1][node] = time++;
    return time;
}

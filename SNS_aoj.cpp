#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > make_adjl();
void bfs(vector<vector<int> > G,queue<int>& q,vector<int>& dist);

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n;
    cin >> m;
    vector<vector<int> > G(n);
    //make_adjl
    for(int i = 0;i < m;i++){
        int from,to;
        cin >> from >> to;
        G[from].push_back(to);
        G[to].push_back(from);
    }
    vector<int> dist(G.size(),-1);
    queue<int> q;
    // cout << "G = {" << endl;
    // for(int i = 0;i < G.size();i++){
    //     cout << "{";
    //     for(int j : G[i]){
    //         cout << j << ",";
    //     }
    //     cout << "}," << endl;
    // }
    // cout << "}" << endl;
    q.push(0);
    dist[0] = 0;
    //bfs
    while (!q.empty())
    {
       int node = q.front();
       q.pop();
       for(int i : G[node]){
            if(dist[i] != -1) continue;
            dist[i] = dist[node] + 1;
            q.push(i);  
       }
    }
    int treec = 1;
    for(int i = 0;i < G.size();i++){
        if((dist[i] == -1) && (!G[i].empty())){
            // cout << "before:" << endl;
            // for(int k:dist){
            //     cout << k << " ";
            // }
            // cout << endl;
            q.push(i);
            dist[i] = G.size() * treec++;
            //bfs
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for(int i : G[node]){
                        if(dist[i] != -1) continue;
                        dist[i] = dist[node] + 1;
                        q.push(i);  
                }
            }
            // cout << "after:" << endl;
            // for(int k:dist){
            //     cout << k << " ";
            // }
            // cout << endl;
        }
    }
    int qnum;
    cin >> qnum;
    for(int i = 0;i < qnum;i++){       
        int from,to;
        cin >> from;
        cin >> to;
        if(dist[from] == -1){
            cout << "no" << endl;
        }else{
            if((dist[from]/G.size()) == (dist[to]/G.size())){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
        
    }
    return 0;
}

void bfs(vector<vector<int> > G,queue<int>& q,vector<int>& dist){
   while (!q.empty())
   {
       int node = q.front();
       q.pop();
       for(int i : G[node]){
            if(dist[i] != -1) continue;
            dist[i] = dist[node] + 1;
            q.push(i);  
       }
   }
}

vector<vector<int> > make_adjl(){
    int n,m;
    cin >> n;
    cin >> m;
    vector<vector<int> > G(n);
    for(int i = 0;i < m;i++){
        int from,to;
        cin >> from >> to;
        G[from].push_back(to);
        G[to].push_back(from);
    }
    return G;
}
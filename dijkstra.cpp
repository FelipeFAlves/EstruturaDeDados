#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int N = 9;

vector<vector<pair<int, int>>> adj(N); // Adjacency list
vector<int> dist(N,INF);
vector<int> pred(N,-1);
vector<int> visitado(N,0); // N elementos com valor 0
priority_queue<pair<int,int>> q;

void dijkstra(int s);

void dijkstra(int s){
    dist[s] = 0;
    q.push( {0,s} );
    while(!q.empty()){
        int a = q.top().second;
        q.pop();

        if(visitado[a]) continue;
        visitado[a] = 1;

        for(auto u: adj[a]){
            int b = u.first;
            int w = u.second;

            if(dist[a] + w <dist[b]){
                dist[b] = dist[a] + w;
                pred[b] = a;
                q.push( {-dist[b],b} );
            }
        }
    }
}


int main(){
    adj[0].push_back({1, 4});
    adj[0].push_back({7, 8});
    adj[1].push_back({0, 4});
    adj[1].push_back({2, 8});
    adj[1].push_back({7, 11});
    adj[2].push_back({1, 8});
    adj[2].push_back({3, 7});
    adj[2].push_back({8, 2});
    adj[2].push_back({5, 4});
    adj[3].push_back({2, 7});
    adj[3].push_back({4, 9});
    adj[3].push_back({5, 14});
    adj[4].push_back({3, 9});
    adj[4].push_back({5, 10});
    adj[5].push_back({2, 4});
    adj[5].push_back({3, 14});
    adj[5].push_back({4, 10});
    adj[5].push_back({6, 2});
    adj[6].push_back({5, 2});
    adj[6].push_back({7, 1});
    adj[6].push_back({8, 6});
    adj[7].push_back({0, 8});
    adj[7].push_back({1, 11});
    adj[7].push_back({6, 1});
    adj[7].push_back({8, 7});
    adj[8].push_back({2, 2});
    adj[8].push_back({6, 6});
    adj[8].push_back({7, 7});

    dijkstra(0);

    // Print shortest distances
    for (int i = 0; i < N; ++i) {
        cout << "Do nó " << 0 << " para o nó " << i << " a distância é " << dist[i] << endl;
    }
    return 0;
}
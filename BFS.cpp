#include <bits/stdc++.h>
using namespace std;
#define N 10
int INF  = -1;

int m[N][N]; // matriz de adjacencia
int dist[N];
queue<int> fila;

void bfs(int s){
    int i,u;
    dist[s] = 0;
    fila.push(s);
    while(!fila.empty()){
        u = fila.front();
        fila.pop();
        printf("%d ",u);
        for( i =0;i<N;i++){
            if(dist[i] == INF && m[u][i]){
                dist[i] = dist[u] +1;
                fila.push(i);
            }
        }
    }


}
int main(){
    srand(time(0));
    memset(dist, INF, sizeof(dist));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int num = rand() % 2; // zero ou 1
            m[i][j] = num;
        }
    }
    bfs(0);
    
    return 0;
}
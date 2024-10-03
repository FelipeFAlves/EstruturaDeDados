#include <bits/stdc++.h>
using namespace std;
#define N 100

vector<int> adj[N]; //Lista de adjacência
int visitado[N]; // LIsta de adjacência

void dfs_list(int u){
    if(!visitado[u]){
        visitado[u] = 1;
        printf("%d ", u);

        for(auto i: adj[u]){
            dfs_list(i);
        }
    }
}

int main(){
    srand(time(0));
    for(int i=0;i<250;i++){
        int num = rand() % 26;
        adj->push_back(num);
    }
    dfs_list(0);

    return 0;
}
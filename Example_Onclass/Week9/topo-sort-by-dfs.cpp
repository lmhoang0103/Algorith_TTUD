#include <bits/stdc++.h>
using namespace std;
#define N 1000001
vector<int> A[N];
bool visited[N];
int n,m;
vector<int> nodes;
void input(){
    cin >> n >> m;
    for(int i = 1; i <=  m; i++){
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
    }
}
void DFS(int u){
    visited[u] = true;
    for(int i = 0; i < A[u].size(); i++){
        int v = A[u][i];
        if(!visited[v]){
            DFS(v);
        }
    }
    nodes.push_back(u);
}
int main(){
    freopen("topo-sort.txt","r",stdin);
    input();
    for(int v = 1; v <= n; v++) visited[v] = false;
    for(int v = 1; v <= n; v++) if(!visited[v]){
        DFS(v);
    }
    for(int i = 0; i < nodes.size(); i++) cout << i << ": " << nodes[i] << endl;
    return 0;
}

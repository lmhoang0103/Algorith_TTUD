#include <bits/stdc++.h>
using namespace std;
#define N 100001
vector<int> A[N]; // A[v] is the list of adjacent nodes of v
int n,m;
bool visited[N]; // visited[v] = true means that v has been visited
stack<int> S;
void input(){
    cin >> n >> m;
    for(int i =1; i <= m; i++){
        int u,v;
        cin >> u >> v; // read an arc (u,v)
        A[u].push_back(v);
        //A[v].push_back(u); // do not do this as the graph is directed
    }
}
void DFS(int u){
    visited[u] = true;
    for(int i = 0; i < A[u].size(); i++){
        int v = A[u][i];
        if(!visited[v]){ // v is not visited
            DFS(v);
        }
    }
    S.push(u);
}
void solve(){
    for(int v = 1;v <= n; v++) visited[v] = false;
    for(int v = 1; v <= n; v++)if(visited[v] == false){
        DFS(v);
    }

    while(!S.empty()){
        int u = S.top(); S.pop();
        cout << u << " ";
    }
}
int main(){
    freopen("topo-sort.txt","r",stdin);
    input();
    solve();
    return 0;
}

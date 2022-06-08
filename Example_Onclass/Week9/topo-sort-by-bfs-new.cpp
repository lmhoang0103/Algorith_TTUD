#include <bits/stdc++.h>
using namespace std;
#define N 100001
vector<int> A[N]; // A[v] is the list of adjacent nodes of v
int n,m;
bool visited[N]; // visited[v] = true means that v has been visited
int d[N]; // d[v] is the in-degree of the node v
void input(){
    cin >> n >> m;
    for(int v = 1; v <= n; v++) d[v] = 0;

    for(int i =1; i <= m; i++){
        int u,v;
        cin >> u >> v; // read an arc (u,v)
        A[u].push_back(v);
        //A[v].push_back(u); // do not do this as the graph is directed
        d[v] ++ ;
    }
}
void solve(){
    queue<int> Q;
    for(int v = 1; v <= n; v++) if(d[v] == 0){
        Q.push(v);
    }
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        cout << u << " "; // push node u to the TOPO list
        // remove out-going arc from u
        for(int i = 0; i < A[u].size(); i++){
            int v = A[u][i];// v is an adjacent node of u
            d[v] -= 1;
            if(d[v] == 0) Q.push(v);
        }
    }
}

int main(){
    freopen("topo-sort.txt","r",stdin);
    input();
    solve();
    return 0;
}

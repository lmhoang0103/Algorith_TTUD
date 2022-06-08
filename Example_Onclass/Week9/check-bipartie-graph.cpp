#include <bits/stdc++.h>
using namespace std;
#define N 100001
vector<int> A[N]; // A[v] is the list of adjacent nodes of v
int n,m;
int d[N]; // d[v] is distance from the starting node during BFS to v
void input(){
    cin >> n >> m;
    for(int i =1; i <= m; i++){
        int u,v;
        cin >> u >> v; // read an edge (u,v)
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
bool BFS(int s){
    queue<int> Q;
    Q.push(s); d[s] = 0;
    //cout << "Init push " << s << endl;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        //cout << "Pop " << u << " d[" << u << "] = " << d[u] << endl;
        for(int i = 0; i < A[u].size(); i++){
            int v = A[u][i];// v is an adjacent node of u
            if(d[v] > -1){// v has been visited
                //cout << "From u = " << u << " detect v = " << v << " d[" << u << "] = " << d[u] << " d[" << v << "] = " << d[v] << endl;
                if(d[u]%2 == d[v]%2){
                        //cout << "From u = " << u << " detect v = " << v << " d[" << u << "] = " << d[u] << " d[" << v << "] = " << d[v] << " -> FALSE" << endl;
                        return false;
                }
            }else{
                Q.push(v);
                d[v] = d[u] + 1;
                //cout << "Push v = " << v << " d = " << d[v] << endl;
            }
        }
    }
    return true;
}
void solve(){
    bool ok = true;
    for(int v = 1; v <= n; v++) d[v] = -1; // v is not visited
    for(int v = 1; v <= n; v++) if(d[v] == -1){
        if(BFS(v) == false){
            ok = false; break;
        }
    }
    if(ok) cout << "The given graph is bipartie" << endl;
    else cout << "The given graph is NOT bipartie graph" << endl;
}
int main(){
    freopen("bipartie.txt","r",stdin);
    input();
    solve();
    return 0;
}

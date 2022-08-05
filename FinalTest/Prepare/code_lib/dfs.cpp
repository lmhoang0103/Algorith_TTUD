#include <bits/stdc++.h>
using namespace std;
const int MAX = 50000;

vector<int> Adj[1001];
vector<bool> bVisited(1001, false);
vector<bool> bMarked(1001, false);

void DFS(int u)
{
    if (bMarked[u])
        return;
    bMarked[u] = true;
    bVisited[u] = true;
    for (int i = 0; i < Adj[u].size(); ++i)
    {
        int v = Adj[u][i];
        bVisited[v] = true;
        DFS(v);
    }
}

int n, m;
vector<vector<int>> vt;
bool mark[MAX];
void input()
{
    cin >> n >> m;
    vt.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        vt[tmp1].push_back(tmp2);
        vt[tmp2].push_back(tmp1);
    }
}

void explore(int x)
{
    mark[x] = true;
    for (int v : vt[x])
    {
        if (!mark[v])
        {
            explore(v);
        }
    }
}

void dfs(int a)
{
    for (int i = 1; i <= n; i++)
    {
        if (!mark[i])
        {
            explore(i);
        }
    }
}

int main()
{
    input();
    dfs(1);
    return 0;
}

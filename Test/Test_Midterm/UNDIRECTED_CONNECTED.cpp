#include <bits/stdc++.h>
using namespace std;
const long long Max = 100001;

int n, m;
vector<int> A[Max]; // A[v] la` cac dinh ke voi v
int visited[Max];
int ans;

void input()
{
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    A[u].push_back(v);
    A[v].push_back(u);
  }
}

void init()
{
  for (int i = 1; i <= n; i++)
  {
    visited[i] = 0;
  }
}

void DFS(int u)
{
  for (int j = 0; j < A[u].size(); j++)
  {
    int v = A[u][j];
    if (!visited[v])
    {
      visited[v] = 1;
      DFS(v);
    }
  }
}

void solve()
{
  init();
  ans = 0;
  for (int v = 1; v <= n; v++)
  {
    if (!visited[v])
    {
      ans++; // Moi lan xet DFS(v) se co het 1 thanh phan lien thong chua v; moi lan co diem chua tham la tien hanh tang so thanh phan lien thong len 1
      DFS(v);
    }
  }
  cout << ans;
}
int main()
{
  int t;
  cin >> t;
  while (t > 0)
  {
    input();
    solve();
    t--;
  }

  return 0;
}
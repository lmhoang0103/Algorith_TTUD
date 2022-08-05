#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;

int n, m;
vector<int> A[MAX];
vector<int> A1[MAX];

int f[MAX];
char color[MAX];
int t;
int icc[MAX];
int ans;
int x[MAX];
int idx;

void input()
{
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    A[u].push_back(v);
  }
}

void dfsA(){};
void buildResidualGraph(){};
void solve()
{
  dfsA();
  buildResidualGraph();
  dfsA1();
  cout << ans;
}

int main()
{
  input();
  solve();
  return 0;
}
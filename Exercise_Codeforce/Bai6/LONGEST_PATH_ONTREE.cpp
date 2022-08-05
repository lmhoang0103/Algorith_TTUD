#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;

int n;
vector<int> A[MAX]; // A[v][i] is the i^th node to v
vector<int> w[MAX]; // c[v]][i] is the weight of the i^th edge to v
int d[MAX];         // d[v] is the distance from the source node to v in BFS
int p[MAX];         // p[v] is the parent of v in BFS
int ans;

void input()
{
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    /* code */
    int u, v, ww;
    cin >> u >> v >> ww;
    A[v].push_back(u);
    A[u].push_back(v);
    w[v].push_back(ww);
    w[u].push_back(ww);
  }
}

// Khoi tao moi khi bat dau BFS
void init()
{
  for (int i = 1; i <= n; i++)
  {
    /* code */
    d[i] = -1;
    p[i] = -1;
  }
}

// duyet cac node tu u
void BFS(int u)
{
  queue<int> Q;
  d[u] = 0;
  Q.push(u);
  while (!Q.empty())
  {
    /* code */
    int v = Q.front();
    Q.pop();
    for (int i = 0; i < A[v].size(); i++)
    {
      int x = A[v][i];
    }
  }
}

// tra ve node xa nhat hien tai()
int findMax()
{
}

void solve()
{
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  cout << ans;
  return 0;
}
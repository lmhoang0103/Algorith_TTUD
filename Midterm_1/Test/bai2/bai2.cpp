#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int n, m;
int a[MAX][MAX];
int s[MAX];
unsigned long long ans;

void input()
{
  ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    s[i] = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
      if (a[i][j] == 0)
        s[j] = 0;
    }
  }
  for (int i = 0; i < n; i++)
    ans = ans + s[i];
}

void solve()
{
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("Testcase_3 (1).txt", "r", stdin);
  input();
  cout << ans;

  return 0;
}
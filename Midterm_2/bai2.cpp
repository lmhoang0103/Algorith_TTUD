#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int n, m;
int a[MAX][MAX];
unsigned long long ans;

void input()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}
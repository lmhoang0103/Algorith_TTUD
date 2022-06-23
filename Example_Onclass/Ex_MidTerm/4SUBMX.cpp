#include <bits/stdc++.h>
using namespace std;
const int MAX = 10001;
int n, k;
int a[MAX];
long long sum[MAX][MAX];
double avg[MAX][MAX];
double ans = 0.0;

void input()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      if (i == j)
        sum[i][j] = a[i];
      sum[i][j] = sum[i][j - 1] + a[j];
    }
  }
}
void solve()
{
  for (int i = 0; i < n - k; i++)
  {
    for (int j = i + k - 1; j < n; j++)
    {
      if (a[j] < ans)
        continue;
      double tmp = (double)sum[i][j] / (j - i + 1);
      if (tmp > ans)
        ans = tmp;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  printf("%.5lf", ans);
  return 0;
}
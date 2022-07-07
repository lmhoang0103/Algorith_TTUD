#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int n;
int a[MAX];
int s[MAX];
int ans;

void input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    // cout << a[i];
  }
}

void solve()
{
  ans = 0;
  for (int i = 1; i < n - 1; i++)
  {
    if (a[i] > a[i - 1] && a[i] > a[i + 1])
    {
      ans = ans + 1;
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
  cout << ans;
  return 0;
}
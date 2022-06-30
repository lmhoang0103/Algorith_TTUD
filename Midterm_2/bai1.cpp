#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int n;
int a[MAX];
int s[MAX];
unsigned long long ans;

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
  s[0] = 1;
  ans = 0;
  for (int i = 1; i < n - 1; i++)
  {
    if (a[i] < a[i - 1])
    {
      s[i] = s[i - 1] + 1;
    }
    else
    {
      s[i] = 1;
    }

    // ans = max(ans, s[i]);
    if (s[i] > ans)
      ans = s[i];
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
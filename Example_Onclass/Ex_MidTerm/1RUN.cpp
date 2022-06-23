#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000000];
int ans = 1;
void input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
}

void solve()
{
  for (int i = 1; i < n; i++)
  {
    if (a[i] <= a[i - 1])
      ans += 1;
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
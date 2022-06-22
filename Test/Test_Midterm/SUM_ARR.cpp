#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    ans += tmp;
  }
  cout << ans;
  return 0;
}
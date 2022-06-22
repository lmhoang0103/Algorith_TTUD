#include <bits/stdc++.h>
using namespace std;

const long long Max = 10005;
long long n, c;
long long location[Max];
long long maxLocaton;
long long ans;

void input()
{
  cin >> n >> c;
  maxLocaton = 0;
  for (long long i = 0; i < n; i++)
  {
    cin >> location[i];
    maxLocaton = max(maxLocaton, location[i]);
  }
  sort(location, location + n);
  ans = 0;
}

void solve(long long start, long long end)
{
  if (start > end)
    return;
  long long mid = (start + end) / 2;
  long long fi = location[0];
  long long cnt = 1;

  for (long long i = 1; i < n; i++)
  {
    if (location[i] - fi >= mid)
    {
      fi = location[i];
      cnt++;
    }
  }

  if (cnt < c)
    solve(start, mid - 1);
  else
  {
    ans = mid;
    solve(mid + 1, end);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t > 0)
  {
    input();
    solve(0, maxLocaton);
    cout << ans << endl;
    t--;
  }
  return 0;
}
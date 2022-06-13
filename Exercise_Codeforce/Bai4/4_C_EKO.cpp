#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1000000;

long long n, m;
long long height[MAX];
long long maxHeight;

void input()
{
  cin >> n >> m;
  maxHeight = 0;
  for (long long i = 0; i < n; i++)
  {
    cin >> height[i];
    maxHeight = max(maxHeight, height[i]);
    // cout << maxHeight;
  }
}

// if cut at "cut", how many meter of wood do you get
long long totalMeterOfWood(long long cut)
{
  long long sum = 0;
  for (long long i = 0; i < n; i++)
  {
    long long tmp = height[i] - cut;

    if (tmp < 0)
      tmp = 0;
    sum = sum + tmp;
  }
  return sum;
}

long long solve(long long left, long long right)
{
  long long mid = (left + right) / 2;
  long long total = totalMeterOfWood(mid);
  if (right - left == 1 || total == m)
  {
    return mid;
  }
  else
  {
    if (total < m)
      return solve(left, mid);
    else
      return solve(mid, right);
  }
}

int main()
{
  // Them 2 dong nay cho nhung bai can nhap cin, cout dai`
  // cin.tie(NULL) tat' auto flush cin
  // ios_base::sync_with_stdio(false);: tat dong` bo hoa I/O cua C va C++
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  cout << solve(0, maxHeight);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

const unsigned long long P = 1000000000 + 7;

int reValue(int n)
{
  int buffer = n / P;
  int result = n - buffer * P;
  return result;
}

int main()
{
  unsigned long long x, y;
  cin >> x >> y;

  x = reValue(x);
  y = reValue(y);

  unsigned long long S;
  S = x + y;

  S = reValue(S);
  cout << S;

  return 0;
}

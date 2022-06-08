#include <bits/stdc++.h>
using namespace std;

const int p = 1000000000 + 7;

int modP(unsigned long long value)
{
  while (value > p)
  {
    value = value - p;
  }
  return value;
}

int main()
{
  int n;
  cin >> n;
  int S = 0;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    tmp = modP(tmp);
    S = S + tmp;
    S = modP(S);
  }

  cout << S;
  return 0;
}

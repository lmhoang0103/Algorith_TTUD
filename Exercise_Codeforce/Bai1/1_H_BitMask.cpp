#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, m;
  int a[31];
  int b[31];
  int check = 1;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  for (int i = 0; i < m; i++)
  {
    int j = 0;
    while (j < n)
    {
      if (b[i] == a[j])
        break;
      j = j + 1;
    }
    if (j == n)
    {
      check = 0;
      break;
    }
  }
  cout << check;
  return 0;
}
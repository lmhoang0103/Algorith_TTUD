#include <bits/stdc++.h>
using namespace std;

int n, b;

vector<int> arr;

void input()
{
  cin >> n >> b;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    arr.push_back(tmp);
  }
}

// Max cua arr[i] toi arr [j]
int indexMax(int i, int j)
{
  int indexMax = i;
  for (int k = i; k < j; k++)
  {
    if (arr[k] > arr[indexMax])
      indexMax = k;
  }
  return indexMax;
}

void solve()
{
  input();
  int indexMaxLeft = 0;
  int indexMaxRight = 0;
  int m = indexMax(0, n);
  int ans = -1;

  for (int i = 1; i < m; i++)
  {

    indexMaxLeft = arr[indexMaxLeft] > arr[i] ? indexMaxLeft : i;
    if (arr[indexMaxLeft] - arr[i] >= b && arr[m] - arr[i] >= b)
    {
      int k = arr[m] + arr[indexMaxLeft] - 2 * arr[i];
      ans = max(ans, k);
    }
  }

  for (int i = n - 2; i > m; i--)
  {
    indexMaxRight = arr[indexMaxRight] > arr[i] ? indexMaxRight : i;
    if (arr[m] - arr[i] > b && arr[indexMaxRight] - arr[i] > b)
    {
      int k = arr[m] + arr[indexMaxRight] - 2 * arr[i];
      ans = max(ans, k);
    }
  }

  cout << ans;
}

int main()
{

  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAX = 51;
int n, b;
int a[MAX];
int ans;
// 0 la giua 0 va 1, 1 la giua 1 va 2, ..
// gia tri 0 la tru, 1 la cong
// gia tri cuoi la x[n-1] giua a[n-1] va a[n]
int x[MAX];
int sum[MAX];
// bool visited[MAX];
void input()
{
  cin >> n >> b;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    // visited[i] = 0;
  }
  ans = 0;
  sum[1] = a[1];
}

void solution()
{
  if (sum[n] == b)
    ans = ans + 1;
}

void TRY(int i)
{
  for (int k = 0; k < 2; k++)
  {

    // x[i] = k;
    //  visited[a] = true;
    //  Tinh sum
    if (k == 0)
    {
      sum[i + 1] = sum[i] - a[i + 1];
    }
    else
    {
      sum[i + 1] = sum[i] + a[i + 1];
    }
    if (i == n - 1)
      solution();
    else
      TRY(i + 1);

    if (k == 0)
    {
      sum[i + 1] = sum[i + 1] + a[i + 1];
    }
    else
    {
      sum[i + 1] = sum[i + 1] - a[i + 1];
    }
    // return sum
    // visited[a] =
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  TRY(1);
  cout << ans;
  return 0;
}
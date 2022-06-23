#include <bits/stdc++.h>
using namespace std;
const int MAX = 50;

// Danh dau ky tu nay da duoc su dung chua
bool visited[MAX];
int n;
int ans;
// 0=H, 1=U, 2 = S, 3 = T, 4 = O, 5 = I, 6 = C
int x[MAX];

void input()
{
  cin >> n;
  for (int i = 0; i < MAX; i++)
  {
    visited[i] = 0;
  }
  ans = 0;
}

// 2 chu so dung dau phai khac 0
bool check(int a, int i)
{
  if (a == 0 && i == 0)
    return false;
  if (a == 2 && i == 0)
    return false;
  if (visited[i])
    return false;

  return true;
}

void solution()
{
  int hust = x[0] * 1000 + x[1] * 100 + x[2] * 10 + x[3];
  int soict = x[2] * 10000 + x[4] * 1000 + x[5] * 100 + x[6] * 10 + x[3];

  if (hust + soict == n)
    ans++;
}

void TRY(int a)
{
  for (int i = 0; i < 10; i++)
  {
    if (check(a, i))
    {
      x[a] = i;
      visited[i] = true;s

      if (a == 6)
        solution();
      else
        TRY(a + 1);

      visited[i] = false;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  while (t > 0)
  {
    input();
    TRY(0);
    t--;
  }
  return 0;
}
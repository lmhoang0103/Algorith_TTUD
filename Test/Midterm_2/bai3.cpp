#include <bits/stdc++.h>
using namespace std;
const int MAX = 11;

int n, r, c;
int a[MAX][MAX];
int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int sol[MAX][MAX];
int sum[MAX][MAX];
long long ans;

// Co the tham o nay
int isSafe(int x, int y, int sol[MAX][MAX])
{
  return (x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1);
}

void input()
{
  ans = 0;
  cin >> n >> r >> c;
  r = r - 1;
  c = c - 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }

  for (int x = 0; x < n; x++)
    for (int y = 0; y < n; y++)
      sol[x][y] = -1;
  sol[r][c] = 0;
  sum[r][c] = a[r][c];
  ans = a[r][c];
}

int solve(int x, int y, int movei, int sol[MAX][MAX],
          int xMove[8], int yMove[8])
{
  int k, next_x, next_y;

  if (movei == n * n)
    return 1;

  for (k = 0; k < 8; k++)
  {
    next_x = x + xMove[k];
    next_y = y + yMove[k];
    if (isSafe(next_x, next_y, sol))
    {
      sol[next_x][next_y] = movei;
      sum[next_x][next_y] = sum[x][y] + a[next_x][next_y];
      if (sum[next_x][next_y] > ans)
      {
        ans = sum[next_x][next_y];
        // cout << "day la ans" << ans << endl;
      }

      if (solve(next_x, next_y, movei + 1, sol,
                xMove, yMove) == 1)
      {
        sol[next_x][next_y] = -1;
        sum[next_x][next_y] = sum[next_x][next_y] - a[next_x][next_y];
      }
      else

      // backtracking
      {
        sol[next_x][next_y] = -1;
        sum[next_x][next_y] = sum[next_x][next_y] - a[next_x][next_y];
      }
    }
  }
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve(r, c, 1, sol, xMove, yMove);
  cout << ans;
  return 0;
}
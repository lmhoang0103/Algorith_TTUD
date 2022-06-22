#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int L, C;
// 2 cap vecto luu hinh anh truoc va sau
vector<pair<int, int>> pre, after;

void input()
{
  cin >> L >> C;

  for (int i = 0; i < L; i++)
  {
    for (int j = 0; j < C; j++)
    {
      int tmp;
      cin >> tmp;
      if (tmp)
        pre.push_back({i, j});
    }
  }

  for (int i = 0; i < L; i++)
  {
    for (int j = 0; j < C; j++)
    {
      int tmp;
      cin >> tmp;
      if (tmp)
        after.push_back({i, j});
    }
  }
}

void solve()
{
  int maxSl = 0;

  map<pair<int, int>, int> m;
  int lensPre = pre.size();
  int lensAft = after.size();
  for (int i = 0; i < lensPre; i++)
  {
    for (int j = 0; j < lensAft; j++)
    {
      int a = after[j].first - pre[i].first + N;
      int b = after[j].second - pre[i].second + N;
      m[{a, b}]++;
      maxSl = max(m[{a, b}], maxSl);
    }
  }
  cout << maxSl << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  // cin.tie(NULL);
  // cout.tie(NULL);
  int t;
  cin >> t;
  while (t > 0)
  {
    input();
    solve();
    t--;
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;

int n;
int p[MAX];
string s;
queue<int> hanhlang;
stack<int> chuong;




void input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }

  for (int i = n - 1; i >= 0; i--)
  {
    chuong.push(p[i]);
  }

  cin >> s;
}

void solve()
{

  int lens = s.length();
  for (int i = 0; i < lens; i++)
  {
    if (s[i] == 'C')
    {
      if (!chuong.empty())
      {
        int tmp = chuong.top();
        chuong.pop();
        hanhlang.push(tmp);
      }
    }
    else
    {
      if (!hanhlang.empty())
      {
        int tmp = hanhlang.front();
        hanhlang.pop();
        chuong.push(tmp);
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  for (int i = 0; i < n; i++)
  {
    cout << chuong.top() << "";
    chuong.pop();
  }
  return 0;
}
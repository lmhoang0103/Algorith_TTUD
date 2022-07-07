#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int n;
int a[MAX];

// c[i] la so luong day chan ket thuc tai a[i]
// l[i] la so luong day le ket thuc tai a[i]
// ans = tong cac c co the co
int c[MAX];
int l[MAX];
unsigned long long ans;

void input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  if ((a[0] % 2) == 0)
  {
    c[0] = 1;
    l[0] = 0;
  }
  else
  {
    c[0] = 0;
    l[0] = 1;
  }
  ans = c[0];
}

void solve()
{
  for (int i = 1; i < n; i++)
  {
    if (a[i] % 2 == 0)
    {
      c[i] = c[i - 1] + 1;
      l[i] = l[i - 1];
    }
    else
    {
      c[i] = l[i - 1];
      l[i] = c[i - 1] + 1;
    }
    ans = ans + c[i];
    // if (i == n - 2)
    // {

    //   cout << ans << endl;
    //   cout << c[i] << endl;
    //   cout << l[i] << endl;
    // }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("test1.txt", "r", stdin);
  input();
  solve();
  cout << ans << endl;
  ans = ans % 1000000007;
  cout << ans << endl;
  // for (int i = 0; i < n; i++)
  // {
  //   cout << "c[" << i << "]: " << c[i] << endl;
  //   cout << "l[" << i << "]: " << l[i] << endl;
  //   cout << endl;
  // }

  return 0;
}
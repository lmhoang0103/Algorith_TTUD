#include <bits/stdc++.h>
using namespace std;
#define MAX 10000001

int n;
int a[MAX];
int m;
int start[MAX], en[MAX];
int M[20][MAX];

void input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> start[i] >> en[i];
  }

  for (int i = 0; i < n; i++)
    M[0][i] = i;

  for (int j = 0; j < n; j++)
  {
    /* code */
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int a = 1<<2;
  //cout << a;
  return 0;
}
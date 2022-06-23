#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;

int n, L1, L2;
int a[MAX];
int s[MAX];
int ans;

void input()
{

  cin >> n >> L1 >> L2;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
}

void solve()
{
  s[0] = a[0];
  ans = s[0];
  for(int i = 1; i<n; i++){
    int maxj = 0;
    for(int j= i-L2; j<= i-L1; j++){
      if(j>=0){
        maxj = max(maxj, s[j]);
      }
    }

    s[i] = maxj+a[i];
    ans = max(ans, s[i]);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  cout<<ans;
  return 0;
}
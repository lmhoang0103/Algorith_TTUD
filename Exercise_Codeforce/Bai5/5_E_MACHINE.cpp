#include <bits/stdc++.h>
using namespace std;

int main()
{
  // freopen("1.inp", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> s(n), t(n);

  // maxv là thời điểm kết thúc muộn nhất
  int maxv = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i] >> t[i];
    maxv = max(maxv, t[i]);
  }

  // Vector L co maxv+1 full 0
  vector<int> L(maxv + 1, 0), R(maxv + 2, 0);

  // L[t[i]] la khoang lon nhat ve ben trai tai t[i]
  // R[s[i]] la khoang lon nhat ve ben phai tai s[i]
  // Tai moi diem se co the di ve ben trai hoac phai lon nhat lan luot la L[t] va R[t]
  for (int i = 0; i < n; i++)
  {
    L[t[i]] = max(L[t[i]], t[i] - s[i]);
    R[s[i]] = max(R[s[i]], t[i] - s[i]);
  }

  // Di tu trai sang phai, tai moi thoi diem t
  for (int i = 1; i <= maxv; i++)
    L[i] = max(L[i], L[i - 1]);

  for (int i = maxv - 1; i >= 0; i--)
    R[i] = max(R[i], R[i + 1]);

  R[maxv] = R[maxv + 1] = 0;

  int ans = -1;
  for (int i = 0; i < n; i++)
    ans = max(ans, L[t[i]] + R[t[i] + 1]);
  cout << ans << endl;

  return 0;
}

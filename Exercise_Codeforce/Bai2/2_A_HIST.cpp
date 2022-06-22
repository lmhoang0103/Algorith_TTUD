#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> vt;
// Can toi uu su dung array de giam ram can de tinh toan
//  Array de luu gia tri ben trai gan nhat nho hon gia tri dang xet
vector<long long> L;
// Array de luu gia tri ben phai gan nhat nho hon gia tri dang xet
vector<long long> R;

// Nhap gia tri cho bai toan vao array vt;
void input()
{
  cin >> n;
  vt.push_back(-1); // Dat linh canh o 2 dau mang
  for (long long i = 0; i < n; i++)
  {
    long long tmp;
    cin >> tmp;
    vt.push_back(tmp);
  }
  vt.push_back(-1); // Dat linh canh o 2 dau mang
}

void solve()
{
  while (true)
  {
    input();
    // Mang khong co phan tu khong thuc hien
    if (n == 0)
      return;
    stack<long long> st;

    L.resize(n + 2);
    R.resize(n + 2);

    // Xet ben trai
    for (long long i = 1; i <= n + 1; i++)
    {
      while (!st.empty() && vt[i] < vt[st.top()])
      {
        L[st.top()] = i;
        st.pop();
      }
      st.push(i);
    }

    // Xet ben phai
    for (long long i = n; i >= 0; i--)
    {
      while (!st.empty() && vt[i] < vt[st.top()])
      {
        R[st.top()] = i;
        st.pop();
      }
      st.push(i);
    }

    long long maxh = 0;

    for (long long i = 1; i <= n; i++)
    {
      long long h = (L[i] - R[i] - 1) * vt[i];
      if (h > maxh)
        maxh = h;
    }

    cout << maxh << endl;

    // Reset mang
    vt.erase(vt.begin(), vt.end());
    L.erase(L.begin(), L.end());
    R.erase(R.begin(), R.end());
  }
}

int main()
{
  solve();
  return 0;
}
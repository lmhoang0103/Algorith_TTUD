#include <bits/stdc++.h>
using namespace std;
const long long MaxK = 10000001;
long long n, k;

// ta luu theo cau truc a[x] = m, trong do x la toa do, m la so luong hang
// De toi uu thi chi mang hang cua ben co toa do am hoac duong trong 1 lan
long long mPos[MaxK];
long long mNeg[MaxK];

void input()
{
  cin >> n >> k;
  for (long long i = 0; i < n; i++)
  {
    long long tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    if (tmp1 > 0)
      mPos[tmp1] = tmp2;
    else
    {
      tmp1 = abs(tmp1);
      mNeg[tmp1] = tmp2;
    }
  }
}

// Ham tinh quang duong
long long qd(long long m[])
{
  long long i = MaxK;
  unsigned long long tqd = 0; // Tong quang duong
  long long c = 0;            // So du

  while (i > 0)
  {
    while (m[i] == 0 && i > 0) // Khong can mang hang den vi tri nay
      i--;
    if (i == 0) // Da xet het
      break;

    long long thuong;
    m[i] = m[i] - c; // Giao c hang cho vi tri i
    if (m[i] < 0)    // Neu giao du
    {
      c = -m[i]; // Thi phan con lai giao cho khach khac
      m[i] = 0;  // Danh dau da giao du
    }
    else // Neu khong giao du
    {
      c = m[i] % k; // Moi lan giao duoc k thi sau khi giao rat nhieu lan van con can c neu c > 0
      if (c != 0)
        c = k - c;
      thuong = m[i] / k; // So lan phai giao lien tiep
      if (c > 0)
      {
        tqd = tqd + 2 * (thuong + 1) * i;
      }
      else
      {
        tqd = tqd + 2 * thuong * i; // Neu c = 0 thi phai giao the nay
      }
    }
    i--;
  }

  return tqd;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  input();

  cout << qd(mNeg) + qd(mPos);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;
const double Pi = atan(1) * 4;

int n, f;
int cnt = 1e9;
int radi[MAX];
double S[MAX];
double maxS; // S lon nhat cua cac banh

/*Giai thich
maxS: Dien tich cai banh lon nhat
Giai gan dung
Neu moi nguoi duoc phan rat nho thi return luon (<1e-7)

*/
void input()
{
  maxS = 0;
  cin >> n >> f;
  for (int i = 0; i < n; i++)
  {
    cin >> radi[i];
    S[i] = radi[i] * radi[i] * Pi;
    maxS = max(maxS, S[i]);
  }
}

/* Neu moi nguoi nhan duoc mot mieng banh s, so nguoi toi da co the nhan banh la sum
Neu sum > F, ta cho moi nguoi nhan nhieu banh hon
Neu sum < F, ta cho moi nguoi nhan it banh di
Neu khong the thay doi so banh nhan duoc moi nguoi qua 1e-7, ta ket thuc
Neu da lap lai qua trinh nay rat nhieu lan, ta cung ket thuc
*/
bool cha(double s)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum = sum + floor(S[i] / s);
  }

  return sum > f;
}

double solve(double left, double right)
{
  double mid = (left + right) / 2.0;
  cnt--;

  if (right - left < 1e-7 || cnt < 0)
  {
    return mid;
  }
  else
  {
    if (cha(mid))
      return solve(mid, right);
    else
      return solve(left, mid);
  }
}

int main()
{

  int t;
  cin >> t;
  while (t > 0)
  {
    input();
    printf("%.6f\n", solve(0, maxS));
    t--;
  }
  return 0;
}
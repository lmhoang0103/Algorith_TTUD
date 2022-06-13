#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
int dgg;

void findDgg()
{
  dgg = 1;
  for (int i = 1; i < n; i++)
  {
    if (arr[i] != arr[i - 1])
      dgg++;
  }
}

void input1()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    arr.push_back(tmp);
  }
  findDgg();
}

// Tim dgg sau moi thay doi tai vi tri tmp1 thanh loai nhua tmp2
// Ta chi can xet doan duong [tmp1 -1; tmp1+1]
void handle(int tmp1, int tmp2)
{
  tmp1--; // Do vecto bat dau tu 0 != 1

  int dggBanDau = 1;
  if (arr[tmp1] != arr[tmp1 - 1] && tmp1 - 1 >= 0)
    dggBanDau++;
  if (arr[tmp1 + 1] != arr[tmp1] && tmp1 + 1 < n)
    dggBanDau++;

  int dggLucSau = 1;
  arr[tmp1] = tmp2;
  if (arr[tmp1] != arr[tmp1 - 1] && tmp1 - 1 >= 0)
    dggLucSau++;
  if (arr[tmp1 + 1] != arr[tmp1] && tmp1 + 1 < n)
    dggLucSau++;

  dgg = dgg - dggBanDau + dggLucSau;

  cout << dgg << endl;
}

void input2()
{
  int k;
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;

    handle(tmp1, tmp2);
  }
}

int main()
{
  input1();
  input2();

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int Max = 2000001;
int n;

//Moi block dac trung cho 1 khoi thoi gian co the chay
struct Block
{
  int s, t,c;
  bool operator<(Block &b)
  {
    return s < b.s && t < b.t;
  }
};

Block b[Max];
int ans = -1;


//Sap xep theo thoi gian bat dau khong giam
bool cmp(Block& b1, Block& b2){
  if(b1.s != b2.s) return b1.s>b2.s;
  
}

bool checkOverlap(Block& b1, Block& b2){


}
void input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin>>b[i].s>>b[i].t;
  }
}


void solve()
{
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  cout << ans;
  return 0;
}
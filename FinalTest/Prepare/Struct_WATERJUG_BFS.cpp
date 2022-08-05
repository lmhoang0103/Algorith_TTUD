#include <bits/stdc++.h>
using namespace std;
const int Max = 1005;

// Mot binh nuoc co dung tich toi da chua luong nuoc hien tai
struct binhNuoc
{
  int luongnuoc;
  int dungtich;
};

binhNuoc binhA, binhB;
int c;

void input()
{
  int a, b;
  cin >> a >> b >> c;
  binhA.dungtich = a;
  binhB.dungtich = b;
}

/*
Co 3 truong hop co the do nuoc
TH1: Do tu binh nay sang binh kia
TH2: Fill 1 binh
Th3: Empty 1 binh
*/

void fillJug(binhNuoc &binh)
{
  binh.luongnuoc = binh.dungtich;
}

void emptyJug(binhNuoc &binh)
{
  binh.luongnuoc = 0;
}

void exchangeWater(binhNuoc &binh1, binhNuoc &binh2)
{
  if (binh1.luongnuoc + binh2.luongnuoc < binh2.dungtich)
  {
    binh2.luongnuoc = binh1.luongnuoc + binh2.luongnuoc;
    binh1.luongnuoc = 0;
    return;
  }
  else
  {
    binh1.luongnuoc = binh1.luongnuoc + binh2.luongnuoc - binh2.dungtich;
    binh2.luongnuoc = binh2.dungtich;
    return;
  }
}

bool checkStop(binhNuoc binh1, binhNuoc binh2)
{
  if (binh1.luongnuoc == c || binh2.luongnuoc == c)
    return true;
  else
    return false;
}

// Tu 1 cap trong hang doi, ta suy ra duoc tat ca trang thai co the co, cho no vao map (BFS)
queue<pair<int, int>> Q;
// Danh dau lai vi tri da di qua
// dist la so lan thuc hien hanh dong
// Vi tri dau tien co dist = -1 (vi tri 0,0)
// Vi tri chua di qua co dist = 0 (gia tri mac dinh khi khai bao map)
// map co key la pair trang thai 2 binh, con lai la dist de dat toi trang thai nay
map<pair<int, int>, int> dist; // Khoang cach
bool visited[Max][Max];

void bfs()
{
  // Khai bao 2 binh tam thoi de giu lai chi so cua binh A, B truoc khi do nuoc
  binhNuoc binhTempA;
  binhNuoc binhTempB;

  // Ban dau trong hang doi co vi tri xuat phat ( thoi diem ban dau cua 2 binh co 0 lit)
  // Khoang cach ban dau tu no toi chinh no la bang 0
  // Danh dau visited = true -> da di qua diem dau tien
  Q.push(pair<int, int>(0, 0));
  dist[pair<int, int>(binhA.luongnuoc, binhB.luongnuoc)] = 0;
  visited[binhA.luongnuoc][binhB.luongnuoc] = true;

  while (!Q.empty())
  {
    binhA.luongnuoc = Q.front().first;
    binhB.luongnuoc = Q.front().second;
    Q.pop();

    // Luu lai luong nuoc hien tai truoc khi do nuoc
    binhTempA = binhA;
    binhTempB = binhB;

    // Kiem tra dieu kien de bai truoc khi bat dau xu li
    if (checkStop(binhA, binhB))
    {
      cout << dist[pair<int, int>(binhA.luongnuoc, binhB.luongnuoc)];
      return;
    }

    // Voi truong hop danh xet lay ra tu Q, cac truong hop co the sinh ra la

    // Fill JUG A
    fillJug(binhA);
    if (!visited[binhA.luongnuoc][binhB.luongnuoc])
    {
      Q.push(pair<int, int>(binhA.luongnuoc, binhB.luongnuoc));
      dist[pair<int, int>(binhA.luongnuoc, binhB.luongnuoc)] = dist[pair<int, int>(binhTempA.luongnuoc, binhTempB.luongnuoc)] + 1;
      visited[binhA.luongnuoc][binhB.luongnuoc] = true;
      // cout << "(" << binhA.luongnuoc << "," << binhB.luongnuoc << ")" << endl;
    }
    // Tra lai trang thai ban dau
    binhA = binhTempA;
    binhB = binhTempB;

    // Fill JUG B
    fillJug(binhB);
    if (!visited[binhA.luongnuoc][binhB.luongnuoc])
    {
      Q.push(pair<int, int>(binhA.luongnuoc, binhB.luongnuoc));
      dist[pair<int, int>(binhA.luongnuoc, binhB.luongnuoc)] = dist[pair<int, int>(binhTempA.luongnuoc, binhTempB.luongnuoc)] + 1;
      visited[binhA.luongnuoc][binhB.luongnuoc] = true;
      // cout << "(" << binhA.luongnuoc << "," << binhB.luongnuoc << ")" << endl;
    }
    // Tra lai trang thai ban dau
    binhA = binhTempA;
    binhB = binhTempB;

    // A->B
    exchangeWater(binhA, binhB);
    if (!visited[binhA.luongnuoc][binhB.luongnuoc])
    {
      Q.push(pair<int, int>(binhA.luongnuoc, binhB.luongnuoc));
      dist[pair<int, int>(binhA.luongnuoc, binhB.luongnuoc)] = dist[pair<int, int>(binhTempA.luongnuoc, binhTempB.luongnuoc)] + 1;
      visited[binhA.luongnuoc][binhB.luongnuoc] = true;
      // cout << "(" << binhA.luongnuoc << "," << binhB.luongnuoc << ")" << endl;
    }
    // Tra lai trang thai ban dau
    binhA = binhTempA;
    binhB = binhTempB;

    // B->A
    exchangeWater(binhB, binhA);
    if (!visited[binhA.luongnuoc][binhB.luongnuoc])
    {
      Q.push(pair<int, int>(binhA.luongnuoc, binhB.luongnuoc));
      dist[pair<int, int>(binhA.luongnuoc, binhB.luongnuoc)] = dist[pair<int, int>(binhTempA.luongnuoc, binhTempB.luongnuoc)] + 1;
      visited[binhA.luongnuoc][binhB.luongnuoc] = true;
      // cout << "(" << binhA.luongnuoc << "," << binhB.luongnuoc << ")" << endl;
    }
    // Tra lai trang thai ban dau
    binhA = binhTempA;
    binhB = binhTempB;

    // empty A
    emptyJug(binhA);
    if (!visited[binhA.luongnuoc][binhB.luongnuoc])
    {
      Q.push(pair<int, int>(binhA.luongnuoc, binhB.luongnuoc));
      dist[pair<int, int>(binhA.luongnuoc, binhB.luongnuoc)] = dist[pair<int, int>(binhTempA.luongnuoc, binhTempB.luongnuoc)] + 1;
      visited[binhA.luongnuoc][binhB.luongnuoc] = true;
      // cout << "(" << binhA.luongnuoc << "," << binhB.luongnuoc << ")" << endl;
    }
    // Tra lai trang thai ban dau
    binhA = binhTempA;
    binhB = binhTempB;
    // empty B
    emptyJug(binhB);
    if (!visited[binhA.luongnuoc][binhB.luongnuoc])
    {
      Q.push(pair<int, int>(binhA.luongnuoc, binhB.luongnuoc));
      dist[pair<int, int>(binhA.luongnuoc, binhB.luongnuoc)] = dist[pair<int, int>(binhTempA.luongnuoc, binhTempB.luongnuoc)] + 1;
      visited[binhA.luongnuoc][binhB.luongnuoc] = true;
      // cout << "(" << binhA.luongnuoc << "," << binhB.luongnuoc << ")" << endl;


    }


    //Khong can tra lai trang thai ban dau do thoat vong while, khong xet nua
    // Tra lai trang thai ban dau
    // binhA = binhTempA;
    // binhB = binhTempB;


  }

  cout << "-1";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  bfs();

  return 0;
}
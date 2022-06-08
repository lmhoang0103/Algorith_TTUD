#include <bits/stdc++.h>
using namespace std;

void output(string str)
{
  int length = str.length();
  if (length > 10)
  {
    cout << str[0] << length - 2 << str[length - 1] << endl;
  }
  else
  {
    cout << str << endl;
  }
}

int main()
{
  int n;
  cin >> n;


  while (n > 0)
  {
    string str;
    cin >> str;
    output(str);
    n--;
  }

  return 0;
}
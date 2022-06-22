#include <bits/stdc++.h>
using namespace std;
stack<int> stk;
void PUSH(int v)
{
  stk.push(v);
}

void POP()
{
  if (!stk.empty())
  {

    cout << stk.top() << endl;
    stk.pop();
  }
  else
    cout << "NULL" << endl;
}
int main()
{
  while (true)
  {
    string str;
    cin >> str;
    if (str == "PUSH")
    {
      int v;
      cin >> v;

      cin.ignore();
      PUSH(v);
      // cout << "push here" << v << endl;
    }
    else if (str == "POP")
    {
      POP();
      // cout << "pop here" << endl;
    }
    else if (str == "#")
    {
      // cout << "end";
      break;
    }
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const string str1 = "adgjmptw";
const string str2 = "behknqux";
const string str3 = "cfilorvy";
const string str4 = "sz";
// Ham find tra ve vi tri tim thay hoac npos
int output(string str)
{
  int lens = str.length();
  int k = 0;
  for (int i = 0; i < lens; i++)
  {
    // str1.find(str[i]) != string::npos
    if (str1.find(str[i]) != string::npos)
    {
      k = k + 1;
    }
    else if (str2.find(str[i]) != string::npos)
    {
      k = k + 2;
    }
    else if (str3.find(str[i]) != string::npos)
    {
      k = k + 3;
    }
    else if (str4.find(str[i]) != string::npos)
    {
      k = k + 4;
    }
    else if (str[i] == ' ')
    {
      k = k + 1;
    }
  }

  return k;
}

int main()
{

  int n;
  cin >> n;
  cin.ignore();
  int i = 1;
  while (i <= n)
  {
    string str;
    getline(cin, str);
    //cout << str << endl;
    cout << "Case #" << i << ": " << output(str) << endl;
    i++;
  }
  return 0;
}
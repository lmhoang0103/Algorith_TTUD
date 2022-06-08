#include <iostream>
using namespace std;
const unsigned long long p = 1000000000 + 7;

// Ham de lay du chia mot so long long cho P
int modP(unsigned long long n)
{
  if (n < p)
    return n;
  unsigned long long buffer = n / p;
  int result = n - buffer * p;
  return result;
}

// a^p va a mod p la tuong tu
// b= p* n + x => a^b = a^(p*n+x) dong du voi a^(n+x)

// n+x
// co the lap lai ham nay lien tuc de giam co mu
unsigned long long modPEXP(unsigned long long n)
{
  unsigned long long buffer = n / p;
  unsigned long long buffer2 = n - buffer * p;
  return buffer + buffer2;
}

unsigned long long mul(int a, int b)
{
  unsigned long long s = a * b;
  s = modP(s);
  return s;
}

// tim modP cua ham mu voi so be
unsigned long long expmodSmall(unsigned long long a, unsigned long long b)
{
  unsigned long long S = 1;
  for (unsigned long long i = 0; i < b; i++)
  {
    S = S * a;
    S = modP(S);
  }
  return S;
}

// tim modP cua ham mu voi so lon
unsigned long long expmod(unsigned long long a, unsigned long long b)
{
  if (b % 2 == 0)
  {
    unsigned long long temp = expmodSmall(a, b / 2);
    temp = temp * temp;
    temp = modP(temp);
    return temp;
  }
  else
  {
    unsigned long long temp = expmodSmall(a, b / 2);
    temp = temp * temp;
    temp = modP(temp);
    temp = temp * a;
    temp = modP(temp);
    return temp;
  }
}

int main()
{
  unsigned long long a, b;
  cin >> a >> b;
  a = modP(a);
  b = modPEXP(b);
  b = modPEXP(b);
  cout << expmod(a, b);

  return 0;
}

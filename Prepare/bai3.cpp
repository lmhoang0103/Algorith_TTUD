#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
#define NO_OF_CHARS 256

string A[MAX];
int n, z;
int badchar[2];

unsigned long long ans;

void badCharHeuristic(string str, int size,
                      int badchar[NO_OF_CHARS])
{
  int i;

  // Initialize all occurrences as -1
  for (i = 0; i < NO_OF_CHARS; i++)
    badchar[i] = -1;

  // Fill the actual value of last occurrence
  // of a character
  for (i = 0; i < size; i++)
    badchar[(int)str[i]] = i;
}

void search(string txt, string pat)
{
  int m = pat.size();
  int n = txt.size();

  int badchar[NO_OF_CHARS];

  /* Fill the bad character array by calling
  the preprocessing function badCharHeuristic()
  for given pattern */
  badCharHeuristic(pat, m, badchar);

  int s = 0; // s is shift of the pattern with
             // respect to text
  while (s <= (n - m))
  {
    int j = m - 1;

    /* Keep reducing index j of pattern while
    characters of pattern and text are
    matching at this shift s */
    while (j >= 0 && pat[j] == txt[s + j])
      j--;

    /* If the pattern is present at current
    shift, then index j will become -1 after
    the above loop */
    if (j < 0)
    {
      ans = ans + 1;

      /* Shift the pattern so that the next
      character in text aligns with the last
      occurrence of it in pattern.
      The condition s+m < n is necessary for
      the case when pattern occurs at the end
      of text */
      s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
    }

    else
      /* Shift the pattern so that the bad character
      in text aligns with the last occurrence of
      it in pattern. The max function is used to
      make sure that we get a positive shift.
      We may get a negative shift if the last
      occurrence of bad character in pattern
      is on the right side of the current
      character. */
      s += max(1, j - badchar[txt[s + j]]);
  }
}

string convertToString(char *a)
{
  string s(a);

  // we cannot use this technique again
  // to store something in s
  // because we use constructors
  // which are only called
  // when the string is declared.

  // Remove commented portion
  // to see for yourself

  /*
  char demo[] = "gfg";
  s(demo); // compilation error
  */

  return s;
}

string removeSpaces(string str)
{
  str.erase(remove(str.begin(), str.end(), ' '), str.end());
  return str;
}

void input()
{
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++)
  {
    getline(cin, A[i]);
    A[i] = removeSpaces(A[i]);
  }

  ans = 0;
  cin >> z;

  for (int i = 0; i < z; i++)
  {
    string D;
    cin >> D;

    // Tim xem D co xuat hien trong hang j khong [j]
    // Gia su ca 2 deu la string
    for (int j = 0; j < n; j++)
    {
      search(A[j], D);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  cout << ans;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
        map<char, int> M;
        M['a'] = 1;// map the key 'a' to value 1
        M['b'] = 100;// map te key 'b' to value 100
        M['x'] = 123;

        char c = 'y';
        cout << "map(" << c << ") = " << M[c] << endl;
        return 0;
}

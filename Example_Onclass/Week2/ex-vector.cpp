#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> V;// dynamic array
     for(int x = 1; x <= 100; x++)
        V.push_back(x);

     for(int i = 0; i < V.size(); i++){
        cout << V[i] << " ";
     }

     return 0;
}

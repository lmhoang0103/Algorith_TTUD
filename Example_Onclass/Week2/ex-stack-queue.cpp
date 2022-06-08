#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int> S;
    queue<int> Q;

    for(int x = 1; x <= 5; x++){
        S.push(x);
        Q.push(x);
    }
    while(!S.empty()){
        int x = S.top(); S.pop();
        cout << "Stack pop " << x << endl;
    }

    while(!Q.empty()){
        int x = Q.front(); Q.pop();
        cout << "Q pop " << x << endl;
    }

     return 0;
}

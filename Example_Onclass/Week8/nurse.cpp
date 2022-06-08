#include <bits/stdc++.h>
#define N 1001
using namespace std;
int n, K1, K2;
int S0[N], S1[N];

void input(){
    cin >> n >> K1 >> K2;
}
void solve(){
    for(int i = 0; i <= n; i++){
        S0[i] = 0; S1[i] = 0;
    }
    // K1 = 2, K2 = 3
    // S0[1] = 1 (0), S0[2] = 0, S0[3] = 1 (110)
    // S1[1] = 0, S1[2] = 1 (11), S1[3] =  2  (011, 111)
    S0[1] = 1;
    S1[K1] = 1; // S1[i] = 0, i < K1
    S0[0] = 1;
    for(int i = K1+1; i <= n; i++){
        S0[i] = S1[i-1];
        S1[i] = 0;
        for(int d = K1; d <= K2; d++){
            int j = i-d;
            if(j >= 0){
                S1[i] = S1[i] + S0[j];
            }
            //cout << "i = " << i << " d = " << d << " j = " << j << " S0[" << j << "] = " << S0[j] << " S1[" << i << "] = " << S1[i] << endl;
            //}
        }
    }
    int ans = S0[n] + S1[n];
    cout << ans;
}

int main(){
    input();
    solve();
    return 0;
}

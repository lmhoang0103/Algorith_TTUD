#include <bits/stdc++.h>
using namespace std;
#define N 1000001
int a[N];
int n;
int S[N];// S[i] stores the solution of sub-problem with index i
bool b[N];// b[i] = true: sub-problem i has been solved
int ans;

int DP(int i){
    if(i == 1){// base-case, smallest sub-problem
        S[1] = a[1]; b[1] = true;
    }else{
        if(b[i] == false){// sub-problem not solved
            int t1  = DP(i-1);// call DP recursively for solving sub-problem
            S[i] = max(t1+a[i], a[i]);
            b[i] = true;// indicate that the sub-problem has been solved and stored in S[i]
        }
    }
    return S[i];
}
void input(){
    cin >> n;
    for(int i =1 ; i <= n; i++) cin >> a[i];
}
int main(){
    input();
    for(int i =1 ; i <= n; i++) b[i] = false;
    ans = DP(1);
    for(int i = 2; i <= n; i++){
        int t = DP(i);
        ans = max(ans, t);
    }
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define N 1000
struct Block{
    int x,y,z;
    bool operator < (Block& b){
        return x < b.x && y < b.y;
    }
};
Block b[N];
int n;
int S[N];
bool cmp(Block& b1, Block& b2){
    if(b1.x != b2.x) return b1.x > b2.x;
    if(b1.y != b2.y) return b1.y > b2.y;
    return b1.z > b2.z;
}
void solve(){
    int t = 0;
    while(true){
        t++;
        cin >> n;
        if(n == 0) break;

        int m = -1;
        int a[3];
        for(int i = 1; i <= n; i++){
            cin >> a[0] >> a[1] >> a[2];
            sort(a,a+3);
            do{
                m++;
                b[m].x = a[0]; b[m].y = a[1]; b[m].z = a[2];
            }while(next_permutation(a,a+3));
        }
        sort(b,b+m+1,cmp);

        //for(int i = 0; i <= m; i++) cout << b[i].x << " " << b[i].y << " " << b[i].z << endl;
        S[0] = b[0].z;
        int ans = S[0];
        for(int i = 1; i <= m; i++){
            // compute S[i] based on the DP equation
            S[i] = b[i].z;
            for(int j = 0; j <= i-1; j++){
                if(b[i] < b[j]){
                    S[i] = max(S[i], S[j] + b[i].z);
                }
            }
            ans = max(ans, S[i]);
        }
        // print result
        cout << "Case " << t << ": maximum height = " << ans << endl;
    }
}
int main(){
    solve();
    return 0;
}

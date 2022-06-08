#include <bits/stdc++.h>
using namespace std;
#define N 1000001
int a[N];
int n;
int SC[N], SL[N];
bool BC[N]; // BC[i] = true if BTC SC[i] exists, BC[i] = false, otherwise
bool BL[N]; // BL[i] = true if BTC SL[i] exists, BL[i] = false, otherwise
void solve(){
    int ans = 1-1e9;
    bool found = false;
    if(a[1]%2== 0){
            BC[1] = true; SC[1] = a[1]; BL[1] = false; ans = SC[1]; found = true;
    }else{
        BC[1] = false; SL[1] = a[1]; BL[1] = true;
    }

    for(int i = 2; i<= n; i++){
        if(a[i]%2==0){
                if(BC[i-1]==true){
                    SC[i] = max(SC[i-1] + a[i], a[i]);
                }else{
                    SC[i] = a[i];
                }
                BC[i] = true;

                if(BL[i-1] == false){
                    BL[i] = false;
                }else{
                    BL[i] = true; SL[i] = SL[i-1] + a[i];
                }
        }else{
            if(BL[i-1] == false){
                BC[i] = false;
            }else{
                BC[i] = true; SC[i] = SL[i-1] + a[i];
            }

            if(BC[i-1] == true){
                SL[i] = max(SC[i-1] + a[i], a[i]);
            }else{
                SL[i] = a[i];
            }
            BL[i] = true;
        }
    }

    for(int i = 2; i <= n; i++){
        if(BC[i] == true && SC[i] > ans){
            ans = SC[i];
        }
    }
    if(found)
        cout << ans;
    else cout << "NOT_FOUND";
}
int main(){
    scanf("%d",&n);
    for(int i =1 ; i <= n; i++) scanf("%d",&a[i]);
    solve();
    return 0;
}

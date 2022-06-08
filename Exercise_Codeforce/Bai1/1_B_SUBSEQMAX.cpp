#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int arr[10000];
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
 
    int best = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++){
        sum = max(arr[i], sum+arr[i]);
        best = max(best, sum);
    }
    cout << best;
 
 
    return 0;
}
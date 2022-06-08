#include <bits/stdc++.h>
using namespace std;
int a[1000000];

int main(){

    int* p;
    cout << sizeof(short) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;
    cout << sizeof(long double) << endl;
    cout << 0xFFFFFFFFFFFFFFFF << endl;
    cout << (1 << 3) << endl;
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(4);
    pq.push(1);
    pq.push(100);
    pq.push(50);
    while(!pq.empty()){
        int x = pq.top(); pq.pop();
        cout << "pop " << x << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>

int main(){
    priority_queue<PII, vector<PII>, greater<PII> > pq; // first element is the key
    pq.push(make_pair(4,7));
    pq.push(make_pair(10,2));
    pq.push(make_pair(1,100));
    pq.push(make_pair(20,5));

    while(!pq.empty()){
        PII e = pq.top(); pq.pop();
        cout << e.first << "," << e.second << endl;
    }
    return 0;
}

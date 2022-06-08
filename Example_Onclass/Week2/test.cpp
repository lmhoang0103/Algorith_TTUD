#include <bits/stdc++.h>
using namespace std;
int a[1000000]; // static
int* b;// pointer to the dynamic allocation array
void proc(){
    int n;
    scanf("%d",&n);
    b = new int[n];// dynamic allocation
}
int main(){
    deque<int> DQ;
    for(int i = 1; i <= 5; i++){
        DQ.push_front(i);
    }
    while(DQ.size() > 0){
        int x = DQ.back();
        cout << x << endl;
        DQ.pop_back();
    }

    //priority_queue<int> PQ; // prioritize max-key
    priority_queue<int, vector<int>, greater<int> > PQ; // prioritize min-key
    PQ.push(10);
    PQ.push(1);
    PQ.push(5);
    PQ.push(8);
    while(!PQ.empty()){
        int x = PQ.top();
        PQ.pop();
        cout << "PQ pop " << x << endl;
    }


    return 0;
}

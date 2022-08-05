#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>

int main()
{
    priority_queue<PII> pq_maxheap; //Maxheap, giam dan
    priority_queue<PII, vector<PII>, greater<PII>> pq; // first element is the key_Minheap, tang dan
    pq.push(make_pair(4, 7));
    pq.push(make_pair(10, 2));
    pq.push(make_pair(1, 100));
    pq.push(make_pair(20, 5));


    //PQ su dung array
    while (!pq.empty())
    {
        PII e = pq.top();
        pq.pop();
        cout << e.first << "," << e.second << endl;
    }

    int arr[] = {1, 2, 3};

    priority_queue<int> pq1(arr, arr + 3); // creating priority queue using array

    cout << "Max priority queue: ";
    while (pq1.empty() == false)
    {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        arr[i] = -arr[i]; // multiplying each array element by -1
    }

    priority_queue<int> pq2(arr, arr + 3);

    cout << "Min priority queue: ";
    while (pq2.empty() == false)
    {
        cout << -pq2.top() << " ";
        pq2.pop();
    }
    return 0;
}

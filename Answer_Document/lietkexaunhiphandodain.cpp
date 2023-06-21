#include <iostream>
#include<vector>

using namespace std;

// Khai bao bien toan cuc
const int MAX = 200; // So phan tu toi da cua mang la 200
int N;
int arr[MAX];

// In ket qua
void printResult(){
    for(int i=0; i<N; i++){
        cout << arr[i];
    }
    cout << endl;

    return;
}

// Quay lui
void TRY(int a){
    for(int v=0; v<=1; v++){
        arr[a-1] = v;
        if(a == N) printResult();
        else
            TRY(a+1);
    }

    return;
}
int main()
{
    cin >> N;
    TRY(1);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
        set<int> S;
        S.insert(7);
        S.insert(1);
        S.insert(9);
        S.insert(100);

        S.insert(7);
        S.insert(1);
        S.insert(9);
        S.insert(100);


        for(set<int>::iterator p = S.begin(); p != S.end(); p++){
            int v = *p;// access to the value pointed by p
            cout << v << endl;
        }

        // check if an element belongs to the set
        int v = 90;
        if(S.find(v) == S.end()){
            cout << v << " does not belong to the set S" << endl;
        }else{
            cout << v << " belongs to S" << endl;
        }

        // remove an element from s set
        v = 9;
        S.erase(v);
        cout << "after erasing " << v << endl;
        for(set<int>::iterator p = S.begin(); p != S.end(); p++){
            int v = *p;// access to the value pointed by p
            cout << v << endl;
        }
        v = 9;
        if(S.find(v) == S.end()){
            cout << v << " does not belong to the set S" << endl;
        }else{
            cout << v << " belongs to S" << endl;
        }
        return 0;
}

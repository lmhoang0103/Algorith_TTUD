#include <bits/stdc++.h>
using namespace std;
#define N 100

struct Node{// data structure of a state
    int index; // index of variable to be assigned
    int value; // value to be assigned to x[index]
    int parent; // index of parent node in the stack
    int nbChildren; // number of waiting children in the stack
    Node(int _index, int _value, int _parent, int _nbChildren){
        index = _index; parent = _parent;
        value = _value; nbChildren = _nbChildren;
    }
};

int x[N];
int n;
bool visited[N];
vector<Node> S; // used as a stack during the execution process
void solution(){
    for(int i = 1; i <= n; i++) cout << x[i] << " "; cout << endl;
}
void printStack(){
    for(int i = 0; i <= S.size()-1; i++){
        cout << "(" << S[i].index << "," << S[i].value << "," << S[i].parent << "," << S[i].nbChildren << ") ";
    }
    cout << endl;
}
void solve(){
    for(int v = 1; v <= n; v++) visited[v] = false;

    S.push_back(Node(0,0,-1,0));
    int cnt = 0;
    while(S.size() > 0){
            //cnt += 1; if(cnt > 40) break;
        int t = S.size() - 1; // index of the current node (top)
        Node e = S[t];// element on top
        x[e.index] = e.value; visited[e.value] = true;
        //cout << "consider top t = " << t << ": " << e.index << "," << e.value << "," << e.parent << "," << e.nbChildren << endl;
        if(e.index == n){// has a complete solution
            solution();
            // perform backtracking
            while(S.size() > 0 && S[S.size()-1].nbChildren == 0){
                Node e1 = S[S.size()-1]; // element on top
                int par = e1.parent;
                visited[e1.value] = false; // recover when backtracking
                if(par == -1) break;
                S[par].nbChildren -= 1;
                S.pop_back();
                //cout << "backtracking Pop: ";
                //printStack();
                if(par != S.size() - 1) break;
                if(S[S.size()-1].parent < 0){
                    S.pop_back();
                }
            }
        }else{
            for(int v = n; v >= 1; v--)if(visited[v] == false){
                S.push_back(Node(e.index+1,v,t,0));
                S[t].nbChildren += 1; // increase number of children of the parent by 1
            }
            //cout << "Push children: "; printStack();
        }
    }
}
int main(){
    n = 10;
    solve();
    return 0;
}

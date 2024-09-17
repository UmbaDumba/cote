#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct compare{
    bool operator()(vector<int> &a, vector<int> &b){
        return a[0] >= b[0];
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    priority_queue<vector<int>, vector<vector<int>>, compare> myones; // {좌표, index, 0 (L) 1 (R)}
        for(int i = 0; i<n; i++){
        int x, r;
        cin >> x >> r;
        myones.push({x-r, i, 0});
        myones.push({x+r, i, 1});
    }

    
    stack<vector<int>> mystack;

    while(!myones.empty()){
        vector<int> nowin = myones.top();
        myones.pop();
        switch(nowin[2]){
            case 0:
                mystack.push(nowin);
                break;
            case 1:
                if(mystack.empty()){
                    cout << "NO";
                    return 0;
                }
                if(mystack.top()[2] == 0 && mystack.top()[1] == nowin[1]){
                    // 가능!
                    mystack.pop();
                    continue;
                }
                cout << "NO";
                return 0;
                break;
        }
    }

    if(mystack.empty()){
        cout << "YES";
    }else{
        cout << "NO";
    }
    

    return 0;
}
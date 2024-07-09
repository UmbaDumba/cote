#include<iostream>
#include<vector>

using namespace std;

void solution1(){
    // 시간초과
    int n, m;
    vector<int> grounds;
    cin >> n;
    cin >> m;

    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        grounds.push_back(temp);
    }

    for(int i = 0; i<m; i++){
        int a, b, k;
        cin >> a;
        cin >> b;
        cin >> k;
        for(int j = a-1; j<b; j++){
            grounds[j] += k;
        }
    }

    for(int i = 0; i<n; i++){
        cout << grounds[i] <<" ";
    }
}


int main(){

    int n, m;
    vector<int> grounds;
    cin >> n;
    cin >> m;

    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        grounds.push_back(temp);
    }
    
    vector<int> changes(n, 0);

    for(int i = 0; i<m; i++){
        int a, b, k;
        cin >> a;
        cin >> b;
        cin >> k;
        changes[a-1] += k;
        if(b<n){
            changes[b] += -k;
        }
        
    }

    int sum = 0;
    for(int i = 0; i<n; i++){
        sum+=changes[i];
        cout << (grounds[i] + sum) <<" ";

    }

    return 0;
}
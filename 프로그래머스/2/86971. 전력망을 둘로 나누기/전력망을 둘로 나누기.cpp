#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;


int tree_count_sub(vector<vector<int>> wires, int n){
    
    
    // 첫번째 트리 개수 찾기
    int count1 = 1;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int node = que.front();
        que.pop();
        for(int i = 0; i<wires.size(); i++){
            if(wires[node][i] == 1){
                // 연결된곳을 찾은것
                wires[node][i] = 0;
                wires[i][node] = 0;
                que.push(i);
                count1++;
            }
        }
        
    }
    
    //cout << "1 : "<<count1<<endl;
    
    // 두번째 트리 개수 찾기
    int count2 = n - count1;
    
    
    return abs(count1 - count2);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    
    vector<vector<int>> trees(n, vector<int>(n, 0));
    
    for(int i = 0; i<wires.size(); i++){
        trees[wires[i][0]-1][wires[i][1]-1] = 1;
        trees[wires[i][1]-1][wires[i][0]-1] = 1;
    }
    
    for(int i = 0; i<wires.size(); i++){
        vector<vector<int>> test = trees;
        test[wires[i][0]-1][wires[i][1]-1] = 0;
        test[wires[i][1]-1][wires[i][0]-1] = 0;
        // 끊기
        
        answer = min(answer, tree_count_sub(test, n));
        
    }
    
    return answer;
}
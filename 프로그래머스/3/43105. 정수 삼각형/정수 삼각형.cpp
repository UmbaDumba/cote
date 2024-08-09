#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// dx (세로방향) : +1 고정 (아래로)
vector<int> dy = {-1, 0};

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    // i==0 일 때 (제일 꼭대기)는 경로까지 최대값이 자기자신인게 고정됨
    for(int i = 1; i<triangle.size(); i++){
        //cout << "i : "<<i<<endl;
        for(int j = 0; j<triangle[i].size(); j++){
            //cout << "j : "<<j<<endl;
            int num = triangle[i][j];
            for(int k = 0; k<2; k++){
                int newx = i - 1;
                int newy = j + dy[k];
                if(newy < 0 || newy >= triangle[i-1].size()){
                    continue;
                }
                
                triangle[i][j] = max(triangle[i][j], num + triangle[newx][newy]);
                //cout << triangle[i][j] << endl;
            }
        }
    }
    answer = *max_element(triangle[triangle.size()-1].begin(), triangle[triangle.size()-1].end());
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    vector<int> serves(players.size(), 0);
    
    
    serves[0] = (players[0] / m) + 1;
    answer += (serves[0]-1);
    serves[k] -= (serves[0]-1);
    
    //cout << "[0] : "<<serves[0]<<endl; 
    
    for(int i = 1; i<players.size(); i++){
        serves[i] += serves[i-1];
        if(players[i] < serves[i] * m){
            // 증설 필요없음
            
        }else{
            // 증설 필요함
            int new_serves = ((players[i] / m) + 1) - serves[i];
            serves[i] += new_serves;
            if((i+k) < players.size()){
                serves[i+k] -= new_serves; // k시간후에 사라짐
            }
            
            answer += new_serves;
            //cout << i << ", "<<new_serves<<endl;
        }
    }
    
    
    return answer;
}
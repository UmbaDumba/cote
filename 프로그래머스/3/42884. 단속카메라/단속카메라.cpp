#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

vector<int> cameras;

bool is_in(vector<int> car){
    if(cameras.empty()){
        return false;
    }
    for(int i = 0; i<cameras.size(); i++){
        if((car[0] <= cameras[i]) && (cameras[i] <= car[1])){
            return true;
        }
    }
    return false;
}


int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), comp);
    // 진출 기준 정렬
    
    
    for(int i = 0; i<routes.size(); i++){
        if(!is_in(routes[i])){
            cameras.push_back(routes[i][1]);
        }
    }
    
    answer = (int) cameras.size();
    
    return answer;
}
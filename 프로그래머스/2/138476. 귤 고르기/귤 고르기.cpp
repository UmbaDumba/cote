#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> tans; //[크기][개수];
    
    for(int i = 0; i<tangerine.size(); i++){
        if(tans.find(tangerine[i]) == tans.end()){
            tans[tangerine[i]] = 1;
        }else{
            tans[tangerine[i]]++;
        }
    }
    
    vector<pair<int, int>> counts(tans.begin(), tans.end());
    sort(counts.begin(), counts.end(), comp);
    
    int sum = 0;
    for(int i = 0; i < counts.size(); i++){
        if(sum >= k){
            break;
        }else{
            answer++;
            sum+=(counts[i].second);
        }
    }
    
    return answer;
}
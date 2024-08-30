#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

bool comp2(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

map<string, vector<pair<int, int>>> mymap;  // {index, plays}
map<string, int> totalplay;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i = 0; i<genres.size(); i++){
        mymap[genres[i]].push_back({i, plays[i]});
        if(totalplay.find(genres[i]) == totalplay.end()){
            // 없음
            totalplay[genres[i]] = plays[i];
        }else{
            totalplay[genres[i]] += plays[i];
        }
    }
    
    vector<pair<string, int>> vecplays(totalplay.begin(), totalplay.end());
    sort(vecplays.begin(), vecplays.end(), comp);
    
    for(int i = 0; i<vecplays.size(); i++){
        sort(mymap[vecplays[i].first].begin(), mymap[vecplays[i].first].end(), comp2);
        for(int j = 0; j<2; j++){
            if(j >= (int)mymap[vecplays[i].first].size()){
                break;
            }
            answer.push_back(mymap[vecplays[i].first][j].first);
        }
    }
    
    return answer;
}
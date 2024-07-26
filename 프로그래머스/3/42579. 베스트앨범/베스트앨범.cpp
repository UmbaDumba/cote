#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp1(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

void sort_value_map(vector<pair<string, int>> *maps){
    sort((*maps).begin(), (*maps).end(), comp1);
    
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> jplays;
    for(int i = 0; i<plays.size(); i++){
        if(jplays.find(genres[i]) == jplays.end()){
            jplays[genres[i]] = plays[i];
        }else{
            jplays[genres[i]] += plays[i];
        }
    }
    vector<pair<string, int>> vecplays(jplays.begin(), jplays.end());
    sort_value_map(&vecplays);
    
    for(int i = 0; i<vecplays.size(); i++){
        string nowgen = vecplays[i].first;
        vector<int> max2;
        for(int j = 0; j<plays.size(); j++){
            if(genres[j].compare(nowgen)){
                continue;
            }
            int nowplays = plays[j];
            if(max2.size() == 0){
                max2.push_back(j);
            }else if(max2.size() == 1){
                if(nowplays <= plays[max2[0]]){
                    max2.push_back(j);
                }else{
                    int temp = max2[0];
                    max2[0] = j;
                    max2.push_back(temp);
                }
            }else{
                int maxn1 = max2[0];
                int maxn2 = max2[1];
                if(nowplays <= plays[maxn2]){
                    continue;
                }else if(nowplays <= plays[maxn1]){
                    max2[1] = j;
                    continue;
                }else{
                    max2[0] = j;
                    max2[1] = maxn1;
                }
            }
            
        }
        if(max2.size() == 2){
            answer.push_back(max2[0]);
            answer.push_back(max2[1]);
        }else{
            answer.push_back(max2[0]);
        }
                
    }
    
    return answer;
}
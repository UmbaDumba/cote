#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<string> banned_list;
vector<vector<string>> result;


bool is_banned(string id, string ban){
    if(id.size() != ban.size()){
        return false;
    }
    for(int i = 0; i<id.size(); i++){
        if(id[i] == ban[i] || ban[i] == '*'){
            continue;
        }
        return false;
    }
    return true;
}

bool is_in(vector<string> list){
    for(int i = 0; i<result.size(); i++){
        bool isok = false;
        for(int j = 0; j<result[i].size(); j++){
            if(result[i][j].compare(list[j]) != 0){
                isok = true;
                break;
            }
        }
        if(!isok){
            return false;
        }
    }
    return true;
}

void printvec(vector<string> vec){
    for(int i = 0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

void dfs(int index, vector<string> user_id, vector<string> ban){
    if(index == (int)banned_list.size()){
        sort(ban.begin(), ban.end());
        if(is_in(ban)){
            
            result.push_back(ban);
        }
        
        return;
    }
    for(int i = 0; i<user_id.size(); i++){
        if(is_banned(user_id[i], banned_list[index])){
            vector<string> next_ids = user_id;
            vector<string> next_ban = ban;
            next_ban.push_back(user_id[i]);
            next_ids.erase(next_ids.begin() + i, next_ids.begin() + i+1);
            dfs(index+1, next_ids, next_ban);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    banned_list = banned_id;
    
    dfs(0, user_id, {});
    
    return (int)result.size();
}
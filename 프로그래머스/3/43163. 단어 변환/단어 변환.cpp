#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool is_change(string a, string b){
    int anothers = 0;
    for(int i = 0; i<a.size(); i++){
        if(a[i] != b[i]){
            anothers++;
        }
        if(anothers>1){
            return false;
        }
    }
    return true;
}

void dfs(vector<string> words, vector<int> masking, string text, string target, int count, int* result){
    if(target.compare(text) == 0){
        // 같음
        (*result) = min((*result), count);
        return;
    }
    
    for(int i = 0; i<words.size(); i++){
        if(masking[i] == 0 && is_change(text, words[i])){
            vector<int> nextmask = masking;
            nextmask[i] = 1;
            dfs(words, nextmask, words[i], target, count+1, result);
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = INT_MAX;
    vector<int> masking((int)words.size(), 0);
    dfs(words, masking, begin, target, 0, &answer);
    
    if(answer == INT_MAX){
        answer = 0;
    }
    
    return answer;
}
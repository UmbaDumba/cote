#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {

    
    unordered_set<string> used;
    
    
    used.insert(words[0]);
    for(int i = 1; i<words.size(); i++){
        
        // 탈락조건1 : 마지막문자로 시작하는 단어가 아님
        if(words[i][0] != words[i-1][words[i-1].size()-1]){
            return {(i%n)+1, i/n + 1};
        }
        
        // 탈락조건2 : 말했던단어또말하기
        if(used.find(words[i]) != used.end()){
            return {(i%n)+1, i/n + 1};
        }
        
        used.insert(words[i]);
        
        // 탈락조건3 : 한글자
        if(words[i].size() == 1){
            return {(i%n)+1, i/n + 1};
        }
    }

    return {0,0};
}
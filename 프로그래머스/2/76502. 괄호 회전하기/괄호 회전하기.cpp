#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;

unordered_map<char, char> maps = {{'(', ')'}, {'{', '}'}, {'[', ']'}};



bool is_ok(string s){
    stack<char> mystack;
    for(int i = 0; i<s.size(); i++){
        if((s[i] == '(') || (s[i] == '{') || (s[i] == '[')){
            mystack.push(s[i]);
        }else if(mystack.empty()){
            return false;
        }else{
            char now = mystack.top();
            if(maps[now] == s[i]){
                mystack.pop();
            }else{
                return false;
            }
        }
    }
    if(mystack.empty()){
        return true;
    }
    return false;
    
}

int solution(string s) {
    int answer = 0;
    int n = s.size() - 1;
    int m = s.size();
    
    for(int i = 0; i<m; i++){
        if(is_ok(s)){
            answer++;
        }
        string ss = s.substr(1, n);
        ss.push_back(s[0]);
        s = ss;
    }
    
    
    return answer;
}
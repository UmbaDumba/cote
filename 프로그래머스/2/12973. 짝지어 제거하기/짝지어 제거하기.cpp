#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    stack<char> strings;
    
    for(int i = 0; i<s.size(); i++){
        if(strings.empty()){
            strings.push(s[i]);
            continue;
        }
        
        if(strings.top() == s[i]){
            strings.pop();
        }else{
            strings.push(s[i]);
        }
    }
    
    if(strings.empty()){
        answer = 1;
    }
    

    return answer;
}
#include<string>
#include <iostream>
#include <stack>


using namespace std;

bool solution(string s)
{
    bool answer = false;
    
    stack<char> stack;
    
    for(int i = 0; i < (s.length()); i++){
        if(s[i] == ')'){
            if(stack.empty()){
                return false;
            }
            if((stack.top()) == '('){
                stack.pop();
            }else{
                stack.push(s[i]);
            }
        }else{
            stack.push(s[i]);
        }
        
    }
    
    if(stack.empty()){
        answer = true;
    }

    

    return answer;
}
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <numeric>

using namespace std;

int value(string str){

    // () || [] 일 때
    if((int)str.size() == 2){
        if(str[0] == '(' && str[1] == ')'){
            return 2;
        }else if(str[0] == '[' && str[1] == ']'){
            return 3;
        }else{
            return 0;
        }
    }else if((int)str.size() < 2){
        return 0;
    }

    stack<char> mystack;

    vector<int> answers;
    mystack.push(str[0]);
    int start = 0;
    
    for(int i = 1; i<str.size(); i++){
        if(mystack.empty()){
            int this_value = value(str.substr(start, (i - start)));
            if(this_value == 0){
                return 0;
            }
            answers.push_back(this_value);
            start = i;
        }
        
        switch(str[i]){
            case '(':
                mystack.push(str[i]);
                break;
            case '[':
                mystack.push(str[i]);
                break;
            case ')':
                if(!mystack.empty() && mystack.top() == '('){
                    // 정상적으로 짝지어짐
                    mystack.pop();
                }else{
                    // 이상한 문자열인것!
                    return 0;
                }
                break;
            case ']':
                if(!mystack.empty() && mystack.top() == '['){
                    // 정상적으로 짝지어짐
                    mystack.pop();
                }else{
                    // 이상한 문자열인것!
                    return 0;
                }
                break;
        }
    }

    if(!mystack.empty()){
        return 0;
    }

    // str이 ( ~~~~ ) || [ ~~~~~] 모양일 때! => 겉에걸 빼고, 안쪽만 다시 넣어보기
    if(answers.empty()){
        if(!mystack.empty()){
            return 0;
        }
        if(str[0] == '('){
            int answer = 2 * value(str.substr(1, (int)str.size()-2));
            return answer;
        }else if(str[0] == '['){
            int answer = 3 * value(str.substr(1, (int)str.size()-2));
            return answer;
        }
    }else{
        if(mystack.empty()){
            int this_value = value(str.substr(start, (str.size() - start)));
            if(this_value == 0){
                return 0;
            }
            answers.push_back(this_value);
        }
    }

    int answer = accumulate(answers.begin(), answers.end(), 0);
    return answer;
}

int main(){

    string str;
    cin >> str;

    cout << value(str);

    return 0;
}
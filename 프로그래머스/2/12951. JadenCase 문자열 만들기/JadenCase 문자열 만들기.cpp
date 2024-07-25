#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer;
    
    bool is_space = true;
    char temp;
    
    for(int i = 0; i<s.size(); i++){
        if(s[i] == ' '){
            is_space = true;
            answer.push_back(s[i]);
            continue;
        }
        if(is_space){
            if(!isdigit(s[i])){
                if(s[i] >= 97 && s[i] <= 122){
                    // 대문자로 바꾸기
                    s[i] -= 32;
                }
            }
        }else{
            if(s[i] >= 65 && s[i] <= 90){
                // 소문자로 바꾸기
                s[i] += 32;
            }
        }
        is_space = false;
        answer.push_back(s[i]);
    }
    
    
    
    return answer;
}
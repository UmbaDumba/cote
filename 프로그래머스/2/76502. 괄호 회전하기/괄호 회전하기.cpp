#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = s.size();
    
    for(int i = 0; i<n; i++){
        stack<char> st; 
        for(int j = 0; j<n; j++){
            char tmp = s[(i+j) % n];
            char stop = st.top();
            
            switch(tmp){
                case ')': if(stop == '(') st.pop();
                    else st.push(tmp);
                    break;
                case ']': if(stop == '[') st.pop();
                    else st.push(tmp);
                    break;
                case '}': if(stop == '{') st.pop();
                    else st.push(tmp);
                    break;
                default: st.push(tmp);
            }
        }
        
        if(st.size() == 0) answer++;
    }
    
    
    return answer;
}
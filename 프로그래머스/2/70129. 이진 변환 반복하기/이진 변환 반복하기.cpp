#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int counts = 0; // 변환횟수
    int zeros = 0;  // 제거된 0의 개수
    
    while(true)
    {
        if(s == "1")
        {
            break;
        }
        
        counts++;
        
        // 0제거
        int ones = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == '0'){
                zeros++;
            }else{
                ones++;
            }
        }
        
        // 1 개수만큼을 2진수로 변환하여 string s에 저장
        string tmp;
        while(true)
        {
            if(ones == 0)
            {
                break;
            }
            
            if(ones % 2 == 0)
            {
                tmp.push_back('0');
            }else{
                tmp.push_back('1');
            }
            
            ones /= 2;
        }
        
        s = tmp;
    }
    
    return {counts, zeros};
}
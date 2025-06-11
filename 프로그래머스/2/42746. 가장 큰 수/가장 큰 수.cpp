#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool mycom(string a, string b)
{
    string ab = a + b;
    string ba = b + a;
    
    //cout << "ab : " << ab << " ba : "<<ba<<endl;
    
    if( (ab) > (ba) ){
        return true;
    }else{
        return false;
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string>strnums;
    for(int i = 0; i<numbers.size(); i++)
    {
        char tmp[5];
        sprintf(tmp, "%d", numbers[i]);
        
        string tmp2 = tmp;
        strnums.push_back(tmp2);
    }
    
    sort(strnums.begin(), strnums.end(), mycom);
    //sort(strnums.begin(), strnums.end(), greater<>());
    
    for(int i = 0; i<strnums.size(); i++)
    {
        answer += strnums[i];
    }
    
    if(answer[0] == '0')
    {
        return "0";
    }
    
    return answer;
}
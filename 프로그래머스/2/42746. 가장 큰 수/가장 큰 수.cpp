#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(string a, string b){
    if((a + b) > (b + a)){
        return true;
    }else{
        return false;
    }
    
    
}



string solution(vector<int> numbers) {
    string answer = "";
    vector<string> snums;
    
    for(int i = 0; i<numbers.size(); i++){
        snums.push_back(to_string(numbers[i]));
    }
    
    sort(snums.begin(), snums.end(), comp);
    
    //cout << ("30" > "3") << endl;
    
    if(!snums[0].compare("0")){
        return "0";
    }
    
    for(int i = 0; i<snums.size(); i++){
        answer += snums[i];
    }
    
    
    return answer;
}
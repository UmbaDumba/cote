#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> comps;
    
    for(int i = 0; i<completion.size(); i++)
    {
        if(comps.find(completion[i]) == comps.end())
        {
            comps[completion[i]] = 1;
        }else{
            comps[completion[i]]++;
        }
        
    }
    
    for(int i = 0; i<participant.size(); i++)
    {
        if(comps.find(participant[i]) == comps.end())
        {
            answer = participant[i];
            break;
        }
        
        comps[participant[i]]--;
        
        if(comps[participant[i]] < 0)
        {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}
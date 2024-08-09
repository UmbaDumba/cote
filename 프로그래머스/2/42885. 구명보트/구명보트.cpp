#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int j = people.size()-1; // j : 무거운사람
    int n = people.size();
    for(int i = 0; i<n; i++){ // i : 가벼운사람
        if(j < i){
            break;
        }
        if(people[j] + people[i] <= limit){
            // 같이 탈출 가능
            answer++;
            j--;
            continue;
        }
        // 무거운사람 혼자가야함
        answer++;
        j--;
        i--;
        continue;
        
    }
    
    return answer;
}
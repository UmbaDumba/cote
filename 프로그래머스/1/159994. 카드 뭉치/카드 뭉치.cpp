#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int n1 = cards1.size();
    int n2 = cards2.size();
    
    int i1 = 0;
    int i2 = 0;
    for(int i = 0; i<goal.size(); i++){
        if(i1 < n1 &&(!cards1[i1].compare(goal[i]))){
            i1++;
            continue;
        }
        if(i2 < n2 && (!cards2[i2].compare(goal[i]))){
            i2++;
            continue;
        }
        return "No";
    }
    
    return "Yes";
}
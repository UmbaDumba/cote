#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> tops;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        tops.push_back(temp);
    }

    vector<int> answer;
    answer.push_back(-1);
    for(int i = 1; i<n; i++){
        if(tops[i] <= tops[i-1]){
            answer.push_back(i-1);
            continue;
        }else if(answer[i-1] == -1){
            answer.push_back(-1);
            continue;
        }
        int next_index = answer[i-1];
        while(true){
            if(tops[next_index] >= tops[i]){
                answer.push_back(next_index);
                break;
            }else if(answer[next_index] == -1){
                answer.push_back(-1);
                break;
            }else{
                next_index = answer[next_index];
            }
        }
    }

    for(int i = 0; i<n; i++){
        cout << answer[i] + 1<<" ";
    }

    return 0;
}
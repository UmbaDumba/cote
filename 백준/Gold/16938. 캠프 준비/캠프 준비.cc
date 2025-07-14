#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int n, l, r, x;
int answer = 0;
vector<int> problems;

// problems
vector<int> selectes;


void sol(){
    // 지금 selectes상태로 괜찮으면 answer 증가
    if(selectes.size() < 2) return;


    
    // 문제 난이도 합이 L보다크거나 같고 R보다 작거나 같음
    int sum = accumulate(selectes.begin(), selectes.end(), 0);
    if( sum < l || sum > r){
        return;
    }

    // 최소난이도랑 최대난이도의 차이가 x보다 크거나 같음
    int cha = *max_element(selectes.begin(), selectes.end()) - *min_element(selectes.begin(), selectes.end());
    if(cha < x) return;

    answer++;



}

void dfs(int i){



    if(i == n){
        sol();
        return;
    }


    // 지금 문제 추가 안함
    dfs(i+1);

    // 문제 추가
    selectes.push_back(problems[i]);
    dfs(i+1);
    selectes.pop_back();



}


int main(){

    cin >> n >> l >> r >> x;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        problems.push_back(tmp);
    }

    dfs(0);

    cout << answer;


    return 0;
}
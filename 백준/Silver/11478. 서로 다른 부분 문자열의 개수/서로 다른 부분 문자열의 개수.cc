#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> get_subset2(string text){
    // s보다 길이가 1 작은 subset을 리턴, 중복제거
    // => 무조건 2개만 나옴!
    vector<string> result;
    int size = (int)text.size();
    
    string left = text.substr(0, size-1);
    string right = text.substr(1, size-1);
    result.push_back(left);
    if(left.compare(right) == -1){
        // 다름
        result.push_back(right);
    }
    return result;
}

int get_subset_count(string text, int size){
    // 중복을 제거한채로 반환해주기!
    vector<string> result;
    
    for(int i = 0; i<(text.size()-size+1); i++){
        string now = text.substr(i, size);
        result.push_back(now);
    }

    // 사전순 정렬
    sort(result.begin(), result.end());

    // 중복 체크 -> 사전순으로 인접한것끼리만 비교하면 된다
    string prev = result[0];
    int result_count = 1;
    for(int i = 1; i<result.size(); i++){
        if(prev.compare(result[i]) != 0){
            // 중복이 아님
            result_count++;
            prev = result[i];
        }
    }


    return result_count;
}


int main(){

    //string text = "ababc";
    string text;
    cin>>text;
    int size = text.size();

    int answer = 1; // text그대로인 subset은 항상 포함

    for(int i = size-1; i>0; i--){
        answer += get_subset_count(text, i);
    }



    cout << answer << endl;

    return 0;
}
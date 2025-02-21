// 숫자야구??

#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> qs;
int ns;
vector<int> anss;
vector<int> test_code;
int answer = 0;

void nums(int k){
    if(k == 5){
        // 5자리 숫자가 만들어진것
        bool flag = true;
        for(int i = 0; i<qs.size(); i++){
            // 내가 만든 조합이랑 주어진 조합이랑 몇개가 맞는지 비교
            int temps = 0;
            int point1 = 0;
            int point2 = 0;
            while(point1 < 5 && point2 < 5){
                if(test_code[point1] == qs[i][point2]){
                    temps++;
                    point1++;
                    point2++;
                }else if(test_code[point1] > qs[i][point2]){
                    point2++;
                }else{
                    point1++;
                }
            }
            if(temps != anss[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            answer++;
        }
        return;
    }
    
    
    for(int i = test_code[k-1]+1; i<=ns; i++){
        test_code.push_back(i);
        nums(k+1);
        test_code.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    
    ns = n;
    qs = q;
    anss = ans;
    
    for(int i = 1; i<=n; i++){
        test_code.push_back(i);
        nums(1);
        test_code.pop_back();
    }
    
    return answer;
}
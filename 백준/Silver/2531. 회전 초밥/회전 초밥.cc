#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;



int main(){

    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> sushis(n);

    for(int i = 0; i<n; i++){
        cin >> sushis[i];
    }

    int left = 0;
    int right = 0;
    // left ~ right 가짓수 (right 포함 안하구)
    unordered_map<int, int> case_count;
    bool is_coupon = false;
    int result = 0;
    int cases = 0;


    for(right=0; right<k; right++){
        if(sushis[right] == c){
            is_coupon = true;
        }

        if(case_count.find(sushis[right]) == case_count.end()){
            case_count[sushis[right]] = 1;
            cases++;
        }else {
            case_count[sushis[right]]++;
        }
    }

    result = max(result, cases);
    if(right >= n) right = 0;

    if(!is_coupon){ // 지금 윈도우에 쿠폰이 없으면 하나 추가요청이 가능하다는것같음
        result++;
    }else{
        // 쿠폰이 있으면 앞뒤로 추가해보기
        if(left != right){
            int testleft = (left-1) < 0 ? n-1 : left-1;
            int testright = (right) >= n ? 0 : right ;
            if( (sushis[testleft] == c)
                && (case_count.find(sushis[testleft]) == case_count.end() || case_count[sushis[testleft]] == 0)
            ){
                    result++;
            }else if((sushis[testright] == c)
                && (case_count.find(sushis[testright]) == case_count.end() || case_count[sushis[testright]] == 0
            )){
                
                result++;
            }
        }
    }


    while(left < n){
        //cout << "left : " << left << ", right : "<<right<<", cases :" <<cases << ", result : "<<result << ", in_coupon : "<<is_coupon<< endl;
        // left 빼기
        case_count[sushis[left]]--;
        if(case_count[sushis[left]] == 0){
            cases--;
            if(sushis[left] == c){
                is_coupon = false;
            }
        }   
        left++;

        // right 추가하기
        if(sushis[right] == c){
            is_coupon = true;
        }
        
        if(case_count.find(sushis[right]) == case_count.end()
            || case_count[sushis[right]] == 0){
            case_count[sushis[right]] = 1;
            cases++;
        }else {
            case_count[sushis[right]]++;
        }

        right++;

        if(right >= n) right = 0;

        // 종류 세기
        int tmp = cases;

        // 쿠폰이 있으면 앞뒤로 추가해보기
        if(!is_coupon){
            tmp++;
        }else{
            if(left != right){
                int testleft = (left-1) < 0 ? n-1 : left-1;
                int testright = (right) >= n ? 0 : right;
                if((sushis[testleft] == c)
                    && (case_count.find(sushis[testleft]) == case_count.end() || case_count[sushis[testleft]] == 0)
                ){
                        tmp++;
                }else if((sushis[testright] == c)
                    && (case_count.find(sushis[testright]) == case_count.end() || case_count[sushis[testright]] == 0
                )){
                    
                    tmp++;
                }
            }
        }
        
        

        result = max(result, tmp);

        

    }

    //if(!is_coupon) result++;
    
    cout << result;

    return 0;
}